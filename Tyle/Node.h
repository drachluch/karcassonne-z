#pragma once
#include <vector>

namespace kar {

	template<class Core>
	class Node {
	public:
		using Index = char;
		using Sons = std::vector<Index>;

	private:
		Index father = -1;
		Sons sons;
		Core core;

	public:
		Node() = default;
		~Node() = default;

		template<class NodeBlueprint>
		void reset(const NodeBlueprint& nb) {
			father = -1;
			sons.clear();
			core.reset(nb);
		}
		template<class NodeBlueprint>
		void reset(const NodeBlueprint& nb, char ambigiousPosition) {
			father = -1;
			sons.clear();
			core.reset(nb, ambigiousPosition);
		}
		void becomeFatherOf(Node& ndSon, const Index idxFather, const Index idxSon) {
			sons.push_back(idxSon);
			ndSon.father = idxFather;
			core.assimilate(ndSon.core);
		}

		Index getFather() const { return father; }
		bool hasFather() const { return father != -1; }
		const Sons & getSons() const { return sons; }
		void setNoFather() { father = -1; }

		const Core & getCore() const { return core; }

		bool canSetFollower() const { return !hasFather() && !core.hasAnyFollower(); }
		bool isNotWorth() const { return hasFather() || core.isCompleted(); }
	};
}
