#include "MainTest2.h"
#include "Drawer.h"
#include <iostream>


float evaluateCitiesRoadsAndCloistersState(const Game & g);

//

void citiesRoadsAndCloisters_OnePlayer()
{
	Game g;

	for (int xx = 0; xx < 72 && g.hasRemainingBlueprint(); xx++) {
		int idxBlueprint = g.nextBlueprintIndex();
		const auto & blueprint = g.getBlueprint(idxBlueprint);

		bool isScoreInitialised = false;
		int idxPosition = -1;
		Direction dir;
		auto score = 0.f;
		OptionFollowerType folType = OptionFollowerType::None;
		int way = -1;

		const int depth = 0;

		for (int i = 0, l = g.getNumberReachablePositions(); i < l; i++) {
			for (int d = 0; d < blueprint.getNumberOfPertinentDirection(); d++) {
				if (g.canSetTile(i, idxBlueprint, Direction{ d })) {
					g.setTile(i, idxBlueprint, Direction{ d });

					auto t_score = evaluateCitiesRoadsAndCloistersState(g);

					if (!isScoreInitialised || score < t_score) {
						idxPosition = i;
						dir = Direction{ d };
						score = t_score;
						folType = OptionFollowerType::None;
						way = -1;
						isScoreInitialised = true;
					}

					if (g.hasIdleFollower()) {
						if (g.canSetMonk()) {
							g.setMonk();

							t_score = evaluateCitiesRoadsAndCloistersState(g);

							if (score < t_score) {
								idxPosition = i;
								dir = Direction{ d };
								score = t_score;
								folType = OptionFollowerType::Monk;
								way = -1;
							}

							g.cancelMonk();
						}

						auto ways = g.waysToSetThief();

						for (auto idxWay = 0; idxWay < ways; idxWay++) {
							g.setThief(idxWay);

							t_score = evaluateCitiesRoadsAndCloistersState(g);

							if (score < t_score) {
								idxPosition = i;
								dir = Direction{ d };
								score = t_score;
								folType = OptionFollowerType::Thief;
								way = idxWay;
							}

							g.cancelThief(idxWay);
						}

						ways = g.waysToSetKnight();

						for (auto idxWay = 0; idxWay < ways; idxWay++) {
							g.setKnight(idxWay);

							t_score = evaluateCitiesRoadsAndCloistersState(g);

							if (score < t_score) {
								idxPosition = i;
								dir = Direction{ d };
								score = t_score;
								folType = OptionFollowerType::Knight;
								way = idxWay;
							}

							g.cancelKnight(idxWay);
						}
					}

					g.cancel();
				}
			}
		}

		if (!isScoreInitialised)
			g.discardBlueprint(idxBlueprint);
		else {

			//std::cerr << g.getReachablePosition(idxPosition) << " bp " << idxBlueprint << " dir " << dir.get();

			g.setTile(idxPosition, idxBlueprint, dir);

			switch (folType) {
			case OptionFollowerType::Monk:
				g.setMonk();
				break;
			case OptionFollowerType::Thief:
				g.setThief(way);
				break;
			case OptionFollowerType::Knight:
				g.setKnight(way);
				break;
			default:
				break;
			}

			//std::cerr << " score " << g.getScore(0) << std::endl;

		}
	}

	g.end();
	std::cerr << g.getScore(0) << std::endl;


	//*
	writeHTMLHeader(std::cout);
	std::cout << "<body><script language=\"javascript\">var state=";
	writeCurrentState(std::cout, g);
	std::cout << ";var followers =";
	writeFollowers(std::cout, g);
	std::cout << ";K.showLogState20180729(\"first\",state,followers);</script></body></html>";
	//*/

}

float evaluateCitiesRoadsAndCloistersState(const Game & g)
{
	auto score = (float)g.getScore(0);

	for (int idxRoadnode = 0, l = g.getNumberRoadNodes(); idxRoadnode < l; idxRoadnode++) {
		const auto & rn = g.getRoadNode(idxRoadnode);
		if (!rn.hasFather() && rn.hasAnyFollower() && !rn.isCompleted())
			score += rn.score() * .9375f;
	}

	for (int idxCitynode = 0, l = g.getNumberCityNodes(); idxCitynode < l; idxCitynode++) {
		const auto & cn = g.getCityNode(idxCitynode);
		if (!cn.hasFather() && cn.hasAnyFollower() && !cn.isCompleted())
			score += cn.score() * 1.25f;
	}

	for (int i = 0, l = g.getNumberCloisters(); i < l; i++) {
		const auto & c = g.getCloister(i);
		if (c.hasDirectFollower() && !c.isCompleted())
			score += c.score();
	}

	return score;
}
