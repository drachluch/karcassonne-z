#pragma once
#include <ostream>

enum class SideType {
	City,
	Road,
	Field
};

std::ostream & operator<<(std::ostream & out, SideType st);

