#pragma once
#include <random>
#include "first.h"
#include "Position.h"
#include "TileBlueprint.h"
#include "Tile.h"
#include "Log.h"
#include "Array.h"

#include "RoadContainer.h"
#include "FieldContainer.h"
#include "CloisterContainer.h"
#include "CityContainer.h"



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

		RoadContainer roads;
		CityContainer cities;
		FieldContainer fields;
		CloisterContainer cloisters;

		Array<Position, 2 * NUMBER_OF_TILES + 2> reachablePositions;
		Array<ReachablePositionLog, NUMBER_OF_TILES> reachableLogs;

		BlocStatic<int, NUMBER_OF_PLAYERS> farmerScores;

		void reachablePositions_reach(int ir);
		void reachablePositions_cancel(const Position & pCancel);

		void tiles_reach(const Position & p, IndexBlueprint indexBlueprint, const Direction & direction);
		void tiles_cancel();

		// nbNodes > 0
		void linkRoads(const Position& p);
		void linkCities(const Position& p);
		void linkFields(const Position& p);

		// nbFields > 0
		void fieldnodes_setNeighbors(int idxTile);

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

		int getNumberReachablePositions() const { return reachablePositions.length(); }
		// getNumberPositions() == getNumberTiles()
		int getNumberPositions() const { return positions.length(); }
		// getNumberTiles() == getNumberPositions()
		int getNumberTiles() const { return tiles.length(); }

		CloisterIterator getCloisterIterator() const { return cloisters.getIterator(); }
		RoadIterator getRoadIterator() const { return roads.getIterator(); }
		CityIterator getCityIterator() const { return cities.getIterator(); }

		const FollowerLog & getFollowerLog(int i) const { return followerLogs[i]; }


		int getIndexPosition(const Position & p) const { return positions.indexOf(p); }
		bool isOccupied(const Position & p) const { return positions.find(p); }
		bool isReachable(const Position & p) const { return reachablePositions.find(p); }

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

		bool hasIdleFollower(int p) const { return (6 - roads.getBusyFollowers()[p] - cities.getBusyFollowers()[p] - fields.getBusyFollowers()[p]) > 0; }
		bool hasIdleFollower() const { return hasIdleFollower(getCurrentPlayer()); }

		int getScore(int i) const { return farmerScores[i] + roads.getThiefScores()[i] + cloisters.getMonkScores()[i] + cities.getKnightScores()[i]; }
		int getThiefScore(int i) const { return roads.getThiefScores()[i]; }
		int getKnightScore(int i) const { return cities.getKnightScores()[i]; }
		int getMonkScore(int i) const { return cloisters.getMonkScores()[i]; }
		int getFarmerScore(int i) const { return farmerScores[i]; }

		void cancel();

		void end();
		void cancelEnd();

	};



	


	

}
