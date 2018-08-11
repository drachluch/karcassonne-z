#include "CityNode.h"
#include <string>

namespace kar {

	void CityNode::reset(const CityNodeBlueprint & cnb)
	{
		father = nullptr;

		sons.cleanse();

		garbageDirectFollower = -2;
		cumulatedFollowers.reset(0);

		coveredTiles = 1;
		holes = cnb.getNumberOfHoles();

		crest = cnb.hasCrest() ? 1 : 0;

		ambigiousPositions.cleanse();

	}

	void CityNode::reset(const CityNodeBlueprint & cnb, int idxTile)
	{
		reset(cnb);

		ambigiousPositions.push(idxTile);
	}

	// don't use the roadnode after unlinking the children
	void CityNode::unlinkChildren()
	{
		for (int i = 0; i < sons.length(); i++)
			sons[i]->father = nullptr;
	}

	// son has no father
	void CityNode::becomeFatherOf(CityNode * son)
	{
		sons.push(son);
		son->father = this;

		crest += son->crest;

		// holes §§ une fusion a eu lieu, donc deux trous ont été bouchés.
		holes += son->holes - 2;

		// followers
		if (son->hasAnyFollower()) {
			if (garbageDirectFollower == -2)
				garbageDirectFollower = -1;
			cumulatedFollowers += son->cumulatedFollowers;
		}

		// coveredTiles
		if (ambigiousPositions.length() == 0) {
			coveredTiles += son->coveredTiles;

			if (son->ambigiousPositions.length() > 0) {
				// les zones ambigues du fils deviennent celles du pere
				ambigiousPositions = son->ambigiousPositions;
			}
		}
		else {
			if (son->ambigiousPositions.length() == 0) {
				coveredTiles += son->coveredTiles;
			}
			else {
				AmbigiousPositions temp_sorted;
				fusion_sort(temp_sorted, ambigiousPositions, son->ambigiousPositions);

				coveredTiles += son->coveredTiles - son->ambigiousPositions.length() - ambigiousPositions.length() + temp_sorted.length();

				// copie des positions ambigues triées.
				ambigiousPositions = temp_sorted;
			}
		}
	}

}