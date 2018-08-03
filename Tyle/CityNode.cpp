#include "CityNode.h"

CityNode::CityNode(const CityNodeBlueprint & cnb)
	: holes(cnb.getNumberOfHoles()), crest(cnb.hasCrest() ? 1 : 0)
{
	cleanseCumulatedFollowers();
}

void CityNode::addAmbigiousPosition(int p)
{
	if (numberOfAmbigiousPositions > 1)
		throw "RoadNode : too many ambigious positions.";
	ambigiousPositions[numberOfAmbigiousPositions] = p;
	numberOfAmbigiousPositions++;
}

bool CityNode::hasAnyFollower() const 
{
	for (int i = 0; i < NUMBER_OF_PLAYERS; i++)
		if (cumulatedFollowers[i] > 0)
			return true;
	return hasDirectFollower();
}
