#pragma once
#include "first.h"
#include "RoadNodeBlueprint.h"
#include <algorithm>

class RoadNode
{
	RoadNode * father = nullptr;
	int numberOfSons = 0;
	RoadNode * sons[3] = { nullptr, nullptr, nullptr };

	// garbageDirectFollower :
	// * {-2} : no followers.
	// * {-1} : at least one follower, but no follower has been added on this node when it was set.
	// * [0 ; NUMBER_OF_PLAYERS[ : only one follower, which has been added on this node when it was set, and specify the owner of the follower.
	int garbageDirectFollower = -2;

	int cumulatedFollowers[NUMBER_OF_PLAYERS];

	int coveredTiles = 1;
	int holes = 0;

	// garbageAmbigiousPosition :
	// * {-1} : no ambigious position
	// * N : one ambigious position, and specify the index of the ambigious position
	// If a road node has two ambigious position, then it is completed (holes = 0).
	int ambigiousPosition = -1;

public:
	// nécessaire pour l'allocation statique
	RoadNode() = default;
	
	// défini le nombre de trous
	RoadNode(const RoadNodeBlueprint & rnb);

	// défini le nombre de trous et le fait que la position du noeud est ambigue.
	RoadNode(const RoadNodeBlueprint & rnb, int idxTile);
	
	~RoadNode() = default;

	RoadNode & operator=(const RoadNode &rn);
	
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

	int getMaxFollower() const {
		int maxF = cumulatedFollowers[0];
		for (int i = 1; i < NUMBER_OF_PLAYERS; i++)
			if (cumulatedFollowers[i] > maxF)
				maxF = cumulatedFollowers[i];
		return maxF;
	}

	int getCumulatedFollower(int index) const { return cumulatedFollowers[index]; }
	bool canSetThief() const { return !hasFather() && garbageDirectFollower != -1; }


};


// la taille de scores et followers est NUMBER_OF_PLAYERS
// fonction appelée lorsque le noeud est complété, pour attribuer les points et libérer les partisans.
// {rn.isCompleted() && rn.hasAnyFollower()}
inline void updateForCompleted(const RoadNode & rn, int * scores, int * followers) {
	// les points sont à attribuer et les partisans à libérer

	int maxF = rn.getMaxFollower();
	int score = rn.score();

	for (int idxPlayer = 0; idxPlayer < NUMBER_OF_PLAYERS; idxPlayer++) {
		// si le joueur est propriétaire
		if (rn.getCumulatedFollower(idxPlayer) == maxF)
			scores[idxPlayer] += score;
		// retour des partisans sur le plateau
		followers[idxPlayer] += rn.getCumulatedFollower(idxPlayer);
	}

}


// la taille de scores et followers est NUMBER_OF_PLAYERS
// fonction appelée lorsqu'il faut annuler les conséquences de la completion du noeud, ie pour attribuer les points et libérer les partisans.
// {rn.isCompleted() && rn.hasAnyFollower()}
inline void cancelUpdateForCompleted(const RoadNode & rn, int * scores, int * followers) {
	// les points sont à retirer et les partisans à remettre sur le plateau

	int maxF = rn.getMaxFollower();
	int score = rn.score();

	for (int idxPlayer = 0; idxPlayer < NUMBER_OF_PLAYERS; idxPlayer++) {
		// si le joueur est propriétaire
		if (rn.getCumulatedFollower(idxPlayer) == maxF)
			scores[idxPlayer] -= score;
		// retour des partisans sur le plateau
		followers[idxPlayer] -= rn.getCumulatedFollower(idxPlayer);
	}
}



