#pragma once
#include "first.h"
#include "FieldNodeBlueprint.h"
#include "Bloc.h"
#include "BlocStatic.h"
#include "Array.h"

namespace kar {

	class FieldNode
	{
		static const int maxNumberOfSons = 5;
		using Sons = Array<FieldNode*, maxNumberOfSons>;
		using CumulatedFollowers = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using Neighbors = Bloc<char>;

		FieldNode * father = nullptr;
		Sons sons;

		// garbageDirectFollower :
		// * {-2} : no followers.
		// * {-1} : at least one follower, but no follower has been added on this node when it was set.
		// * [0 ; NUMBER_OF_PLAYERS[ : only one follower, which has been added on this node when it was set, and specify the owner of the follower.
		int garbageDirectFollower = -2;

		CumulatedFollowers cumulatedFollowers = { 0 };

		Neighbors neighborCities{ 0, nullptr };

	public:
		// nécessaire pour l'allocation statique
		FieldNode() = default;

		~FieldNode() = default;

		void reset();

		bool hasFather() const { return father != nullptr; }
		FieldNode & getRoot() { return father != nullptr ? father->getRoot() : *this; }
		const FieldNode & getRoot() const { return father != nullptr ? father->getRoot() : *this; }
		int getDepth() const { return father != nullptr ? 1 + father->getDepth() : 0; }

		// son has no father !
		void becomeFatherOf(FieldNode * son);
		// supposed to be called just before throw it away
		void unlinkChildren();

		const Sons & getChildren() const { return sons; }

		// return true if a follower is associated with this node
		// hasDirectFollower() => hasAnyFollower()
		// hasDirectFollower() => getDirectFollower() is defined
		// hasDirectFollower() => getCumulatedFollower(getDirectFollower()) = 1 && {V i != getDirectFollower(), getCumulatedFollower(i) = 0}
		bool hasDirectFollower() const { return garbageDirectFollower > -1; }

		// hasAnyFollower() => {E i, getCumulatedFollower(i) > 0}
		bool hasAnyFollower() const { return garbageDirectFollower > -2; }

		// hasDirectFollower() must be true
		// return integer between 0 and NUMBER_OF_PLAYER-1
		int getDirectFollower() const { return garbageDirectFollower; }

		// hasDirectFollower() must be false before
		// indexPlayer between 0 and NUMBER_OF_PLAYER -1
		// hasDirectFollower() become true after
		void setDirectFollower(int indexPlayer) {
			garbageDirectFollower = indexPlayer;
			cumulatedFollowers[indexPlayer] = 1;
		}

		// hasDirectFollower() must be true before
		// hasDirectFollower() become false after
		// hasAnyFollower() become false after
		void setNoDirectFollower() {
			cumulatedFollowers[garbageDirectFollower] = 0;
			garbageDirectFollower = -2;
		}

		int getMaxFollower() const { return cumulatedFollowers.max(); }
		int getCumulatedFollower(int index) const { return cumulatedFollowers[index]; }

		bool canSetFarmer() const { return !hasFather() && garbageDirectFollower != -1; }

		const Neighbors & getNeighborCities() const { return neighborCities; }
		void setNeighborCities(const Neighbors & b) { neighborCities = b; }

	};

}


