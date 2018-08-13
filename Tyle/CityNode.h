#pragma once
#include "first.h"
#include "CityNodeBlueprint.h"
#include "BlocStatic.h"
#include "Bloc.h"
#include "Array.h"

namespace kar {



	class CityNode
	{
		static const int maxNumberOfSons = 4;
		using Sons = Array<CityNode*, maxNumberOfSons>;
		using CumulatedFollowers = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using Neighbors = Bloc<char>;
		using AmbigiousPositions = Array<int, MAX_AMBIGIOUS_POSITIONS_FOR_CITYNODE>;

		CityNode * father = nullptr;
		Sons sons;

		// garbageDirectFollower :
		// * {-2} : no followers.
		// * {-1} : at least one follower, but no follower has been added on this node when it was set.
		// * [0 ; NUMBER_OF_PLAYERS[ : only one follower, which has been added on this node when it was set, and specify the owner of the follower.
		int garbageDirectFollower = -2;

		CumulatedFollowers cumulatedFollowers = { 0 };

		int coveredTiles = 1;
		int holes = 0;

		int crest = 1;

		AmbigiousPositions ambigiousPositions;

		Neighbors neighborFields = { 0, nullptr };

	public:
		// nécessaire pour l'allocation statique
		CityNode() = default;

		~CityNode() = default;

		// défini le nombre de trous et la présence d'un blason
		void reset(const CityNodeBlueprint & cnb);

		// défini le nombre de trous et le fait que la position du noeud est ambigue.
		void reset(const CityNodeBlueprint & cnb, int idxTile);

		bool hasFather() const { return father != nullptr; }
		CityNode & getRoot() { return father != nullptr ? father->getRoot() : *this; }
		const CityNode & getRoot() const { return father != nullptr ? father->getRoot() : *this; }
		int getDepth() const { return father != nullptr ? 1 + father->getDepth() : 0; }

		// son has no father !
		void becomeFatherOf(CityNode * son);
		// supposed to be called just before throw it away
		void unlinkChildren();

		const Array<CityNode*, maxNumberOfSons> & getChildren() const { return sons; }

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
		int score() const { return isCompleted() ? 2 * (coveredTiles + crest) : coveredTiles + crest; }

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

		int getNumberOfAmbigiousPositions() const { return ambigiousPositions.length(); }
		int getAmbigiousPosition(int i) const { return ambigiousPositions[i]; }

		int getMaxFollower() const { return cumulatedFollowers.max(); }

		int getCumulatedFollower(int index) const { return cumulatedFollowers[index]; }
		bool canSetKnight() const { return !hasFather() && garbageDirectFollower != -1; }

		const Neighbors & getNeighborFields() { return neighborFields; }
		void setNeighborFields(const Neighbors & b) { neighborFields = b; }
	};


	// sort the content of the already sorted arrays src1 and src2, and write the sorted result into dest.
	// dest can't have its size longer than L, and if the sorted result is longer, it's truncated.
	// return nothing
	template <typename T, int L>
	void fusion_sort(Array<T, L> & dest, const Array<T, L> & src1, const Array<T, L> & src2) {
		int i1 = 0, i2 = 0;
		for (; dest.length() < L && i1 < src1.length() && i2 < src2.length();) {
			if (src1[i1] < src2[i2]) {
				dest.push(src1[i1]);
				i1++;
			}
			else {
				if (src1[i1] > src2[i2]) {
					dest.push(src2[i2]);
					i2++;
				}
				else {
					dest.push(src1[i1]);
					i1++;
					i2++;
				}
			}
		}

		for (; dest.length() < L && i1 < src1.length(); i1++)
			dest.push(src1[i1]);
		for (; dest.length() < L && i2 < src2.length(); i2++)
			dest.push(src2[i2]);
	}


	// la taille de scores et followers est NUMBER_OF_PLAYERS
	// fonction appelée lorsque le noeud est complété, pour attribuer les points et libérer les partisans.
	// {cn.isCompleted() && cn.hasAnyFollower()}
	inline void updateForCompleted(const CityNode & cn, int * scores, int * followers) {
		// les points sont à attribuer et les partisans à libérer

		auto maxF = cn.getMaxFollower();
		auto score = cn.score();

		for (auto idxPlayer = 0; idxPlayer < NUMBER_OF_PLAYERS; idxPlayer++) {
			// si le joueur est propriétaire
			if (cn.getCumulatedFollower(idxPlayer) == maxF)
				scores[idxPlayer] += score;
			// retour des partisans sur le plateau
			followers[idxPlayer] += cn.getCumulatedFollower(idxPlayer);
		}

	}


	// la taille de scores et followers est NUMBER_OF_PLAYERS
	// fonction appelée lorsqu'il faut annuler les conséquences de la completion du noeud, ie pour attribuer les points et libérer les partisans.
	// {cn.isCompleted() && cn.hasAnyFollower()}
	inline void cancelUpdateForCompleted(const CityNode & cn, int * scores, int * followers) {
		// les points sont à retirer et les partisans à remettre sur le plateau

		auto maxF = cn.getMaxFollower();
		auto score = cn.score();

		for (auto idxPlayer = 0; idxPlayer < NUMBER_OF_PLAYERS; idxPlayer++) {
			// si le joueur est propriétaire
			if (cn.getCumulatedFollower(idxPlayer) == maxF)
				scores[idxPlayer] -= score;
			// retour des partisans sur le plateau
			followers[idxPlayer] -= cn.getCumulatedFollower(idxPlayer);
		}
	}

}


