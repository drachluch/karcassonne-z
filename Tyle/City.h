#pragma once
#include <vector>
#include "first.h"
#include "CityCoreData.h"
#include "CityNodeBlueprint.h"
#include "BlocStatic.h"

#include "Followers.h"
#include "Scores.h"

namespace kar {
	class City
	{
	public:
		using CoreData = CityCoreData;
		using Index = char;
		using Sons = std::vector<Index>;
		using AmbigiousPositions = std::vector<char>;
		using NodeBlueprint = CityNodeBlueprint;

	private:
		Index father = -1;
		Sons sons;

		// garbageDirectFollower :
		// * {-2} : no followers.
		// * {-1} : at least one follower, but no follower has been added on this node when it was set.
		// * [0 ; NUMBER_OF_PLAYERS[ : only one follower, which has been added on this node when it was set, and specify the owner of the follower.
		int garbageFollower = -2;
		
		AmbigiousPositions ambigiousPositions;

		CoreData core;
		
	public:
		City() = default;
		~City() = default;

		void reset(const NodeBlueprint& nb);
		void reset(const NodeBlueprint& nb, char ambigiousPosition);
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
	};

	inline void City::reset(const NodeBlueprint& nb) {
		father = -1;
		sons.clear();
		garbageFollower = -2;
		core.reset(nb);
		ambigiousPositions.clear();
	}

	inline void City::reset(const NodeBlueprint& nb, char ambigiousPosition) {
		reset(nb);
		ambigiousPositions.push_back(ambigiousPosition);
	}

}
