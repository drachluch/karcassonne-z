#include "City.h"
#include <algorithm>

void kar::City::becomeFatherOf(City & ndSon, const Index idxFather, const Index idxSon)
{
	sons.push_back(idxSon);
	ndSon.father = idxFather;

	// holes §§ une fusion a eu lieu, donc deux trous ont été bouchés.
	core.holes += ndSon.core.holes - 2;
	core.crest += ndSon.core.crest;

	// followers
	if (ndSon.hasAnyFollower()) {
		if (garbageFollower == -2) {
			garbageFollower = -1;
			core.followers = ndSon.core.followers;
		}
		else
			core.followers += ndSon.core.followers;
	}

	// coveredTiles
	if (ambigiousPositions.empty()) {
		core.coveredArea += ndSon.core.coveredArea;
		ambigiousPositions = ndSon.ambigiousPositions;
	}
	else {
		if (ndSon.ambigiousPositions.empty()) {
			core.coveredArea += ndSon.core.coveredArea;
		}
		else {
			const auto oldSize = ambigiousPositions.size();

			ambigiousPositions.insert(ambigiousPositions.end(), ndSon.ambigiousPositions.begin(), ndSon.ambigiousPositions.end());
			std::sort(ambigiousPositions.begin(), ambigiousPositions.end());
			std::unique(ambigiousPositions.begin(), ambigiousPositions.end());

			core.coveredArea += ndSon.core.coveredArea - oldSize - ndSon.ambigiousPositions.size() + ambigiousPositions.size();
		}
	}
}