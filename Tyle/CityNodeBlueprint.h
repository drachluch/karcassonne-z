#pragma once

namespace kar {

	struct CityNodeBlueprint {

		int holes;
		bool crest;

		int numberAdjacentFieldNodes;
		int adjacentFieldNodes[2];

		int getNumberOfHoles() const { return holes; }
		bool hasCrest() const { return crest; }
		int getNumberAdjacentFieldNodes() const { return numberAdjacentFieldNodes; }
		const int * getAdjacentFieldNodes() const { return adjacentFieldNodes; }

	};

}
