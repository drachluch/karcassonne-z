#pragma once
#include "first.h"
#include "Field.h"
#include "Array.h"


namespace kar {
	// permet de parcourir uniquement les noeuds sans parents, c'est à dire seulement les représentants
	class FieldIterator {
	public:
		using Node = Field;
		using Nodes = Array<Field, NUMBER_OF_FIELDNODES>;
	private:
		const Nodes & nodes;
		int currentNode;

	public:
		FieldIterator(const Nodes & nds) : nodes(nds), currentNode(0) {
			if (currentNode < nodes.length() && nodes[0].hasFather())
				operator++();
		}
		~FieldIterator() = default;

		inline bool isOver() const { return currentNode >= nodes.length(); }
		inline bool isNotOver() const { return currentNode < nodes.length(); }
		void operator++() {
			currentNode++;
			for (; currentNode < nodes.length() && nodes[currentNode].hasFather(); currentNode++);
		}
		inline const auto & getCore() const { return nodes[currentNode].getCoreData(); }
	};

}