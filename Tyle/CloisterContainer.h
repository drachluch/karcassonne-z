#pragma once
#include "first.h"
#include <vector>
#include "Array.h"
#include "Position.h"
#include "Cloister.h"
#include "CloisterIterator.h"

#include "Followers.h"
#include "Scores.h"

namespace kar {

	class CloisterContainer
	{
	public:
		using Cloisters = Array<Cloister, NUMBER_OF_CLOISTERS>;
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

		bool canSetMonk() const { return logs.back(); }
		void setMonk(const char idxPlayer);
		void cancelMonk();

		void noticeEnd();
		void unnoticeEnd();

		CloisterIterator getIterator() const { return CloisterIterator{ cloisters }; }

		inline const Scores & getMonkScores() const { return scores; }
		inline const Followers & getBusyFollowers() const { return busyFollowers; }
	};

	void updateCompletenessOfCloisters(const Position & p, Array<Cloister, NUMBER_OF_CLOISTERS>& cloisters, Scores& scores, Followers& followers);
	void rollBackCompletenessOfCloisters(const Position & p, Array<Cloister, NUMBER_OF_CLOISTERS>& cloisters, Scores& scores, Followers& followers);

	

	inline void CloisterContainer::cancel(const Position & p)
	{
		if (logs.back()) {
			const auto & c = cloisters.pop();

			if (c.hasDirectFollower()) {
				if (c.isCompleted()) {
					scores[c.getDirectFollower()] -= c.score();
				} else {
					busyFollowers[c.getDirectFollower()]--;
				}
			}
		}

		logs.pop_back();
		rollBackCompletenessOfCloisters(p, cloisters, scores, busyFollowers);
	}

	inline void CloisterContainer::setMonk(const char indexPlayer)
	{
		auto & c = cloisters.last();

		c.setDirectFollower(indexPlayer);
		if (c.isCompleted())
			scores[indexPlayer] += c.score();
		else
			busyFollowers[indexPlayer]++;
	}

	inline void CloisterContainer::cancelMonk()
	{
		auto & c = cloisters.last();

		const auto indexPlayer = c.getDirectFollower();
		c.setNoDirectFollower();
		if (c.isCompleted())
			scores[indexPlayer] -= c.score();
		else
			busyFollowers[indexPlayer]--;
	}

	inline void CloisterContainer::noticeEnd()
	{
		for (auto it = getIterator(); it.isNotOver(); ++it) {
			const auto & c = it.getCore();
			scores[c.getDirectFollower()] += c.score();
		}
	}

	inline void CloisterContainer::unnoticeEnd()
	{
		for (auto it = getIterator(); it.isNotOver(); ++it) {
			const auto & c = it.getCore();
			scores[c.getDirectFollower()] -= c.score();
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


