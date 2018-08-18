#pragma once
#include "first.h"
#include "nodeCommun.h"

#include "Array.h"
#include "BlocStatic.h"
#include "City.h"
#include "TileBlueprint.h"
#include "CityIterator.h"


namespace kar {
	class CityContainer {
	public:
		using Node = City;
		using Index = City::Index;
		using Nodes = Array<Node, NUMBER_OF_CITYNODES>;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Logs = Array<char, NUMBER_OF_TILES>;

	private:
		Nodes nodes;
		Logs addedNumberOfNodesLogs;
		Scores scores;
		Followers followers;

		template <typename T>
		void unlinkChildren(const T idx);

	public:
		CityContainer() : scores(0), followers(0) {}
		~CityContainer() = default;

		void add(const TileBlueprint::CityNodeBlueprints & cnbs);
		void makeFatherAndSon(const Index idxFather, const Index idxChild);
		void checkForCompletedNodes();
		void cancel();

		void noticeEnd();
		void unnoticeEnd();

		int waysToSetFollower() const;
		Index setFollower(int wayKnight, char idxPlayer);
		void cancelFollower(int wayKnight);

		Index getIndexOfRoot(const Index idx) const;
		const City& getRoot(const Index idx) const;

		int getLastNumberOfAddedNodes() const { return addedNumberOfNodesLogs.last(); }
		int getNumberOfNodes() const { return nodes.length(); }

		CityIterator getIterator() const { return CityIterator{ nodes }; }

		inline const Scores & getKnightScores() const { return scores; }
		inline const Followers & getBusyFollowers() const { return followers; }

	};

	inline void CityContainer::add(const TileBlueprint::CityNodeBlueprints & cnbs)
	{
		nodes.addLength(cnbs.length());
		addedNumberOfNodesLogs.push(cnbs.length());

		if (cnbs.length() == 1) {
			const auto & cnb = cnbs[0];
			nodes.last().reset(cnb.getNumberOfHoles(), cnb.hasCrest());
		} else
			if (cnbs.length() > 1) {
				const auto first = nodes.length() - cnbs.length();
				const auto ambigiousPosition = addedNumberOfNodesLogs.length();
				for (auto i = 0; i < cnbs.length(); i++) {
					const auto & cnb = cnbs[i];
					nodes[first + i].reset(cnb.getNumberOfHoles(), cnb.hasCrest(), ambigiousPosition);
				}
			}

	}

	inline void CityContainer::makeFatherAndSon(const Index idxFather, const Index idxChild)
	{
		nodes[idxFather].becomeFatherOf(nodes[idxChild], idxFather, idxChild);
	}

	inline void CityContainer::checkForCompletedNodes()
	{
		auto nbNodesChecked = addedNumberOfNodesLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		// décompte des points pour les routes terminées avec des partisans déjà dessus
		for (auto i = 0; i < nbNodesChecked; i++) {
			const auto & nd = nodes[first + i];
			if (!nd.hasFather() && nd.isCompleted() && nd.hasAnyFollower())
				noticeCompletedNode(nd, scores, followers);
		}
	}

	inline void CityContainer::cancel()
	{
		auto nbNodesCanceled = addedNumberOfNodesLogs.pop();
		auto first = nodes.length() - nbNodesCanceled;
		for (auto i = 0; i < nbNodesCanceled; i++) {
			noticeCanceled(nodes[first + i], scores, followers);
			unlinkChildren(first + i);
		}
		nodes.addLength(-nbNodesCanceled);
	}

	inline void CityContainer::noticeEnd()
	{
		for (auto i = 0; i < nodes.length(); i++) {
			const auto & nd = nodes[i];
			if (!nd.hasFather() && nd.hasAnyFollower() && !nd.isCompleted())
				noticeUncompletedNodeAtTheEnd(nd, scores);
		}
	}

	inline void CityContainer::unnoticeEnd()
	{
		for (auto i = 0; i < nodes.length(); i++) {
			const auto & nd = nodes[i];
			if (!nd.hasFather() && nd.hasAnyFollower() && !nd.isCompleted())
				unnoticeUncompletedNodeAtTheEnd(nd, scores);
		}
	}

	inline int CityContainer::waysToSetFollower() const
	{
		auto ways = 0;
		auto nbNodesChecked = addedNumberOfNodesLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		for (auto i = 0; i < nbNodesChecked; i++)
			if (nodes[first + i].canSetFollower())
				ways++;
		return ways;
	}

	inline CityContainer::Index CityContainer::setFollower(int wayKnight, char idxPlayer)
	{
		const auto nbNodesChecked = addedNumberOfNodesLogs.last();
		const auto first = nodes.length() - nbNodesChecked;
		auto ways = 0;

		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & rn = nodes[first + i];
			if (rn.canSetFollower()) {
				if (ways == wayKnight) {
					noticeDirectFollower(rn, idxPlayer, scores, followers);
					return first + i;
				}
				ways++;
			}
		}
		throw "communism is a lie";
	}

	inline void CityContainer::cancelFollower(int wayKnight)
	{
		auto nbNodesChecked = addedNumberOfNodesLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		auto ways = 0;

		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & nd = nodes[first + i];
			if (nd.canSetFollower()) {
				if (ways == wayKnight) {
					unnoticeDirectFollower(nd, scores, followers);
					return;
				}
				ways++;
			}
		}
	}

	inline CityContainer::Index CityContainer::getIndexOfRoot(const Index idx) const
	{
		auto currentIdx = idx;
		for (; nodes[currentIdx].hasFather(); currentIdx = nodes[currentIdx].getFather());
		return currentIdx;
	}

	inline const City & CityContainer::getRoot(const Index idx) const
	{
		return nodes[getIndexOfRoot(idx)];
	}

	template<typename T>
	inline void CityContainer::unlinkChildren(const T idx)
	{
		for (auto i : nodes[idx].getSons())
			nodes[i].setNoFather();
	}
}