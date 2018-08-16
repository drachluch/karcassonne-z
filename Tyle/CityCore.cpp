#include "CityCore.h"
#include <algorithm>

void kar::CityCore::assimilate(const CityCore & cc)
{
	holes += cc.holes - 2;
	crest += cc.crest;

	if (cc.hasAnyFollower()) {
		if (garbageFollower == -2) {
			garbageFollower = -1;
			followers = cc.followers;
		}
		else
			followers += cc.followers;
	}

	// coveredTiles
	if (ambigiousPositions.empty()) {
		coveredArea += cc.coveredArea;
		ambigiousPositions = cc.ambigiousPositions;
	}
	else {
		if (cc.ambigiousPositions.empty()) {
			coveredArea += cc.coveredArea;
		}
		else {
			const auto oldSize = ambigiousPositions.size();

			ambigiousPositions.insert(ambigiousPositions.end(), cc.ambigiousPositions.begin(), cc.ambigiousPositions.end());
			std::sort(ambigiousPositions.begin(), ambigiousPositions.end());
			std::unique(ambigiousPositions.begin(), ambigiousPositions.end());

			coveredArea += cc.coveredArea - oldSize - cc.ambigiousPositions.size() + ambigiousPositions.size();
		}
	}
}