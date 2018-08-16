#pragma once
#include "NodeIterator.h"
#include "first.h"
#include "Array.h"
#include "City.h"

namespace kar {
	using CityIterator = NodeIterator<Array<City, NUMBER_OF_CITYNODES>>;
}