#pragma once
#include "Array.h"
#include "TileBlueprint.h"
#include "Field.h"
#include "FieldIterator.h"
#include "first.h"


namespace kar {

	

	class FieldContainer {
	public:
		using Node = Field;
		using Index = char;
		using Nodes = Array<Node, NUMBER_OF_FIELDNODES>;
		using Followers = BlocStatic<char, NUMBER_OF_PLAYERS>;
		using Logs = Array<char, NUMBER_OF_TILES>;
		using NodeBlueprints = TileBlueprint::FieldNodeBlueprints;

	private:
		Nodes nodes;
		Logs addedNumberOfNodesLogs;
		Followers followers;

		template <typename T>
		void unlinkChildren(const T idx);

	public:
		FieldContainer() : followers(0) {}
		~FieldContainer() = default;

		void add(const NodeBlueprints & rnbs);
		void makeFatherAndSon(const Index idxFather, const Index idxChild);
		void cancel();

		int waysToSetFollower() const;
		Index setFollower(int way, char idxPlayer);
		void cancelFollower(int way);

		Index getIndexOfRoot(const Index idx) const { return nodes[idx].hasFather() ? getIndexOfRoot(nodes[idx].getFather()) : idx; }
		int getLastNumberOfAddedNodes() const { return addedNumberOfNodesLogs.last(); }
		int getNumberOfNodes() const { return nodes.length(); }

		FieldIterator getIterator() const { return FieldIterator{ nodes }; }
		Node & getNode(const Index idx) { return nodes[idx]; }
		const Node & getNode(const Index idx) const { return nodes[idx]; }

		inline const Followers & getBusyFollowers() const { return followers; }

		int depth(const Index idx) const {
			auto step = 0;
			for (auto currentIdx = idx; nodes[currentIdx].hasFather(); currentIdx = nodes[currentIdx].getFather(), step++);
			return step;
		}

	};



	inline void FieldContainer::add(const NodeBlueprints & rnbs)
	{
		const auto nbNewNodes = rnbs.length();
		const auto first = nodes.length();
		nodes.addLength(nbNewNodes);
		addedNumberOfNodesLogs.push(nbNewNodes);
		for (auto i = 0; i < nbNewNodes; i++)
			nodes[first + i].reset();
	}

	inline void FieldContainer::makeFatherAndSon(const Index idxFather, const Index idxChild)
	{
		nodes[idxFather].becomeFatherOf(nodes[idxChild], idxFather, idxChild);
	}

	// nbNodes > 0
	inline void FieldContainer::cancel()
	{
		const auto nbNodesCanceled = addedNumberOfNodesLogs.pop();
		const auto first = nodes.length() - nbNodesCanceled;
		for (auto i = 0; i < nbNodesCanceled; i++) {
			noticeCanceled(nodes[first + i], followers);
			unlinkChildren(first + i);
		}
		nodes.addLength(-nbNodesCanceled);
	}

	inline int FieldContainer::waysToSetFollower() const
	{
		auto ways = 0;
		const auto nbNodesChecked = addedNumberOfNodesLogs.last();
		const auto first = nodes.length() - nbNodesChecked;
		for (auto i = 0; i < nbNodesChecked; i++)
			if (nodes[first + i].canSetFollower())
				ways++;
		return ways;
	}

	inline FieldContainer::Index FieldContainer::setFollower(int way, char idxPlayer)
	{
		const auto nbNodesChecked = addedNumberOfNodesLogs.last();
		const auto first = nodes.length() - nbNodesChecked;
		auto ways = 0;

		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & rn = nodes[first + i];
			if (rn.canSetFollower()) {
				if (ways == way) {
					noticeDirectFollower(rn, idxPlayer, followers);
					return first + i;
				}
				ways++;
			}
		}
		throw "communism is a lie";
	}

	inline void FieldContainer::cancelFollower(int wayThief)
	{
		const auto nbNodesChecked = addedNumberOfNodesLogs.last();
		const auto first = nodes.length() - nbNodesChecked;
		auto ways = 0;

		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & rn = nodes[first + i];
			if (rn.canSetFollower()) {
				if (ways == wayThief) {
					unnoticeDirectFollower(rn, followers);
					return;
				}
				ways++;
			}
		}
	}

	template<typename T>
	inline void FieldContainer::unlinkChildren(const T idx)
	{
		for (auto i : nodes[idx].getSons())
			nodes[i].setNoFather();
	}


}
