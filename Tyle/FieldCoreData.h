#pragma once
#include "first.h"
#include "BlocStatic.h"
#include <vector>

namespace kar {

	struct FieldCoreData
	{
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Neighbors = std::vector<char>;

		Followers followers;
		Neighbors neighbors;

		FieldCoreData() : followers(0) {}
		~FieldCoreData() = default;

		void free_followers(Followers& workingFollowers) const { workingFollowers -= followers; }
		void get_back_followers(Followers& workingFollowers) const { workingFollowers += followers; }

		const Neighbors& getNeighbors() const { return neighbors; }
		Neighbors& getNeighbors() { return neighbors; }
	};


}
