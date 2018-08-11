#pragma once
#include "SideType.h"
#include "TileBlueprint.h"
#include "Direction.h"
#include "FieldPosition.h"

namespace kar {

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

		const char * getName() const { return name; }
		const Direction & getDirection() const { return direction; }
		int getIndexBlueprint() const { return indexBlueprint; }

		SideType getSideType(const Direction & d) const { return sides[d.get()].side; }
		bool compatible(const TileBlueprint & tb, const Direction & tbDir, const Direction & sideDir) const {
			return getSideType(sideDir.opposite()) == tb.getSideType(sideDir.rotateTrigo(tbDir));
		}

		int getRoadNode(const Direction & d) const { return sides[d.get()].roadNode; }
		int getCityNode(const Direction & d) const { return sides[d.get()].cityNode; }
		int getFieldNode(const Direction & d) const { return sides[d.get()].fieldNode; }
		int getLeftFieldNode(const Direction & d) const { return sides[d.get()].leftFieldNode; }
		int getRightFieldNode(const Direction & d) const { return sides[d.get()].rightFieldNode; }

		void setRoadNode(const Direction & d, int rn) { sides[d.get()].roadNode = rn; }
		void setCityNode(const Direction & d, int cn) { sides[d.get()].cityNode = cn; }
		void setFieldNode(const Direction & d, int fn) { sides[d.get()].fieldNode = fn; }
		void setLeftFieldNode(const Direction & d, int fn) { sides[d.get()].leftFieldNode = fn; }
		void setRightFieldNode(const Direction & d, int fn) { sides[d.get()].rightFieldNode = fn; }


		Direction getFirstDirectionOfRoadnode(int indexRoadnode) const {
			for (int i = 0; i < 4; i++)
				if (sides[i].side == SideType::Road)
					if (sides[i].roadNode == indexRoadnode)
						return Direction{ i };
			throw "IndexRoadnode not found in tile.";
		}

		Direction getFirstDirectionOfCitynode(int indexCitynode) const {
			for (int i = 0; i < 4; i++)
				if (sides[i].side == SideType::City)
					if (sides[i].cityNode == indexCitynode)
						return Direction{ i };
			throw "IndexCitynode not found in tile.";
		}

		CompleteFieldPosition getFirstDirectionOfFieldnode(int indexFieldnode) const {
			for (int i = 0; i < 4; i++)
				if (sides[i].side == SideType::Field) {
					if (sides[i].fieldNode == indexFieldnode)
						return CompleteFieldPosition{ Direction{i}, FieldPosition::Center };
				}
				else
					if (sides[i].side == SideType::Road) {
						if (sides[i].leftFieldNode == indexFieldnode)
							return CompleteFieldPosition{ Direction{i}, FieldPosition::Left };
						else
							if (sides[i].rightFieldNode == indexFieldnode)
								return CompleteFieldPosition{ Direction{i}, FieldPosition::Right };
					}
			throw "IndexFieldnode not found in tile.";
		}

	};

}