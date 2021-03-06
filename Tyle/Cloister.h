#pragma once
#include "Position.h"

namespace kar {

	struct Cloister
	{
		Position p;
		signed char completeness = 1;
		signed char directFollower = -1;

		Cloister() = default;
		Cloister(const Position & p_) : p(p_) {}
		~Cloister() = default;

		Cloister & operator=(const Cloister &) = default;

		bool hasDirectFollower() const { return directFollower != -1; }
		signed char getDirectFollower() const { return directFollower; }
		bool isCompleted() const { return completeness == 9; }
		int score() const { return completeness; }
		const Position & getPosition() const { return p; }



		bool withinRange(const Position & q) const { return p.withinOneRange(q); }
		void setPosition(const Position q) { p = q; }
		void setDirectFollower(signed char faction) { directFollower = faction; }
		void setNoDirectFollower() { directFollower = -1; }
		void incrCompleteness() { completeness++; }
		void decrCompleteness() { completeness--; }

	};

}