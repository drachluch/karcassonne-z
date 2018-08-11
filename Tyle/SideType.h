#pragma once
#include <ostream>

namespace kar {

	enum class SideType {
		City,
		Road,
		Field
	};

	std::ostream & operator<<(std::ostream & out, SideType st);

}