#pragma once
#include "first.h"
#include <vector>
#include "Array.h"
#include "BlocStatic.h"
#include "Position.h"
#include "Cloister.h"

namespace kar {

	class CloisterContainer
	{
	public:
		using Cloisters = Array<Cloister, NUMBER_OF_CLOISTERS>;
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using Logs = std::vector<bool>;

	private:
		Cloisters cloisters;
		Logs logs;
		Scores scores;
		Followers busyFollowers;

	public:
		CloisterContainer() : scores(0), busyFollowers(0) {}
		~CloisterContainer() = default;

		void reachNoCloister(const Position & p);

		template<class UnaryFunction>
		void reachNewCloister(const Position & p, UnaryFunction isOccupied);

		void cancel(const Position & p);

		bool canSetMonk() const;
		void setMonk();
		void cancelMonk();
	};

	void updateCompletenessOfCloisters(const Position & p, Array<Cloister, NUMBER_OF_CLOISTERS>& cloisters, BlocStatic<int, NUMBER_OF_PLAYERS>& scores, BlocStatic<char, NUMBER_OF_PLAYERS>& followers);
	void rollBackCompletenessOfCloisters(const Position & p, Array<Cloister, NUMBER_OF_CLOISTERS>& cloisters, BlocStatic<int, NUMBER_OF_PLAYERS>& scores, BlocStatic<char, NUMBER_OF_PLAYERS>& followers);

	void CloisterContainer::reachNoCloister(const Position & p) {
		updateCompletenessOfCloisters(p, cloisters, scores, busyFollowers);
		logs.push_back(false);
	}

	inline void CloisterContainer::cancel(const Position & p)
	{
		if (logs.back()) {
			const auto & c = cloisters.pop();

			if (c.hasDirectFollower()) {
				scores[c.getDirectFollower()] -= c.score();
				busyFollowers[c.getDirectFollower()]--;
			}
		}

		logs.pop_back();
		rollBackCompletenessOfCloisters(p, cloisters, scores, busyFollowers);
	}

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

	template<class UnaryFunction>
	inline void CloisterContainer::reachNewCloister(const Position & p, UnaryFunction isOccupied)
	{
		updateCompletenessOfCloisters(p, cloisters, scores, busyFollowers);
		logs.push_back(true);

		cloisters.push(Cloister{ p });
		auto & c = cloisters.last();

		const Position ps[8] = { p.east(), p.east().north(), p.east().south(), p.north(), p.west(), p.west().north(), p.west().south(), p.south() };

		for (const auto & p : ps)
			if (isOccupied(p))
				c.incrCompleteness();
	}

}


