#pragma once
#include <vector>
#include "first.h"
#include "BlocStatic.h"
#include "Bloc.h"
#include "CityCoreData.h"
#include "CityNodeBlueprint.h"

namespace kar {
	class City
	{
	public:
		using CoreData = CityCoreData;
		using Index = signed char;
		using Sons = std::vector<Index>;
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using Neighbors = Bloc<char>;
		using AmbigiousPositions = std::vector<char>;

	private:
		Index father = -1;
		Sons sons;

		// garbageDirectFollower :
		// * {-2} : no followers.
		// * {-1} : at least one follower, but no follower has been added on this node when it was set.
		// * [0 ; NUMBER_OF_PLAYERS[ : only one follower, which has been added on this node when it was set, and specify the owner of the follower.
		int garbageFollower = -2;
		
		AmbigiousPositions ambigiousPositions;
		Neighbors neighborFields = { 0, nullptr };

		CoreData core;
		
	public:
		City() = default;
		~City() = default;

		void reset(char nbHoles, bool _crest);
		void reset(char nbHoles, bool _crest, char ambigiousPosition);
		void becomeFatherOf(City& ndSon, const Index idxFather, const Index idxSon);

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
		bool isNotWorth() const { return hasFather() || isCompleted(); }

		const Neighbors & getNeighborFields() { return neighborFields; }
		void setNeighborFields(const Neighbors & b) { neighborFields = b; }
	};

	inline void City::reset(char nbHoles, bool _crest) {
		father = -1;
		sons.clear();
		garbageFollower = -2;
		core.followers.reset(0);
		core.coveredArea = 1;
		core.holes = nbHoles;
		core.crest = _crest;
		ambigiousPositions.clear();
	}

	inline void City::reset(char nbHoles, bool _crest, char ambigiousPosition) {
		reset(nbHoles, _crest);
		ambigiousPositions.push_back(ambigiousPosition);
	}

}
