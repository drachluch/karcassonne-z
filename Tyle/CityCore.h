#pragma once
#include "first.h"
#include "BlocStatic.h"
#include "CityNodeBlueprint.h"
#include <vector>

namespace kar {
	class CityCore
	{
	public:
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using AmbigiousPositions = std::vector<char>;
		using NodeBlueprint = CityNodeBlueprint;

	private:
		Followers followers;
		char garbageFollower = -2;
		AmbigiousPositions ambigiousPositions;

		char coveredArea = 1;
		char holes = 0;
		char crest = 0;

	public:
		CityCore() : followers(0) {}
		~CityCore() = default;

		void reset(const NodeBlueprint& nb);
		void reset(const NodeBlueprint& nb, char ambigiousPosition);

		void assimilate(const CityCore& cc);

		bool hasAnyFollower() const { return garbageFollower > -2; }
		bool hasDirectFollower() const { return garbageFollower > -1; }
		int getDirectFollower() const { return garbageFollower; }
		void setDirectFollower(char idxPlayer) { garbageFollower = idxPlayer; followers[idxPlayer] = 1; }
		void setNoDirectFollower() { followers[garbageFollower] = 0; garbageFollower = -2; }

		char getUncompleteness() const { return holes; }
		const Followers& getFollowers() const { return followers; }

		int score() const { return (isCompleted() ? 2 : 1) * (coveredArea + crest); }
		bool isCompleted() const { return holes == 0; }
		

		bool isNotWorth() const { return isCompleted(); }

		void give_points(Scores& scores) const;
		void take_back_points(Scores& scores) const;
		void free_followers(Followers& workingFollowers) const { workingFollowers -= followers; }
		void get_back_followers(Followers& workingFollowers) const { workingFollowers += followers; }
	};

	inline void CityCore::reset(const NodeBlueprint & nb)
	{
		garbageFollower = -2;
		followers.reset(0);
		coveredArea = 1;
		holes = nb.getNumberOfHoles();
		crest = nb.hasCrest() ? 1 : 0;
		ambigiousPositions.clear();
	}

	inline void CityCore::reset(const NodeBlueprint & nb, char ambigiousPosition)
	{
		reset(nb);
		ambigiousPositions.push_back(ambigiousPosition);
	}

	inline void CityCore::give_points(Scores & scores) const
	{
		const auto maxF = followers.max();
		if (maxF > 0) {
			const auto points = score();
			for (auto i = 0; i < NUMBER_OF_PLAYERS; i++)
				if (followers[i] == maxF)
					scores[i] += points;
		}
	}

	inline void CityCore::take_back_points(Scores & scores) const
	{
		const auto maxF = followers.max();
		if (maxF > 0) {
			const auto points = score();
			for (auto i = 0; i < NUMBER_OF_PLAYERS; i++)
				if (followers[i] == maxF)
					scores[i] -= points;
		}
	}
}
