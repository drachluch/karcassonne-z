#pragma once
#include "first.h"
#include "BlocStatic.h"
#include "RoadCoreData.h"
#include <vector>


namespace kar {
	
	class Road {
	public:
		using Index = signed char;
		using Sons = std::vector<Index>;
		using CoreData = RoadCoreData;
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;

	private:
		Index father = -1;
		Sons sons;

		signed char garbageFollower = -2;
		signed char ambigiousPosition = -1;

		CoreData core;


	public:
		Road() = default;
		~Road() = default;

		void reset(char h, char idxTile = -1);
		void becomeFatherOf(Road & ndSon, const Index idxFather, const Index idxSon);

		Index getFather() const { return father; }
		bool hasFather() const { return father != -1; }
		const Sons & getSons() const { return sons; }
		void setNoFather() { father = -1; }

		const CoreData & getCoreData() const { return core; }
		bool isCompleted() const { return core.isCompleted(); }

		bool hasAnyFollower() const { return garbageFollower > -2; }
		bool hasDirectFollower() const { return garbageFollower > -1; }
		int getDirectFollower() const { return garbageFollower; }
		void setDirectFollower(signed char idxPlayer) { garbageFollower = idxPlayer; core.followers[idxPlayer] = 1; }
		void setNoDirectFollower() { core.followers[garbageFollower] = 0; garbageFollower = -2; }

		bool canSetFollower() const { return !hasFather() && garbageFollower != -1; }

		// renvoie true si scores ou followers ont �t� modifi�s, false sinon.
		bool cancel(Scores & scores, Followers & followers) const;


		void noticeCompletedNode(Scores & scores, Followers & followers) const;
		void noticeDirectFollower(char idxPlayer, Scores& scores, Followers & followers);
		void unnoticeDirectFollower(Scores& scores, Followers & followers);

		void noticeUncompletedNodeAtTheEnd(Scores& scores) const;
		void unnoticeUncompletedNodeAtTheEnd(Scores& scores) const;


	};

	

	inline void Road::reset(char h, char idxTile)
	{
		father = -1;
		sons.clear();
		garbageFollower = -2;
		core.followers.reset(0);
		core.coveredArea = 1;
		core.holes = h;
		ambigiousPosition = idxTile;
	}

	inline void Road::becomeFatherOf(Road & ndSon, const Index idxFather, const Index idxSon)
	{
		sons.push_back(idxSon);
		ndSon.father = idxFather;
		
		// holes �� une fusion a eu lieu, donc deux trous ont �t� bouch�s.
		core.holes += ndSon.core.holes - 2;

		// followers
		if (ndSon.hasAnyFollower()) {
			if (garbageFollower == -2) {
				garbageFollower = -1;
				core.followers = ndSon.core.followers;
			} else
				core.followers += ndSon.core.followers;
		}

		// coveredTiles
		if (ambigiousPosition == -1) {
			core.coveredArea += ndSon.core.coveredArea;
			ambigiousPosition = ndSon.ambigiousPosition;
		} else {
			if (ndSon.ambigiousPosition != ambigiousPosition) {
				core.coveredArea += ndSon.core.coveredArea;
			} else {
				core.coveredArea += ndSon.core.coveredArea - 1;
			}
		}
	}

	inline bool Road::cancel(Scores& scores, Followers& followers) const
	{
		if (hasAnyFollower() && !hasFather()) {
			if (hasDirectFollower()) {
				if (core.isCompleted()) {
					// les points ont �t� compt�s, le partisan n'est plus sur place
					// le partisan est d�j� lib�r�, et le score est rendu normal.
					scores[getDirectFollower()] -= core.score();
				}
				else {
					// les points n'ont pas �t� compt�s, le partisan est toujours sur place
					// donc le score ne change pas, et le partisan est lib�r�.
					followers[getDirectFollower()]--;
				}
				return true;
			}
			else
				if (core.isCompleted()) {
					core.take_back_points(scores);
					core.get_back_followers(followers);
					return true;
				}
		}

		return false;
	}

	inline void Road::noticeCompletedNode(Scores& scores, Followers& followers) const {
		core.give_points(scores);
		core.free_followers(followers);
	}

	inline void Road::noticeDirectFollower(char idxPlayer, Scores& scores, Followers& followers)
	{
		setDirectFollower(idxPlayer);
		if (core.isCompleted()) {
			scores[getDirectFollower()] += core.score(); // les points sont compt�s, le partisan est plac� puis imm�diatement remis � la r�serve.
		}
		else {
			followers[getDirectFollower()]++; // les points ne sont pas compt�s, le partisan est plac�.
		}
	}

	inline void Road::unnoticeDirectFollower(Scores& scores, Followers& followers)
	{
		if (core.isCompleted()) {
			// les points ont �t� compt�s, le partisan n'est plus sur place
			// le partisan est d�j� lib�r�, et le score est rendu normal.
			scores[getDirectFollower()] -= core.score();
		}
		else {
			// les points n'ont pas �t� compt�s, le partisan est toujours sur place
			// donc le score ne change pas, et le partisan est lib�r�.
			followers[getDirectFollower()]--;
		}

		setNoDirectFollower();
	}

	inline void Road::noticeUncompletedNodeAtTheEnd(Scores& scores) const { core.give_points(scores); }
	inline void Road::unnoticeUncompletedNodeAtTheEnd(Scores& scores) const { core.take_back_points(scores); }

}
