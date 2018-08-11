#include "Position.h"
namespace kar {
	std::ostream & operator<<(std::ostream & out, const Position & p) { return out << "{x:" << p.x << ",y:" << p.y << "}"; }
}


