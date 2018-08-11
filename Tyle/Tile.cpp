#include "Tile.h"

namespace kar {

	Tile::Tile(int idxBlueprint, const TileBlueprint & tb, const Direction & d)
		: name(tb.getName()), indexBlueprint(idxBlueprint), direction(d)
	{
		for (int i = 0; i < 4; i++)
			sides[i].side = tb.getSideType(Direction{ i }.rotateTrigo(d));

	}

	void Tile::setNodes(const TileBlueprint & tb, int firstIndexRoadNode, int firstIndexCityNode, int firstIndexFieldNode)
	{
		for (int i = 0; i < 4; i++) {
			const auto dir = Direction{ i }.rotateTrigo(direction);
			switch (sides[i].side) {
			case SideType::City:
				sides[i].cityNode = firstIndexCityNode + tb.getCityNode(dir);
				break;
			case SideType::Field:
				sides[i].fieldNode = firstIndexFieldNode + tb.getFieldNode(dir);
				break;
			case SideType::Road:
				sides[i].roadNode = firstIndexRoadNode + tb.getFieldNode(dir);
				sides[i].leftFieldNode = firstIndexFieldNode + tb.getLeftFieldNode(dir);
				sides[i].rightFieldNode = firstIndexFieldNode + tb.getRightFieldNode(dir);
				break;
			default:
				throw "wtf ?";
			}
		}
	}

}
