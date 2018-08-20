#include "MainTestLonelyFarmer.h"
#include "Game.h"
#include "Drawer.h"
#include <iostream>

auto evaluateCities(const kar::Game & g)
{
	auto score = g.getScore(0);

	for (auto it = g.getCityIterator(); it.isNotOver(); ++it) {
		const auto & c = it.getCore();
		if (c.followers.max() > 0)
			score += c.score();
	}

	return score;
}


void oneFarmer_OnePlayer()
{
	kar::Game g;

	// tentative de placement du paysan.
	{
		bool farmerSet = false;
		for (; g.hasRemainingBlueprint() && !farmerSet;) {
			const auto idxBlueprint = g.nextBlueprintIndex();
			const auto & blueprint = g.getBlueprint(idxBlueprint);

			int idxPosition = -1;
			kar::Direction dir;
			bool canSetSomewhere = false;

			for (int i = 0, l = g.getNumberReachablePositions(); i < l && !farmerSet; i++) {
				for (int d = 0; d < blueprint.getNumberOfPertinentDirection() && !farmerSet; d++) {
					if (g.canSetTile(i, idxBlueprint, kar::Direction{ d })) {
						g.setTile(i, idxBlueprint, kar::Direction{ d });

						canSetSomewhere = true;

						if (!farmerSet) {
							farmerSet = g.waysToSetFarmer() > 0;
							idxPosition = i;
							dir = kar::Direction{ d };
						}

						g.cancel();
					}
				}
			}

			if (!canSetSomewhere)
				g.discardBlueprint(idxBlueprint);
			else {
				g.setTile(idxPosition, idxBlueprint, dir);
				if (farmerSet)
					g.setFarmer(0);
			}
		}
	}


	// placement des tuiles suivantes avec des chevaliers.
	{
		for (; g.hasRemainingBlueprint(); ) {
			const auto idxBlueprint = g.nextBlueprintIndex();
			const auto & blueprint = g.getBlueprint(idxBlueprint);

			bool isScoreInitialised = false;
			int idxPosition = -1;
			kar::Direction dir;
			auto score = 0;
			int way = -1;

			const int depth = 0;
			auto before_score = g.getScore(0);

			for (int i = 0, l = g.getNumberReachablePositions(); i < l; i++) {
				for (int d = 0; d < blueprint.getNumberOfPertinentDirection(); d++) {
					if (g.canSetTile(i, idxBlueprint, kar::Direction{ d })) {
						g.setTile(i, idxBlueprint, kar::Direction{ d });

						auto t_score = evaluateCities(g);

						if (!isScoreInitialised || score < t_score) {
							idxPosition = i;
							dir = kar::Direction{ d };
							score = t_score;
							way = -1;
							isScoreInitialised = true;
						}

						if (g.hasIdleFollower()) {
							const auto ways = g.waysToSetKnight();

							for (auto idxWay = 0; idxWay < ways; idxWay++) {
								g.setKnight(idxWay);

								t_score = evaluateCities(g);

								if (score < t_score) {
									idxPosition = i;
									dir = kar::Direction{ d };
									score = t_score;
									way = idxWay;
								}

								g.cancelKnight(idxWay);
							}
						}

						g.cancel();
					}
				}
			}

			if (before_score != g.getScore(0))
				throw "score has been modified";

			if (!isScoreInitialised)
				g.discardBlueprint(idxBlueprint);
			else {

				g.setTile(idxPosition, idxBlueprint, dir);
				if (way > -1)
					g.setKnight(way);

			}


		}
	}


	g.end();
	std::cerr << g.getFarmerScore(0) << '+' << g.getKnightScore(0) << std::endl;

	writeStats20180817(std::cout, g);
}
