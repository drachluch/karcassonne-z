#include "Position.h"

std::ostream & operator<<(std::ostream & out, const Position & p) { return out << "{x:" << p.x << ",y:" << p.y << "}"; }

