#include "Neighborhood.h"
#include <algorithm>
#include "Field.h"

void setNeighborCities(const kar::FieldContainer& fc, kar::Field& node, const kar::FieldNodeBlueprint& fnb, const kar::CityContainer& cc) {
	auto & neighbors = node.getCoreData().getNeighbors();
	neighbors.clear();

	{
		const auto firstCity = cc.getNumberOfNodes() - cc.getLastNumberOfAddedNodes();
		auto relativIdxCity = fnb.getAdjacentCityNodes();
		for (auto i = 0; i < fnb.getNumberAdjacentCityNodes(); i++)
			neighbors.push_back(cc.getIndexOfRoot(firstCity + relativIdxCity[i]));
	}
	{
		for (auto & idxSon : node.getSons())
			for (auto idxCity : fc.getNode(idxSon).getCoreData().getNeighbors())
				neighbors.push_back(cc.getIndexOfRoot(idxCity));
	}

	std::sort(neighbors.begin(), neighbors.end());
	std::unique(neighbors.begin(), neighbors.end());

}

struct DepthAndIndex {
	int idx = 0;
	int depth = 0;
};

void kar::setNeighbors_OfManyFields(kar::FieldContainer& fc, const kar::TileBlueprint::FieldNodeBlueprints& fnbs, const kar::CityContainer& cc) {
	const auto nbFields = fc.getLastNumberOfAddedNodes();
	const auto firstField = fc.getNumberOfNodes() - nbFields;
	
	std::vector<DepthAndIndex> depths;
	depths.resize(nbFields);
	for (auto i = 0; i < nbFields; i++)
		depths[i] = DepthAndIndex{ firstField + i, fc.depth(firstField + i) };

	std::sort(depths.begin(), depths.end(), [](const DepthAndIndex & left, const DepthAndIndex & right) { return left.depth > right.depth; });

	for (const DepthAndIndex& dd : depths)
		setNeighborCities(fc, fc.getNode(dd.idx), fnbs[dd.idx - firstField], cc);
}

kar::BlocStatic<int, NUMBER_OF_PLAYERS> kar::countEndFarmerScore(const FieldContainer & fc, const CityContainer & cc)
{
	BlocStatic<int, NUMBER_OF_PLAYERS> scores(0);

	for (auto it = fc.getIterator(); it.isNotOver(); ++it) {
		const auto & core = it.getCore();
		const auto maxF = core.followers.max();

		if (maxF > 0) {
			std::vector<char> temp;
			temp.reserve(core.neighbors.size());
			for (const auto idx : core.neighbors)
				temp.push_back(cc.getIndexOfRoot(idx));

			std::sort(temp.begin(), temp.end());
			std::unique(temp.begin(), temp.end());

			auto participation = 0;
			for (const auto idx : temp)
				if (cc.getRoot(idx).isCompleted())
					participation += 3;
			
			for (auto i = 0; i < NUMBER_OF_PLAYERS; i++)
				if (core.followers[i] == maxF)
					scores[i] += participation;
		}
	}
	
	return scores;
}


