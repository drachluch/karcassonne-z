#pragma once
#include "first.h"
#include "RoadNodeBlueprint.h"
#include "Bloc.h"
#include "Array.h"

namespace kar {

	class RoadNode
	{
		static const int maxNumberOfSons = 3;

		RoadNode * father = nullptr;
		Array<RoadNode*, maxNumberOfSons> sons;

		// garbageDirectFollower :
		// * {-2} : no followers.
		// * {-1} : at least one follower, but no follower has been added on this node when it was set.
		// * [0 ; NUMBER_OF_PLAYERS[ : only one follower, which has been added on this node when it was set, and specify the owner of the follower.
		int garbageDirectFollower = -2;

		BlocStatic<int, NUMBER_OF_PLAYERS> cumulatedFollowers = { 0 };

		int coveredTiles = 1;
		int holes = 0;

		// garbageAmbigiousPosition :
		// * {-1} : no ambigious position
		// * N : one ambigious position, and specify the index of the ambigious position
		// If a road node has two ambigious position, then it is completed (holes = 0).
		int ambigiousPosition = -1;

	public:
		// n�cessaire pour l'allocation statique
		RoadNode() = default;

		~RoadNode() = default;

		// d�fini le nombre de trous
		void reset(const RoadNodeBlueprint & rnb);

		// d�fini le nombre de trous et le fait que la position du noeud est ambigue.
		void reset(const RoadNodeBlueprint & rnb, int idxTile);

		bool hasFather() const { return father != nullptr; }
		RoadNode & getRoot() { return father != nullptr ? father->getRoot() : *this; }

		// son has no father !
		void becomeFatherOf(RoadNode * son);
		// supposed to be called just before throw it away
		void unlinkChildren();

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

		bool isCompleted() const { return holes == 0; }
		int score() const { return coveredTiles; }

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

		bool canSetThief() const { return !hasFather() && garbageDirectFollower != -1; }


	};


	// la taille de scores et followers est NUMBER_OF_PLAYERS
	// fonction appel�e lorsque le noeud est compl�t�, pour attribuer les points et lib�rer les partisans.
	// {rn.isCompleted() && rn.hasAnyFollower()}
	inline void updateForCompleted(const RoadNode & rn, int * scores, int * followers) {
		// les points sont � attribuer et les partisans � lib�rer

		int maxF = rn.getMaxFollower();
		int score = rn.score();

		for (int idxPlayer = 0; idxPlayer < NUMBER_OF_PLAYERS; idxPlayer++) {
			// si le joueur est propri�taire
			if (rn.getCumulatedFollower(idxPlayer) == maxF)
				scores[idxPlayer] += score;
			// retour des partisans sur le plateau
			followers[idxPlayer] += rn.getCumulatedFollower(idxPlayer);
		}

	}


	// la taille de scores et followers est NUMBER_OF_PLAYERS
	// fonction appel�e lorsqu'il faut annuler les cons�quences de la completion du noeud, ie pour attribuer les points et lib�rer les partisans.
	// {rn.isCompleted() && rn.hasAnyFollower()}
	inline void cancelUpdateForCompleted(const RoadNode & rn, int * scores, int * followers) {
		// les points sont � retirer et les partisans � remettre sur le plateau

		int maxF = rn.getMaxFollower();
		int score = rn.score();

		for (int idxPlayer = 0; idxPlayer < NUMBER_OF_PLAYERS; idxPlayer++) {
			// si le joueur est propri�taire
			if (rn.getCumulatedFollower(idxPlayer) == maxF)
				scores[idxPlayer] -= score;
			// retour des partisans sur le plateau
			followers[idxPlayer] -= rn.getCumulatedFollower(idxPlayer);
		}
	}

}

