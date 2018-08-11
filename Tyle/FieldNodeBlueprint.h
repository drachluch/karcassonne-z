#pragma once

namespace kar {

	struct FieldNodeBlueprint {
		int numberAdjacentCityNodes;
		int adjacentCityNodes[2];

		int getNumberAdjacentCityNodes() const { return numberAdjacentCityNodes; }
		const int * getAdjacentCityNodes() const { return adjacentCityNodes; }
	};

}