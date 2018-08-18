#pragma once

namespace kar {
	template<class Nodes>
	class NodeIterator
	{
	private:
		const Nodes & nodes;
		int currentNode;

	public:
		NodeIterator(const Nodes & nds) : nodes(nds), currentNode(0) {
			if (currentNode < nodes.length() && nodes[0].isNotWorth())
				operator++();
		}
		~NodeIterator() = default;

		inline bool isOver() const { return currentNode >= nodes.length(); }
		inline bool isNotOver() const { return currentNode < nodes.length(); }
		void operator++() {
			currentNode++;
			for (; currentNode < nodes.length() && nodes[0].isNotWorth(); currentNode++);
		}
		inline const auto & getCore() const { return nodes[currentNode].getCoreData(); }
	};
}