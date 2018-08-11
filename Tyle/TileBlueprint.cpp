#include "TileBlueprint.h"
#include <string>

namespace kar {

	TileBlueprint::TileBlueprint(const char * n, int r, bool c, SideBlueprint s0, SideBlueprint s1, SideBlueprint s2, SideBlueprint s3, int nbOfRoadNodes, RoadNodeBlueprint rnb_src0, RoadNodeBlueprint rnb_src1, RoadNodeBlueprint rnb_src2, RoadNodeBlueprint rnb_src3, int nbOfCityNodes, CityNodeBlueprint cnb_src0, CityNodeBlueprint cnb_src1, int nbOfFieldNodes, FieldNodeBlueprint fnb_src0, FieldNodeBlueprint fnb_src1, FieldNodeBlueprint fnb_src2, FieldNodeBlueprint fnb_src3)
		: name(n), cloister(c), rqMax(r)
	{
		sides[0] = s0;
		sides[1] = s1;
		sides[2] = s2;
		sides[3] = s3;

		if (nbOfRoadNodes > 0) rnb.push(rnb_src0);
		if (nbOfRoadNodes > 1) rnb.push(rnb_src1);
		if (nbOfRoadNodes > 2) rnb.push(rnb_src2);
		if (nbOfRoadNodes > 3) rnb.push(rnb_src3);

		if (nbOfCityNodes > 0) cnb.push(cnb_src0);
		if (nbOfCityNodes > 1) cnb.push(cnb_src1);

		if (nbOfFieldNodes > 0) fnb.push(fnb_src0);
		if (nbOfFieldNodes > 1) fnb.push(fnb_src1);
		if (nbOfFieldNodes > 2) fnb.push(fnb_src2);
		if (nbOfFieldNodes > 3) fnb.push(fnb_src3);

	}

}
