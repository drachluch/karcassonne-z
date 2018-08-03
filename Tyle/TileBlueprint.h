#pragma once
#include "SideType.h"
#include "Direction.h"
#include "RoadNodeBlueprint.h"
#include "CityNodeBlueprint.h"
#include "FieldNodeBlueprint.h"

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

	const char * name;
	SideBlueprint sides[4];
	int rqMax;

	bool cloister;

	int numberOfRoadNodes;
	int numberOfCityNodes;
	int numberOfFieldNodes;

	RoadNodeBlueprint rnb[4];
	CityNodeBlueprint cnb[2];
	FieldNodeBlueprint fnb[4];

public:
	explicit TileBlueprint(const char * n, int r, bool c, SideBlueprint s0, SideBlueprint s1, SideBlueprint s2, SideBlueprint s3, int nbOfRoadNodes, RoadNodeBlueprint rnb_src0, RoadNodeBlueprint rnb_src1, RoadNodeBlueprint rnb_src2, RoadNodeBlueprint rnb_src3, int nbOfCityNodes, CityNodeBlueprint cnb_src0, CityNodeBlueprint cnb_src1, int nbOfFieldNodes, FieldNodeBlueprint fnb_src0, FieldNodeBlueprint fnb_src1, FieldNodeBlueprint fnb_src2, FieldNodeBlueprint fnb_src3);
	~TileBlueprint() = default;

	const char * getName() const  { return name; }
	bool hasCloister() const  { return cloister; }
	int getNumberOfPertinentDirection() const  { return rqMax; }

	SideType getSideType(const Direction & d) const  { return sides[d.get()].side; }

	int getCityNode(const Direction & d) const  { return sides[d.get()].cityNode; }
	
	int getRoadNode(const Direction & d) const  {
		return sides[d.get()].roadNode;
	}


	int getFieldNode(const Direction & d) const  { return sides[d.get()].fieldNode; }
	int getLeftFieldNode(const Direction & d) const  { return sides[d.get()].leftFieldNode; }
	int getRightFieldNode(const Direction & d) const  { return sides[d.get()].rightFieldNode; }

	int getNumberOfRoadNodes() const { return numberOfRoadNodes; }
	int getNumberOfCityNodes() const { return numberOfCityNodes; }
	int getNumberOfFieldNodes() const { return numberOfFieldNodes; }

	const RoadNodeBlueprint & getRoadNodeBlueprint(int i) const {
		return rnb[i];
	}
	const CityNodeBlueprint & getCityNodeBlueprint(int i) const { return cnb[i]; }
	const FieldNodeBlueprint & getFieldNodeBlueprint(int i) const { return fnb[i]; }


};

