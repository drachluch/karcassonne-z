#pragma once
#include "Array.h"
#include "TileBlueprint.h"
#include "Road.h"
#include "RoadIterator.h"
#include "first.h"

namespace kar {

	class RoadContainer {
	public:
		using Node = Road;
		using Index = Road::Index;
		using Nodes = Array<Node, NUMBER_OF_ROADNODES>;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Logs = Array<char, NUMBER_OF_TILES>;

	private:
		Nodes nodes;
		Logs addedNumberOfRoadsLogs;
		Scores scores;
		Followers followers;

		template <typename T>
		void unlinkChildren(const T idx);
		
	public:
		RoadContainer() : scores(0), followers(0) {}
		~RoadContainer() = default;

		void add(const TileBlueprint::RoadNodeBlueprints & rnbs);
		void makeFatherAndSon(const Index idxFather, const Index idxChild);
		void checkForCompletedNodes();
		void cancel();

		void noticeEnd();
		void unnoticeEnd();

		int waysToSetFollower() const;
		Index setFollower(int wayThief, char idxPlayer);
		void cancelFollower(int wayThief);

		Index getIndexOfRoot(const Index idx) const { return nodes[idx].hasFather() ? getIndexOfRoot(nodes[idx].getFather()) : idx; }
		int getLastNumberOfAddedRoads() const { return addedNumberOfRoadsLogs.last(); }
		int getNumberOfNodes() const { return nodes.length(); }

		RoadIterator getIterator() const { return RoadIterator{nodes}; }

		inline const Scores & getThiefScores() const { return scores; }
		inline const Followers & getBusyFollowers() const { return followers; }

	};

	

	inline void RoadContainer::add(const TileBlueprint::RoadNodeBlueprints & rnbs)
	{
		nodes.addLength(rnbs.length());
		addedNumberOfRoadsLogs.push(rnbs.length());

		if (rnbs.length() == 1)
			nodes.last().reset(rnbs[0].getNumberOfHoles());
		else
			if (rnbs.length() > 1) {
				const auto first = nodes.length() - rnbs.length();
				for (auto i = 0; i < rnbs.length(); i++)
					nodes[first + i].reset(rnbs[i].getNumberOfHoles(), addedNumberOfRoadsLogs.length());
			}
	}

	inline void RoadContainer::makeFatherAndSon(const Index idxFather, const Index idxChild)
	{
		nodes[idxFather].becomeFatherOf(nodes[idxChild], idxFather, idxChild);
	}

	inline void RoadContainer::checkForCompletedNodes()
	{
		auto nbNodesChecked = addedNumberOfRoadsLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		// décompte des points pour les routes terminées avec des partisans déjà dessus
		for (auto i = 0; i < nbNodesChecked; i++) {
			const auto & rn = nodes[first + i];
			const auto & core = rn.getCoreData();
			if (!rn.hasFather() && core.isCompleted() && rn.hasAnyFollower()) {
				core.give_points(scores);
				core.free_followers(followers);
			}
		}
	}

	// nbNodes > 0
	inline void RoadContainer::cancel()
	{
		auto nbNodesCanceled = addedNumberOfRoadsLogs.pop();
		auto first = nodes.length() - nbNodesCanceled;
		for (auto i = 0; i < nbNodesCanceled; i++) {
			nodes[first + i].cancel(scores, followers);
			unlinkChildren(first + i);
		}
		nodes.addLength(-nbNodesCanceled);
	}

	inline void RoadContainer::noticeEnd()
	{
		for (auto i = 0; i < nodes.length(); i++) {
			const auto & nd = nodes[i];
			if (!nd.hasFather() && nd.hasAnyFollower() && !nd.isCompleted())
				nd.noticeUncompletedNodeAtTheEnd(scores);
		}
	}

	inline void RoadContainer::unnoticeEnd()
	{
		for (auto i = 0; i < nodes.length(); i++) {
			const auto & nd = nodes[i];
			if (!nd.hasFather() && nd.hasAnyFollower() && !nd.isCompleted())
				nd.unnoticeUncompletedNodeAtTheEnd(scores);
		}
	}

	inline int RoadContainer::waysToSetFollower() const
	{
		auto ways = 0;
		auto nbNodesChecked = addedNumberOfRoadsLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		for (auto i = 0; i < nbNodesChecked; i++) {
			const auto & nd = nodes[first + i];
			if (nd.canSetFollower())
				ways++;
		}
		return ways;
	}

	inline RoadContainer::Index RoadContainer::setFollower(int wayThief, char idxPlayer)
	{
		const auto nbNodesChecked = addedNumberOfRoadsLogs.last();
		const auto first = nodes.length() - nbNodesChecked;
		auto ways = 0;

		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & rn = nodes[first + i];
			if (rn.canSetFollower()) {
				if (ways == wayThief) {
					rn.noticeDirectFollower(idxPlayer, scores, followers);
					return first + i;
				}
				ways++;
			}
		}
	}

	inline void RoadContainer::cancelFollower(int wayThief)
	{
		auto nbNodesChecked = addedNumberOfRoadsLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		auto ways = 0;

		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & rn = nodes[first + i];
			if (rn.canSetFollower()) {
				if (ways == wayThief) {
					rn.unnoticeDirectFollower(scores, followers);
					return;
				}
				ways++;
			}
		}
	}

	template<typename T>
	inline void RoadContainer::unlinkChildren(const T idx)
	{
		for (auto i : nodes[idx].getSons())
			nodes[i].setNoFather();
	}

	
}
