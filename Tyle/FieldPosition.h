#pragma once
#include "Direction.h"

namespace kar {

	enum class FieldPosition {
		Center, Right, Left
	};

	struct CompleteFieldPosition {

		Direction direction;
		FieldPosition fieldPosition;

	};

}