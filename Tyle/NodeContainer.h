#pragma once
#include "first.h"
#include "Array.h"
#include "BlocStatic.h"
#include "nodeCommun.h"
#include "NodeIterator.h"



namespace kar {

	template<class Node, class Nodes, class NodeBlueprints>
	class NodeContainer {
	public:
		using Index = char;
		using Scores = BlocStatic<int, NUMBER_OF_PLAYERS>;
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Iterator = NodeIterator<Node>;

	private:
		using Logs = Array<char, NUMBER_OF_TILES>;
		Nodes nodes;
		Logs addedNumberOfNodesLogs;
		Scores scores;
		Followers followers;

		template <typename T>
		void unlinkChildren(const T idx);

	public:
		NodeContainer() : scores(0), followers(0) {}
		~NodeContainer() = default;

		void add(const NodeBlueprints & nbs);
		void makeFatherAndSon(const Index idxFather, const Index idxChild);
		void checkForCompletedNodes();
		void cancel();

		void noticeEnd();
		void unnoticeEnd();

		int waysToSetFollower() const;
		auto setFollower(int way, char idxPlayer);
		void cancelFollower(int way);

		Index getIndexOfRoot(const Index idx) const { return nodes[idx].hasFather() ? getIndexOfRoot(nodes[idx].getFather()) : idx; }
		int getLastNumberOfAddedRoads() const { return addedNumberOfNodesLogs.last(); }
		int getNumberOfNodes() const { return nodes.length(); }

		Iterator getIterator() const { return Iterator{ nodes }; }

		inline const Scores & getKnightScores() const { return scores; }
		inline const Followers & getBusyFollowers() const { return followers; }

	};

	template<class Node, class Nodes, class NodeBlueprints>
	inline void NodeContainer<Node, Nodes, NodeBlueprints>::add(const NodeBlueprints & nbs)
	{
		const auto nbOfBlueprints = nbs.length();
		nodes.addLength(nbOfBlueprints);
		addedNumberOfNodesLogs.push(nbOfBlueprints);

		if (nbOfBlueprints == 1)
			nodes.last().reset(nbs[0]);
		else
			if (nbOfBlueprints > 1) {
				const auto first = nodes.length() - nbOfBlueprints;
				const auto ambigiousPosition = addedNumberOfNodesLogs.length();
				for (auto i = 0; i < nbOfBlueprints; i++)
					nodes[first + i].reset(nbs[i], ambigiousPosition);
			}

	}

	template<class Node, class Nodes, class NodeBlueprints>
	inline void NodeContainer<Node, Nodes, NodeBlueprints>::makeFatherAndSon(const Index idxFather, const Index idxChild)
	{
		nodes[idxFather].becomeFatherOf(nodes[idxChild], idxFather, idxChild);
	}

	template<class Node, class Nodes, class NodeBlueprints>
	inline void NodeContainer<Node, Nodes, NodeBlueprints>::checkForCompletedNodes()
	{
		const auto nbNodesChecked = addedNumberOfNodesLogs.last();
		const auto first = nodes.length() - nbNodesChecked;
		// décompte des points pour les routes terminées avec des partisans déjà dessus
		for (auto i = 0; i < nbNodesChecked; i++) {
			const auto & nd = nodes[first + i];
			if (!nd.hasFather() && nd.isCompleted() && nd.hasAnyFollower())
				noticeCompletedNode(nd, scores, followers);
		}
	}

	template<class Node, class Nodes, class NodeBlueprints>
	inline void NodeContainer<Node, Nodes, NodeBlueprints>::cancel()
	{
		const auto nbNodesCanceled = addedNumberOfNodesLogs.pop();
		const auto first = nodes.length() - nbNodesCanceled;
		for (auto i = 0; i < nbNodesCanceled; i++) {
			noticeCanceled(nodes[first + i], scores, followers);
			unlinkChildren(first + i);
		}
		nodes.addLength(-nbNodesCanceled);
	}

	template<class Node, class Nodes, class NodeBlueprints>
	inline void NodeContainer<Node, Nodes, NodeBlueprints>::noticeEnd()
	{
		for (auto i = 0; i < nodes.length(); i++) {
			const auto & nd = nodes[i];
			if (!nd.hasFather() && nd.hasAnyFollower() && !nd.isCompleted())
				noticeUncompletedNodeAtTheEnd(nd, scores);
		}
	}

	template<class Node, class Nodes, class NodeBlueprints>
	inline void NodeContainer<Node, Nodes, NodeBlueprints>::unnoticeEnd()
	{
		for (auto i = 0; i < nodes.length(); i++) {
			const auto & nd = nodes[i];
			if (!nd.hasFather() && nd.hasAnyFollower() && !nd.isCompleted())
				unnoticeUncompletedNodeAtTheEnd(nd, scores);
		}
	}

	template<class Node, class Nodes, class NodeBlueprints>
	inline int NodeContainer<Node, Nodes, NodeBlueprints>::waysToSetFollower() const
	{
		auto ways = 0;
		const auto nbNodesChecked = addedNumberOfNodesLogs.last();
		const auto first = nodes.length() - nbNodesChecked;
		for (auto i = 0; i < nbNodesChecked; i++)
			if (nodes[first + i].canSetFollower())
				ways++;
		return ways;
	}

	template<class Node, class Nodes, class NodeBlueprints>
	inline auto NodeContainer<Node, Nodes, NodeBlueprints>::setFollower(int wayKnight, char idxPlayer)
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

	template<class Node, class Nodes, class NodeBlueprints>
	inline void NodeContainer<Node, Nodes, NodeBlueprints>::cancelFollower(int wayKnight)
	{
		const auto nbNodesChecked = addedNumberOfNodesLogs.last();
		const auto first = nodes.length() - nbNodesChecked;
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

	template<class Node, class Nodes, class NodeBlueprints>
	template<typename T>
	inline void NodeContainer<Node, Nodes, NodeBlueprints>::unlinkChildren(const T idx)
	{
		for (auto i : nodes[idx].getSons())
			nodes[i].setNoFather();
	}
}



