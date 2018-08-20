#pragma once
#include "CityNodeBlueprint.h"
#include "Followers.h"
#include "Scores.h"

namespace kar {

	struct CityCoreData {

		Followers followers;
		char coveredArea = 1;
		char holes = 0;
		char crest = 0;

		CityCoreData() : followers(0) {}
		~CityCoreData() = default;

		void reset(const CityNodeBlueprint& nb) {
			followers.reset(0);
			coveredArea = 1;
			holes = nb.getNumberOfHoles();
			crest = nb.hasCrest() ? 1 : 0;
		}
		int score() const { return (holes == 0 ? 2 : 1) * (coveredArea + crest); }
		bool isCompleted() const { return holes == 0; }
		void give_points(Scores & scores) const {
			const auto maxF = followers.max();
			if (maxF > 0) {
				const auto points = score();
				for (auto i = 0; i < followers.length(); i++)
					if (followers[i] == maxF)
						scores[i] += points;
			}
		}
		void take_back_points(Scores & scores) const {
			const auto maxF = followers.max();
			if (maxF > 0) {
				const auto points = score();
				for (auto i = 0; i < followers.length(); i++)
					if (followers[i] == maxF)
						scores[i] -= points;
			}
		}
		void free_followers(Followers & workingFollowers) const { workingFollowers -= followers; }
		void get_back_followers(Followers & workingFollowers) const { workingFollowers += followers; }
	};
}



