#pragma once
#include "SideType.h"
#include "TileBlueprint.h"
#include "Direction.h"

struct Side {
	SideType side;

	union {
		int cityNode;
		int fieldNode;
		int roadNode;
	};

	int leftFieldNode;
	int rightFieldNode;

};


struct Tile {
	const char * name = nullptr;
	Direction direction;
	int indexBlueprint;
	Side sides[4];

	Tile() = default;
	Tile(int idxBlueprint, const TileBlueprint & tb, const Direction & d);
	~Tile() = default;

	void setNodes(const TileBlueprint & tb, int firstIndexRoadNode, int firstIndexCityNode, int firstIndexFieldNode);

	const char * getName() const  { return name; }
	const Direction & getDirection() const  { return direction; }
	int getIndexBlueprint() const  { return indexBlueprint; }

	SideType getSideType(const Direction & d) const  { return sides[d.get()].side; }
	bool compatible(const TileBlueprint & tb, const Direction & tbDir, const Direction & sideDir) const  {
		return getSideType(sideDir.opposite()) == tb.getSideType(sideDir.rotateTrigo(tbDir));
	}

	int getRoadNode(const Direction & d) const  { return sides[d.get()].roadNode; }
	int getCityNode(const Direction & d) const  { return sides[d.get()].cityNode; }
	int getFieldNode(const Direction & d) const  { return sides[d.get()].fieldNode; }
	int getLeftFieldNode(const Direction & d) const  { return sides[d.get()].leftFieldNode; }
	int getRightFieldNode(const Direction & d) const  { return sides[d.get()].rightFieldNode; }

	void setRoadNode(const Direction & d, int rn)  { sides[d.get()].roadNode = rn; }
	void setCityNode(const Direction & d, int cn)  { sides[d.get()].cityNode = cn; }
	void setFieldNode(const Direction & d, int fn)  { sides[d.get()].fieldNode = fn; }
	void setLeftFieldNode(const Direction & d, int fn)  { sides[d.get()].leftFieldNode = fn; }
	void setRightFieldNode(const Direction & d, int fn)  { sides[d.get()].rightFieldNode = fn; }


	const Direction & getFirstDirectionOfRoadnode(int indexRoadnode) const {
		for (int i = 0; i < 4; i++)
			if (sides[i].side == SideType::Road)
				if (sides[i].roadNode == indexRoadnode)
					return Direction{ i };
		throw "IndexRoadnode not found in tile.";
	}

};

