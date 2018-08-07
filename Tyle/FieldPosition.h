#pragma once
#include "Direction.h"

enum class FieldPosition {
	Center, Right, Left
};

struct CompleteFieldPosition {

	Direction direction;
	FieldPosition fieldPosition;

};

