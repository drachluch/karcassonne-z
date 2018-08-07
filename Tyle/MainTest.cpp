#include "MainTest.h"
#include "Game.h"
#include "Drawer.h"
#include <iostream>

void cloisterOnePlayer()
{
	Game g;

	for (int xx = 0; xx < 72 && g.hasRemainingBlueprint(); xx++) {
		int idxBlueprint = g.nextBlueprintIndex();
		const auto & blueprint = g.getBlueprint(idxBlueprint);

		bool isScoreInitialised = false;
		int idxPosition = -1;
		Direction dir;
		float score = 0.;


		for (int i = 0, l = g.getNumberReachablePositions(); i < l; i++) {
			for (int d = 0; d < blueprint.getNumberOfPertinentDirection(); d++) {
				if (g.canSetTile(i, idxBlueprint, Direction{ d })) {
					g.setTile(i, idxBlueprint, Direction{ d });

					if (g.hasIdleFollower() && g.canSetMonk())
						g.setMonk();

					//float t_score = exploreTheFuture_cloisterOnePlayer(g, 0);
					float t_score = (float) evaluateCloistersState(g);

					g.cancel();

					if (!isScoreInitialised || score < t_score) {
						idxPosition = i;
						dir = Direction{ d };
						score = t_score;
						isScoreInitialised = true;
					}
				}
			}
		}

		if (!isScoreInitialised)
			g.discardBlueprint(idxBlueprint);
		else {
			//std::cerr << g.getReachablePosition(idxPosition) << " : " << idxBlueprint << " : " << dir.get() << std::endl;
			g.setTile(idxPosition, idxBlueprint, dir);
			if (g.hasIdleFollower() && g.canSetMonk())
				g.setMonk();
		}
	}

	g.end();
	std::cerr << g.getScore(0) << std::endl;


	writeHTMLHeader(std::cout);
	std::cout << "<body><script language=\"javascript\">var state=";
	writeCurrentState(std::cout, g);
	std::cout << ";var followers =";
	writeFollowers(std::cout, g);
	std::cout << ";K.showLogState20180729(\"first\",state,followers);</script></body></html>";

}




// en situation standard (hors tentative de prédiction), le blueprint à placer est aléatoire.
// donc on calcule le score max pour chaque blueprint, puis on agrège en prenant la moyenne des scores.
float exploreTheFuture_cloisterOnePlayer(Game & g, int depth)
{
	if (depth < 0)
		throw "Depth can't be strictly negative.";

	//float score = evaluateCloistersState(g);
	float score = 0.;
	bool isThereAnyWayOut = false;

	int remainingBlueprints = g.getSumRemainingNumber();

	// parcours de l'ensemble des blueprints
	for (int indexBlueprint = 0; indexBlueprint < NUMBER_OF_DISTINCT_TILES; indexBlueprint++) {
		int remainingBlueprintsOfThisKind = g.getRemainingNumberBlueprint(indexBlueprint);

		// s'il reste au moins un blueprint de la sorte
		if (remainingBlueprintsOfThisKind > 0) {

			const auto & blue = g.getBlueprint(indexBlueprint);
			int nbOfPertinentDirection = blue.getNumberOfPertinentDirection();

			bool isInitialisedScore = false;
			float scoreMax = 0.;

			// parcours de l'ensemble des positions disponibles
			for (int indexReachablePosition = 0, numberReachablePositions = g.getNumberReachablePositions(); indexReachablePosition < numberReachablePositions; indexReachablePosition++) {
				// parcours de l'ensemble des directions possibles pour le blueprint
				for (int d = 0; d < nbOfPertinentDirection; d++) {
					if (g.canSetTile(indexReachablePosition, indexBlueprint, Direction{ d })) {
						g.setTile(indexReachablePosition, indexBlueprint, Direction{ d });
						isThereAnyWayOut = true;

						if (g.canSetMonk() && g.hasIdleFollower()) {
							g.setMonk();
						}

						float temp_score = depth == 0
							? (int) evaluateCloistersState(g)
							: exploreTheFuture_cloisterOnePlayer(g, depth - 1);

						// agrégation en prenant le maximum
						if (!isInitialisedScore || temp_score > scoreMax) {
							scoreMax = temp_score;
							isInitialisedScore = true;
						}

						g.cancel();
					}
				}
			}
			
			float probability = (float)remainingBlueprintsOfThisKind / (float)remainingBlueprints;
			// agrégation en prenant la moyenne des maximum
			score += scoreMax * probability;

		}
	}
	
	return isThereAnyWayOut
		? score
		: evaluateCloistersState(g);
}


int evaluateCloistersState(const Game & g) {
	int score = 0;
	for (int i = 0, l = g.getNumberCloisters(); i < l; i++) {
		const auto & c = g.getCloister(i);
		if (c.hasDirectFollower())
			score += c.score();
	}
	return score;
}

void roadnodeOnePlayer()
{
	Game g;

	for (int xx = 0; xx < 72 && g.hasRemainingBlueprint(); xx++) {
		int idxBlueprint = g.nextBlueprintIndex();
		const auto & blueprint = g.getBlueprint(idxBlueprint);

		bool isScoreInitialised = false;
		int idxPosition = -1;
		Direction dir;
		float score = 0.;
		int way = -1;

		const int depth = 0;

		for (int i = 0, l = g.getNumberReachablePositions(); i < l; i++) {
			for (int d = 0; d < blueprint.getNumberOfPertinentDirection(); d++) {
				if (g.canSetTile(i, idxBlueprint, Direction{ d })) {
					g.setTile(i, idxBlueprint, Direction{ d });

					//float t_score = exploreTheFuture_roadnodeOnePlayer(g, depth);
					float t_score = evaluateRoadnodesState(g);

					if (!isScoreInitialised || score < t_score) {
						idxPosition = i;
						dir = Direction{ d };
						score = t_score;
						way = -1;
						isScoreInitialised = true;
					}

					if (g.hasIdleFollower()) {
						int ways = g.waysToSetThief();

						for (int idxWay = 0; idxWay < ways; idxWay++) {
							g.setThief(idxWay);

							//t_score = exploreTheFuture_roadnodeOnePlayer(g, depth);
							t_score = evaluateRoadnodesState(g);

							if (score < t_score) {
								idxPosition = i;
								dir = Direction{ d };
								score = t_score;
								way = idxWay;
							}

							g.cancelThief(idxWay);
						}
					}

					//float t_score = evaluateRoadnodesState(g);

					g.cancel();
				}
			}
		}

		if (!isScoreInitialised)
			g.discardBlueprint(idxBlueprint);
		else {
			
			//std::cerr << g.getReachablePosition(idxPosition) << " bp " << idxBlueprint << " dir " << dir.get();
			
			g.setTile(idxPosition, idxBlueprint, dir);
			
			if (way != -1) {
				g.setThief(way);
				//std::cerr << " way " << way;
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

float exploreTheFuture_roadnodeOnePlayer(Game & g, int depth)
{
	if (depth < 0)
		throw "Depth can't be strictly negative.";

	//float score = evaluateCloistersState(g);
	float score = 0.;
	bool isThereAnyWayOut = false;

	int remainingBlueprints = g.getSumRemainingNumber();

	// parcours de l'ensemble des blueprints
	for (int indexBlueprint = 0; indexBlueprint < NUMBER_OF_DISTINCT_TILES; indexBlueprint++) {
		int remainingBlueprintsOfThisKind = g.getRemainingNumberBlueprint(indexBlueprint);

		// s'il reste au moins un blueprint de la sorte
		if (remainingBlueprintsOfThisKind > 0) {

			const auto & blue = g.getBlueprint(indexBlueprint);
			int nbOfPertinentDirection = blue.getNumberOfPertinentDirection();

			bool isInitialisedScore = false;
			float scoreMax = 0.;

			// parcours de l'ensemble des positions disponibles
			for (int indexReachablePosition = 0, numberReachablePositions = g.getNumberReachablePositions(); indexReachablePosition < numberReachablePositions; indexReachablePosition++) {
				// parcours de l'ensemble des directions possibles pour le blueprint
				for (int d = 0; d < nbOfPertinentDirection; d++) {
					if (g.canSetTile(indexReachablePosition, indexBlueprint, Direction{ d })) {
						g.setTile(indexReachablePosition, indexBlueprint, Direction{ d });
						isThereAnyWayOut = true;


						float temp_score = depth == 0
							? evaluateRoadnodesState(g)
							: exploreTheFuture_roadnodeOnePlayer(g, depth - 1);

						// agrégation en prenant le maximum
						if (!isInitialisedScore || temp_score > scoreMax) {
							scoreMax = temp_score;
							isInitialisedScore = true;
						}


						if (g.hasIdleFollower()) {
							int ways = g.waysToSetThief();

							for (int idxWay = 0; idxWay < ways; idxWay++) {
								g.setThief(idxWay);


								temp_score = depth == 0
									? evaluateRoadnodesState(g)
									: exploreTheFuture_roadnodeOnePlayer(g, depth - 1);

								// agrégation en prenant le maximum
								if (temp_score > scoreMax) {
									scoreMax = temp_score;
								}

								g.cancelThief(idxWay);
							}
						}

						g.cancel();
					}
				}
			}

			float probability = (float)remainingBlueprintsOfThisKind / (float)remainingBlueprints;
			// agrégation en prenant la moyenne des maximum
			score += scoreMax * probability;

		}
	}

	return isThereAnyWayOut
		? score
		: evaluateRoadnodesState(g);
}

float evaluateRoadnodesState(const Game & g)
{
	float score = (float) g.getScore(0);

	for (int idxRoadnode = 0, l = g.getNumberRoadNodes(); idxRoadnode < l; idxRoadnode++) {
		const RoadNode & rn = g.getRoadNode(idxRoadnode);
		if (!rn.hasFather() && rn.hasAnyFollower() && !rn.isCompleted())
			score += rn.score() * .9375f;
	}

	return score;
}

void bothOnePlayer()
{
	Game g;

	for (int xx = 0; xx < 72 && g.hasRemainingBlueprint(); xx++) {
		int idxBlueprint = g.nextBlueprintIndex();
		const auto & blueprint = g.getBlueprint(idxBlueprint);

		bool isScoreInitialised = false;
		int idxPosition = -1;
		Direction dir;
		float score = 0.;
		OptionFollowerType folType = OptionFollowerType::None;
		int way = -1;

		const int depth = 0;

		for (int i = 0, l = g.getNumberReachablePositions(); i < l; i++) {
			for (int d = 0; d < blueprint.getNumberOfPertinentDirection(); d++) {
				if (g.canSetTile(i, idxBlueprint, Direction{ d })) {
					g.setTile(i, idxBlueprint, Direction{ d });

					float t_score = evaluateBothState(g);

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

							t_score = evaluateBothState(g);

							if (score < t_score) {
								idxPosition = i;
								dir = Direction{ d };
								score = t_score;
								folType = OptionFollowerType::Monk;
								way = -1;
							}

							g.cancelMonk();
						}

						int ways = g.waysToSetThief();

						for (int idxWay = 0; idxWay < ways; idxWay++) {
							g.setThief(idxWay);

							t_score = evaluateBothState(g);

							if (score < t_score) {
								idxPosition = i;
								dir = Direction{ d };
								score = t_score;
								folType = OptionFollowerType::Thief;
								way = idxWay;
							}

							g.cancelThief(idxWay);
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

float evaluateBothState(const Game & g)
{
	float score = (float)g.getScore(0);

	for (int idxRoadnode = 0, l = g.getNumberRoadNodes(); idxRoadnode < l; idxRoadnode++) {
		const RoadNode & rn = g.getRoadNode(idxRoadnode);
		if (!rn.hasFather() && rn.hasAnyFollower() && !rn.isCompleted())
			score += rn.score() * .9375f;
	}

	for (int i = 0, l = g.getNumberCloisters(); i < l; i++) {
		const auto & c = g.getCloister(i);
		if (c.hasDirectFollower() && !c.isCompleted())
			score += c.score();
	}

	return score;
}
