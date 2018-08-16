#pragma once
#include <vector>
#include "first.h"
#include "BlocStatic.h"
#include "FieldCoreData.h"

namespace kar {
	class Field
	{
	public:
		using Index = signed char;
		using Sons = std::vector<Index>;
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using CoreData = FieldCoreData;

	private:
		Index father = -1;
		Sons sons;

		// garbageDirectFollower :
		// * {-2} : no followers.
		// * {-1} : at least one follower, but no follower has been added on this node when it was set.
		// * [0 ; NUMBER_OF_PLAYERS[ : only one follower, which has been added on this node when it was set, and specify the owner of the follower.
		int garbageFollower = -2;

		CoreData core;

	public:
		Field() = default;
		~Field() = default;

		void reset(void);
		void becomeFatherOf(Field& ndSon, const Index idxFather, const Index idxSon);

		Index getFather() const { return father; }
		bool hasFather() const { return father != -1; }
		const Sons & getSons() const { return sons; }
		void setNoFather() { father = -1; }

		const CoreData & getCoreData() const { return core; }

		bool hasAnyFollower() const { return garbageFollower > -2; }
		bool hasDirectFollower() const { return garbageFollower > -1; }
		int getDirectFollower() const { return garbageFollower; }
		void setDirectFollower(signed char idxPlayer) { garbageFollower = idxPlayer; core.followers[idxPlayer] = 1; }
		void setNoDirectFollower() { core.followers[garbageFollower] = 0; garbageFollower = -2; }

		bool canSetFollower() const { return !hasFather() && garbageFollower != -1; }
		bool isNotWorth() const { return hasFather(); }

	};

}


