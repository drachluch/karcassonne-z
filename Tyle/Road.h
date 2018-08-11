#pragma once
#include "Bloc.h"
#include "Array.h"


namespace kar {

	template <int nbPlayers>
	class Road {
	public:
		static const int maxNumberOfSons = 3;
		using Index = signed char;
		using Sons = Array<Index, maxNumberOfSons>;
		using Followers = BlocStatic<char, nbPlayers>;

	private:
		Index father = -1;
		signed char numberOfSons = 0;
		Sons sons;

		signed char garbageFollower = -2;
		Followers cumulatedFollowers;

		char coveredArea = 1;
		char holes = 1;
		signed char ambigiousPosition = -1;

	public:
		Road() = default;
		~Road() = default;

		void reset(char h, char idxTile = -1);
		void becomeFatherOf(Road & ndSon, const Index idxFather, const Index idxSon);

		bool hasFather() const { return father != -1; }
		const Sons & getSons() const { return sons; }
		void setNoFather() { father = -1; }

		bool isCompleted() const { return holes == 0; }
		int score() const { return coveredArea; }

		bool hasAnyFollower() const { return garbageFollower > -2; }
		bool hasDirectFollower() const { return garbageFollower > -1; }
		int getDirectFollower() const { return garbageFollower; }
		const Followers & getFollowers() const { return cumulatedFollowers; }
		void setDirectFollower(signed char idxPlayer) { garbageFollower = idxPlayer; cumulatedFollowers[idxPlayer] = 1; }
		void setNoDirectFollower() { garbageFollower = -2; }

		bool canSetFollower() const { return !hasFather() && garbageFollower != -1; }


	};

	template<int nbPlayers>
	inline void Road<nbPlayers>::reset(char h, char idxTile)
	{
		father = -1;
		sons.cleanse();
		garbageFollower = -2;
		cumulatedFollowers.reset(0);
		coveredArea = 1;
		holes = h;
		ambigiousPosition = idxTile;
	}

	template<int nbPlayers>
	inline void Road<nbPlayers>::becomeFatherOf(Road & ndSon, const Index idxFather, const Index idxSon)
	{
		sons.push(idxSon);
		ndSon.father = idxFather;
		
		// holes §§ une fusion a eu lieu, donc deux trous ont été bouchés.
		holes += ndSon.holes - 2;

		// followers
		if (ndSon.hasAnyFollower()) {
			if (garbageFollower == -2)
				garbageFollower = -1;
			cumulatedFollowers = ndSon.cumulatedFollowers;
		}

		// coveredTiles
		if (ambigiousPosition == -1) {
			coveredTiles += ndSon.coveredTiles;
			ambigiousPosition = ndSon.ambigiousPosition;
		} else {
			if (ndSon.ambigiousPosition != ambigiousPosition) {
				coveredTiles += ndSon.coveredTiles;
			} else {
				coveredTiles += ndSon.coveredTiles - 1;
			}
		}
	}

}
