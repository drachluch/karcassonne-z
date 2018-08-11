#pragma once
#include "SideType.h"
#include "Direction.h"
#include "Array.h"
#include "RoadNodeBlueprint.h"
#include "CityNodeBlueprint.h"
#include "FieldNodeBlueprint.h"

namespace kar {

	struct SideBlueprint {
		SideType side;

		union {
			int cityNode;
			int fieldNode;
			int roadNode;
		};

		int leftFieldNode;
		int rightFieldNode;

	};

	class TileBlueprint {
	public:
		using RoadNodeBlueprints = Array<RoadNodeBlueprint, 4>;
		using CityNodeBlueprints = Array<CityNodeBlueprint, 2>;
		using FieldNodeBlueprints = Array<FieldNodeBlueprint, 4>;

	private:
		const char * name;
		SideBlueprint sides[4];
		int rqMax;

		bool cloister;

		RoadNodeBlueprints rnb;
		CityNodeBlueprints cnb;
		FieldNodeBlueprints fnb;

	public:
		explicit TileBlueprint(const char * n, int r, bool c, SideBlueprint s0, SideBlueprint s1, SideBlueprint s2, SideBlueprint s3, int nbOfRoadNodes, RoadNodeBlueprint rnb_src0, RoadNodeBlueprint rnb_src1, RoadNodeBlueprint rnb_src2, RoadNodeBlueprint rnb_src3, int nbOfCityNodes, CityNodeBlueprint cnb_src0, CityNodeBlueprint cnb_src1, int nbOfFieldNodes, FieldNodeBlueprint fnb_src0, FieldNodeBlueprint fnb_src1, FieldNodeBlueprint fnb_src2, FieldNodeBlueprint fnb_src3);
		~TileBlueprint() = default;

		const char * getName() const { return name; }
		bool hasCloister() const { return cloister; }
		int getNumberOfPertinentDirection() const { return rqMax; }

		SideType getSideType(const Direction & d) const { return sides[d.get()].side; }

		int getCityNode(const Direction & d) const { return sides[d.get()].cityNode; }

		int getRoadNode(const Direction & d) const { return sides[d.get()].roadNode; }


		int getFieldNode(const Direction & d) const { return sides[d.get()].fieldNode; }
		int getLeftFieldNode(const Direction & d) const { return sides[d.get()].leftFieldNode; }
		int getRightFieldNode(const Direction & d) const { return sides[d.get()].rightFieldNode; }

		int getNumberOfRoadNodes() const { return rnb.length(); }
		int getNumberOfCityNodes() const { return cnb.length(); }
		int getNumberOfFieldNodes() const { return fnb.length(); }

		const RoadNodeBlueprint & getRoadNodeBlueprint(int i) const { return rnb[i]; }
		const CityNodeBlueprint & getCityNodeBlueprint(int i) const { return cnb[i]; }
		const FieldNodeBlueprint & getFieldNodeBlueprint(int i) const { return fnb[i]; }

		const RoadNodeBlueprints & getRoadNodeBlueprints() const { return rnb; }
		const CityNodeBlueprints & getCityNodeBlueprints() const { return cnb; }
		const FieldNodeBlueprints & getFieldNodeBlueprints() const { return fnb; }


	};

}
