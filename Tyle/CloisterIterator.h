#pragma once
#include "first.h"
#include "Array.h"
#include "Cloister.h"

namespace kar {
	class CloisterIterator {
	public:
		using Node = Cloister;
		using Nodes = Array<Cloister, NUMBER_OF_CLOISTERS>;
	private:
		const Nodes & nodes;
		int currentNode;

	public:
		CloisterIterator(const Nodes & nds) : nodes(nds), currentNode(0) {
			if (currentNode < nodes.length() && (nodes[0].isCompleted() || !nodes[0].hasDirectFollower()))
				operator++();
		}
		~CloisterIterator() = default;

		inline bool isNotOver() const { return currentNode < nodes.length(); }
		void operator++() {
			currentNode++;
			for (; currentNode < nodes.length() && (nodes[currentNode].isCompleted() || !nodes[0].hasDirectFollower()); currentNode++);
		}
		inline const Cloister & getCore() const { return nodes[currentNode]; }
	};

}

