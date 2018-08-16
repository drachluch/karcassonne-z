#include "CloisterContainer.h"

namespace kar {

	void updateCompletenessOfCloisters(const Position & p, Array<Cloister, NUMBER_OF_CLOISTERS>& cloisters, BlocStatic<int, NUMBER_OF_PLAYERS>& scores, BlocStatic<char, NUMBER_OF_PLAYERS>& followers) {
		for (auto i = 0; i < cloisters.length(); i++) {
			auto & c = cloisters[i];
			if (c.withinRange(p)) {
				c.incrCompleteness();

				if (c.isCompleted() && c.hasDirectFollower()) {
					scores[c.getDirectFollower()] += c.score();
					followers[c.getDirectFollower()]--;
				}
			}
		}
	}

	void rollBackCompletenessOfCloisters(const Position & p, Array<Cloister, NUMBER_OF_CLOISTERS>& cloisters, BlocStatic<int, NUMBER_OF_PLAYERS>& scores, BlocStatic<char, NUMBER_OF_PLAYERS>& followers) {
		for (auto i = 0; i < cloisters.length(); i++) {
			auto & c = cloisters[i];
			if (c.withinRange(p)) {
				if (c.isCompleted() && c.hasDirectFollower()) {
					scores[c.getDirectFollower()] -= c.score();
					followers[c.getDirectFollower()]--;
				}

				c.decrCompleteness();
			}
		}
	}

	void CloisterContainer::reachNoCloister(const Position & p) {
		updateCompletenessOfCloisters(p, cloisters, scores, busyFollowers);
		logs.push_back(false);
	}

}

