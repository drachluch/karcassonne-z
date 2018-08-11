#pragma once
#include "Position.h"
#include "Game.h"
#include <ostream>

namespace kar {


	struct Bounds {
		int xmax; int xmin; int ymax; int ymin;
		void update(const Position & p) { if (p.x < xmin) xmin = p.x; else if (p.x > xmax) xmax = p.x; if (p.y < ymin) ymin = p.y; else if (p.y > ymax) ymax = p.y; }
	};



	void writeCurrentState(std::ostream & out, const Game & g);
	void writeHTMLHeader(std::ostream & out);

	void writeFollowers(std::ostream & out, const Game & g);

}




