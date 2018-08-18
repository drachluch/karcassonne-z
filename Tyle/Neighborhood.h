#pragma once
#include <vector>
#include "FieldContainer.h"
#include "CityContainer.h"
#include "TileBlueprint.h"

namespace kar {
	void setNeighbors_OfManyFields(FieldContainer& fc, const TileBlueprint::FieldNodeBlueprints& fnbs, const CityContainer& cc);
	
	BlocStatic<int, NUMBER_OF_PLAYERS> countEndFarmerScore(const FieldContainer& fc, const CityContainer& cc);
}