#include "RoadNode.h"
#include <string>

RoadNode::RoadNode(const RoadNodeBlueprint & rnb)
	: holes(rnb.getNumberOfHoles())
{
	memset(cumulatedFollowers, 0, sizeof(cumulatedFollowers));
}

RoadNode::RoadNode(const RoadNodeBlueprint & rnb, int idxTile)
	: holes(rnb.getNumberOfHoles()), ambigiousPosition(idxTile)
{
	memset(cumulatedFollowers, 0, sizeof(cumulatedFollowers));
}

RoadNode & RoadNode::operator=(const RoadNode & rn)
{
	father = rn.father;
	numberOfSons = rn.numberOfSons;
	memcpy(sons, rn.sons, sizeof(sons));
	garbageDirectFollower = rn.garbageDirectFollower;
	memcpy(cumulatedFollowers, rn.cumulatedFollowers, sizeof(cumulatedFollowers));
	coveredTiles = rn.coveredTiles;
	holes = rn.holes;
	ambigiousPosition = rn.ambigiousPosition;
	
	return *this;
}

// don't use the roadnode after unlinking the children
void RoadNode::unlinkChildren()
{
	for (int i = 0; i < numberOfSons; i++)
		sons[i]->father = nullptr;
}

// son has no father
void RoadNode::becomeFatherOf(RoadNode * son)
{

	if (numberOfSons < 0 && numberOfSons > 2)
		throw "number of sons not acceptable";

	sons[numberOfSons] = son;
	numberOfSons++;
	son->father = this;

	// holes §§ une fusion a eu lieu, donc deux trous ont été bouchés.
	holes += son->holes - 2;

	// followers
	if (son->hasAnyFollower()) {
		if (garbageDirectFollower == -2)
			garbageDirectFollower = -1;
		for (int i = 0; i < NUMBER_OF_PLAYERS; i++)
			cumulatedFollowers[i] += son->cumulatedFollowers[i];
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


