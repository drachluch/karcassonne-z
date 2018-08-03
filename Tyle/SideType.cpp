#include "SideType.h"


std::ostream & operator<<(std::ostream & out, SideType st) {
	switch (st) {
	case SideType::Road:
		return out << "road";
	case SideType::City:
		return out << "city";
	case SideType::Field:
		return out << "field";
	}
	return out;
}
