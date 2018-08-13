#pragma once
#include "Road.h"
#include "Array.h"


namespace kar {
	class RoadIterator {
	public:
		using Node = Road;
		using Nodes = Array<Road, NUMBER_OF_ROADNODES>;
	private:
		const Nodes & nodes;
		int currentNode;

	public:
		RoadIterator(const Nodes & nds) : nodes(nds), currentNode(0) {
			if (currentNode < nodes.length() && (nodes[0].isCompleted() || nodes[0].hasFather()))
				operator++();
		}
		~RoadIterator() = default;

		inline bool isOver() const { return currentNode >= nodes.length(); }
		void operator++() {
			currentNode++;
			for (; currentNode < nodes.length() && (nodes[currentNode].isCompleted() || nodes[currentNode].hasFather()); currentNode++);
		}
		inline const RoadCoreData & getCore() const { return nodes[currentNode].getCoreData(); }
	};

}
