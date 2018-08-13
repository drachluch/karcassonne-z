#pragma once
#include "first.h"
#include "BlocStatic.h"

namespace kar {
	struct RoadCoreData {
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;

		Followers followers;
		char coveredArea = 1;
		char holes = 1;

		RoadCoreData() : followers(0) {}
		~RoadCoreData() = default;

		int score() const { return coveredArea; }
		bool isCompleted() const { return holes == 0; }
		void give_points(Scores & scores) const {
			const auto maxF = followers.max();
			if (maxF > 0) {
				const auto points = score();
				for (auto i = 0; i < NUMBER_OF_PLAYERS; i++)
					if (followers[i] == maxF)
						scores[i] += points;
			}
		}
		void take_back_points(Scores & scores) const {
			const auto maxF = followers.max();
			if (maxF > 0) {
				const auto points = score();
				for (auto i = 0; i < NUMBER_OF_PLAYERS; i++)
					if (followers[i] == maxF)
						scores[i] -= points;
			}
		}
		void free_followers(Followers & workingFollowers) const { workingFollowers -= followers; }
		void get_back_followers(Followers & workingFollowers) const { workingFollowers += followers; }
	};
}