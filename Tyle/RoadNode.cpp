#include "RoadNode.h"
#include <string>

namespace kar {

	void RoadNode::reset(const RoadNodeBlueprint & rnb)
	{
		father = nullptr;

		sons.cleanse();

		garbageDirectFollower = -2;
		cumulatedFollowers.reset(0);

		coveredTiles = 1;
		holes = rnb.getNumberOfHoles();

		ambigiousPosition = -1;
	}

	void RoadNode::reset(const RoadNodeBlueprint & rnb, int idxTile)
	{
		father = nullptr;

		sons.cleanse();

		garbageDirectFollower = -2;
		cumulatedFollowers.reset(0);

		coveredTiles = 1;
		holes = rnb.getNumberOfHoles();

		ambigiousPosition = idxTile;

	}

	// don't use the roadnode after unlinking the children
	void RoadNode::unlinkChildren()
	{
		for (int i = 0; i < sons.length(); i++)
			sons[i]->father = nullptr;
	}

	// son has no father
	void RoadNode::becomeFatherOf(RoadNode * son)
	{
		sons.push(son);
		son->father = this;

		// holes §§ une fusion a eu lieu, donc deux trous ont été bouchés.
		holes += son->holes - 2;

		// followers
		if (son->hasAnyFollower()) {
			if (garbageDirectFollower == -2)
				garbageDirectFollower = -1;
			cumulatedFollowers = son->cumulatedFollowers;
		}

		// coveredTiles
		if (ambigiousPosition == -1) {
			coveredTiles += son->coveredTiles;
			ambigiousPosition = son->ambigiousPosition;
		}
		else {
			if (son->ambigiousPosition != ambigiousPosition) {
				coveredTiles += son->coveredTiles;
			}
			else {
				coveredTiles += son->coveredTiles - 1;
			}
		}
	}

}
