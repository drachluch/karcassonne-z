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

		// garbageDirectFollower :
		// * {-2} : no followers.
		// * {-1} : at least one follower, but no follower has been added on this node when it was set.
		// * [0 ; NUMBER_OF_PLAYERS[ : only one follower, which has been added on this node when it was set, and specify the owner of the follower.
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
		bool isCompleted() const { return core.holes == 0; }

		bool hasAnyFollower() const { return garbageFollower > -2; }
		bool hasDirectFollower() const { return garbageFollower > -1; }
		int getDirectFollower() const { return garbageFollower; }
		void setDirectFollower(signed char idxPlayer) { garbageFollower = idxPlayer; core.followers[idxPlayer] = 1; }
		void setNoDirectFollower() { core.followers[garbageFollower] = 0; garbageFollower = -2; }

		bool canSetFollower() const { return !hasFather() && garbageFollower != -1; }
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

}
