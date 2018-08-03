#pragma once
#include <ostream>
#include "Direction.h"

struct Position
{
	int x = 0;
	int y = 0;

	Position() = default;
	Position(int xx, int yy) : x(xx), y(yy) {}
	Position(const Position & p) = default;
	~Position() = default;

	bool operator==(const Position & right) const  { return x == right.x && y == right.y; }

	Position east() const  { return Position{ x + 1, y }; }
	Position north() const  { return Position{ x, y - 1 }; }
	Position west() const  { return Position{ x - 1, y }; }
	Position south() const  { return Position{ x, y + 1 }; }

	Position next(const Direction & d) const  {
		switch (d.get()) {
		case 0: return Position{ x + 1, y };
		case 1: return Position{ x, y - 1 };
		case 2: return Position{ x - 1, y };
		default: return Position{ x, y + 1 };
		}
	}

	bool withinOneRange(const Position & p) const  { return x <= p.x + 1 && x >= p.x - 1 && y <= p.y + 1 && y >= p.y - 1 && !(x == p.x && y == p.y); }

};

std::ostream & operator<<(std::ostream & out, const Position & p);
