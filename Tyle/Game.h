#pragma once
#include <random>
#include "first.h"
#include "Position.h"
#include "TileBlueprint.h"
#include "Cloister.h"
#include "Tile.h"
#include "Log.h"
#include "Array.h"

#include "RoadNode.h"
#include "CityNode.h"
#include "FieldNode.h"

#include "NeighborStack.h"

namespace kar {


	class Game
	{

		using IndexBlueprint = int;

		std::default_random_engine random_engine;

		static const TileBlueprint blueprints[NUMBER_OF_DISTINCT_TILES];
		int inventory[NUMBER_OF_DISTINCT_TILES];
		int remainingTiles = NUMBER_OF_TILES;

		Array<DiscardedBlueprintLog, NUMBER_OF_TILES + 1> discardedBlueprintLogs;
		Array<IndexBlueprint, NUMBER_OF_TILES> discardedBlueprintStorage;

		Array<Tile, NUMBER_OF_TILES> tiles;
		Array<Position, NUMBER_OF_TILES> positions;
		Array<FollowerLog, NUMBER_OF_TILES> followerLogs;

		Array<RoadNode, NUMBER_OF_ROADNODES> roadnodes;
		Array<CityNode, NUMBER_OF_CITYNODES> citynodes;
		Array<FieldNode, NUMBER_OF_FIELDNODES> fieldnodes;

		NeighborStack<char, MAX_NUMBER_INDEX_NEIGHBOR_CITIES> neighborCities;
		NeighborStack<char, MAX_NUMBER_INDEX_NEIGHBOR_FIELDS> neighborFields;

		Array<Position, 2 * NUMBER_OF_TILES + 2> reachablePositions;
		Array<ReachablePositionLog, NUMBER_OF_TILES> reachableLogs;

		Array<Cloister, NUMBER_OF_CLOISTERS> cloisters;

		int scores[NUMBER_OF_PLAYERS];
		int followers[NUMBER_OF_PLAYERS];

		void reachablePositions_reach(int ir);
		void reachablePositions_cancel(const Position & pCancel);

		void tiles_reach(const Position & p, IndexBlueprint indexBlueprint, const Direction & direction);
		void tiles_cancel();

		void cloisters_reach(const Position & p, bool newCloister);
		void cloisters_cancel(const Position & p, bool newCloister);

		// nbNodes > 0
		void roadnodes_reach(const Position & p, int idxTile);
		void roadnodes_cancel(int nbNodes);

		// nbNodes > 0
		void citynodes_reach(const Position & p, int idxTile);
		void citynodes_setNeighbors(int idxTile);
		void citynodes_cancel(int nbNodes);

		// nbFields > 0
		void fieldnodes_reach(const Position & p, int idxTile);
		void fieldnodes_setNeighbors(int idxTile);
		void fieldnodes_cancel(int nbNodes);

		void setThiefOnRoadnode(int indexRoadnode);
		void cancelThiefOnRoadnode(int indexRoadnode);

		void setKnightOnCitynode(int indexCitynode);
		void cancelKnightOnCitynode(int indexCitynode);

		void setFarmerOnFieldnode(int indexFieldnode);
		void cancelFarmerOnFieldnode(int indexFieldnode);

		void discardedBlueprints_reach();
		void discardedBlueprints_cancel();

		int currentPlayer = 0;

	public:
		Game();
		~Game() = default;

		IndexBlueprint nextBlueprintIndex();
		const TileBlueprint & getBlueprint(IndexBlueprint i) const {
			if (i < 0 || i >= NUMBER_OF_DISTINCT_TILES) {
				throw "TileBlueprint : out of bound";
			}
			return blueprints[i];
		}
		int getRemainingNumberBlueprint(IndexBlueprint i) const { return inventory[i]; }
		int getSumRemainingNumber() const { return remainingTiles; }
		bool hasRemainingBlueprint() const { return remainingTiles != 0; }

		void discardBlueprint(IndexBlueprint i);

		const Position & getReachablePosition(int i) const { return reachablePositions[i]; }
		const Position & getPosition(int i) const { return positions[i]; }
		const Tile & getTile(int i) const { return tiles[i]; }
		const Cloister & getCloister(int i) const { return cloisters[i]; }
		const RoadNode & getRoadNode(int i) const { return roadnodes[i]; }
		const CityNode & getCityNode(int i) const { return citynodes[i]; }
		const FieldNode & getFieldNode(int i) const { return fieldnodes[i]; }

		int getNumberReachablePositions() const { return reachablePositions.length(); }
		// getNumberPositions() == getNumberTiles()
		int getNumberPositions() const { return positions.length(); }
		// getNumberTiles() == getNumberPositions()
		int getNumberTiles() const { return tiles.length(); }
		int getNumberCloisters() const { return cloisters.length(); }
		int getNumberRoadNodes() const { return roadnodes.length(); }
		int getNumberCityNodes() const { return citynodes.length(); }
		int getNumberFieldNodes() const { return fieldnodes.length(); }

		const FollowerLog & getFollowerLog(int i) const { return followerLogs[i]; }


		int getIndexPosition(const Position & p) const { for (int i = 0; i < positions.length(); i++) if (positions[i] == p) return i; return -1; }

		bool isOccupied(const Position & p) const { for (int i = 0; i < positions.length(); i++) if (positions[i] == p) return true; return false; }
		bool isReachable(const Position & p) const { for (int i = 0; i < reachablePositions.length(); i++) if (reachablePositions[i] == p) return true; return false; }

		void setTile(int indexReachablePosition, IndexBlueprint indexBlueprint, const Direction & direction);

		bool canSetTile(const Position & p, const TileBlueprint & tb, const Direction & direction) const;
		bool canSetTile(int indexReachablePosition, IndexBlueprint indexBlueprint, const Direction & direction) const { return canSetTile(getReachablePosition(indexReachablePosition), getBlueprint(indexBlueprint), direction); }

		bool canSetMonk() const;
		void setMonk();
		void cancelMonk();

		int waysToSetThief() const;
		void setThief(int wayThief);
		void cancelThief(int wayThief);

		int waysToSetKnight() const;
		void setKnight(int wayKnight);
		void cancelKnight(int wayKnight);

		int waysToSetFarmer() const;
		void setFarmer(int wayFarmer);
		void cancelFarmer(int wayFarmer);

		int getCurrentPlayer() const { return currentPlayer; }
		void nextPlayer() { currentPlayer = (currentPlayer + 1) % NUMBER_OF_PLAYERS; }
		void previousPlayer() { currentPlayer = (currentPlayer + NUMBER_OF_PLAYERS - 1) % NUMBER_OF_PLAYERS; }
		int getNumberOfPlayers() const { return NUMBER_OF_PLAYERS; }

		bool hasIdleFollower(int p) const { return followers[p] > 0; }
		bool hasIdleFollower() const { return hasIdleFollower(getCurrentPlayer()); }

		int getScore(int i) const { return scores[i]; }

		void cancel();

		void end();

	};



	void setNeighborFields(CityNode & cn, const CityNodeBlueprint & cnb, const Array<FieldNode, NUMBER_OF_FIELDNODES> & fieldnodes, int firstField, NeighborStack<char, MAX_NUMBER_INDEX_NEIGHBOR_FIELDS> & neighborFields);
	void setNeighborCities(FieldNode & fn, const FieldNodeBlueprint & fnb, const Array<CityNode, NUMBER_OF_CITYNODES> & citynodes, int firstCity, NeighborStack<char, MAX_NUMBER_INDEX_NEIGHBOR_CITIES> & neighborCities);

}
