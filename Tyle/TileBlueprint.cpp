#include "TileBlueprint.h"
#include <string>

TileBlueprint::TileBlueprint(const char * n, int r, bool c, SideBlueprint s0, SideBlueprint s1, SideBlueprint s2, SideBlueprint s3, int nbOfRoadNodes, RoadNodeBlueprint rnb_src0, RoadNodeBlueprint rnb_src1, RoadNodeBlueprint rnb_src2, RoadNodeBlueprint rnb_src3, int nbOfCityNodes, CityNodeBlueprint cnb_src0, CityNodeBlueprint cnb_src1, int nbOfFieldNodes, FieldNodeBlueprint fnb_src0, FieldNodeBlueprint fnb_src1, FieldNodeBlueprint fnb_src2, FieldNodeBlueprint fnb_src3)
	: name(n), cloister(c), rqMax(r), numberOfRoadNodes(nbOfRoadNodes), numberOfCityNodes(nbOfCityNodes), numberOfFieldNodes(nbOfFieldNodes)
{
	sides[0] = s0;
	sides[1] = s1;
	sides[2] = s2;
	sides[3] = s3;
	
	rnb[0] = rnb_src0;
	rnb[1] = rnb_src1;
	rnb[2] = rnb_src2;
	rnb[3] = rnb_src3;

	cnb[0] = cnb_src0;
	cnb[1] = cnb_src1;

	fnb[0] = fnb_src0;
	fnb[1] = fnb_src1;
	fnb[2] = fnb_src2;
	fnb[3] = fnb_src3;

}

