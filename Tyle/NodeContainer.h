#pragma once
#include "Array.h"
#include "Bloc.h"
#include "TileBlueprint.h"

namespace Karcassonne {


	template <int nbSons, int nbPlayers>
	class NRoad{
	public:
		using Index = signed char;
		using Sons = Array<Index, nbSons>;
		using Followers = BlocStatic<char, nbPlayers>;

	private:
		Index father = -1;
		Sons sons;

		signed char garbageFollower = -2;
		Followers cumulatedFollowers = { 0 };

		char coveredArea = 1;
		char holes = 1;
		signed char ambigiousPosition = -1;

	public:
		
		void reset(char h, char idxTile = -1) {
			father = -1;
			sons.cleanse();
			garbageFollower = -2;
			cumulatedFollowers.reset(0);
			coveredArea = 1;
			holes = h;
			ambigiousPosition = idxTile;
		}

		bool hasFather() const { return father != -1; }
		void setNoFather() { father = -1; }
		const Sons & getSons() const { return sons; }

		bool isCompleted() const { return holes == 0; }
		int score() const { return coveredArea; }

		bool hasAnyFollower() const { return garbageFollower > -2; }
		bool hasDirectFollower() const { return garbageFollower > -1; }
		void setDirectFollower(signed char idxPlayer) { garbageFollower = idxPlayer; cumulatedFollowers[idxPlayer] = 1; }
		void setNoDirectFollower() { garbageFollower = -2; }
		int getDirectFollower() { return garbageFollower; }
		const Followers & getFollowers() const { return cumulatedFollowers; }


	};

	template <typename Node, int nbPlayers>
	void noticeCompletedNode(const Node & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers);

	template <typename Node, int nbPlayers>
	void unnoticeCompletedNode(const Node & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers);

	template <typename Node, int nbPlayers>
	void noticeDirectFollower(Node & nd, char idxPlayer, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers);

	template <typename Node, int nbPlayers>
	void unnoticeDirectFollower(Node & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers);
	

	template <typename Node, int nbNodes, int nbPlayers>
	class NodeContainer {
		using Nodes = Array<Node, nbNodes>;
		using Scores = BlocStatic<int, nbPlayers>;
		using Followers = BlocStatic<int, nbPlayers>;

		Nodes nodes;

		Scores scores = { 0 };
		Followers followers = { 0 };

		template <typename T>
		void unlinkChildren(const T idx);
		


	public:

		void add(const TileBlueprint::RoadNodeBlueprints & rnbs, const signed char idxTile = -1);
		void becomeFatherOf(const signed char idxFather, const signed char idxChild);
		void checkForCompletedNodes(int nbNodesChecked);
		void cancel(int nbNodesCanceled);

	};

	template<typename Node, int nbNodes, int nbPlayers>
	inline void NodeContainer<Node, nbNodes, nbPlayers>::add(const TileBlueprint::RoadNodeBlueprints & rnbs, const signed char idxTile)
	{
		auto first = nodes.length();
		nodes.addLength(rnbs.length());

		for (auto i = 0; i < rnbs.length(); i++)
			nodes[first + i].reset(rnbs[i], idxTile);
	}

	template<typename Node, int nbNodes, int nbPlayers>
	inline void NodeContainer<Node, nbNodes, nbPlayers>::checkForCompletedNodes(int nbNodesChecked)
	{
		auto first = nodes.length() - nbNodesChecked;
		// décompte des points pour les routes terminées avec des partisans déjà dessus
		for (auto relativIdxRoadnode = 0; relativIdxRoadnode < nbNodesChecked; relativIdxRoadnode++) {
			auto & rn = nodes[first + relativIdxRoadnode];
			if (!rn.hasFather() && rn.isCompleted() && rn.hasAnyFollower())
				noticeCompletedNode(rn, scores, followers);
		}
	}

	// nbNodes > 0
	template<typename Node, int nbNodes, int nbPlayers>
	inline void NodeContainer<Node, nbNodes, nbPlayers>::cancel(int nbNodesCanceled)
	{
		auto first = nodes.length() - nbNodesCanceled;
		for (auto relativNodeIdx = 0; relativNodeIdx < nbNodesCanceled; relativNodeIdx++) {
			
			auto & nd = nodes[first + relativIdxRoadNode];

			if (nd.hasAnyFollower() && !nd.hasFather()) {
				if (nd.hasDirectFollower()) {
					unnoticeDirectFollower(nd, scores, followers);
				} else {
					if (nd.isCompleted())
						unnoticeCompletedNode(nd, scores, followers);
				}
			}

			unlinkChildren(first + relativNodeIdx);
		}

		nodes.addLength(-nbNodesCanceled);
	}

	template <typename Node, int nbPlayers>
	void noticeCompletedNode(const Node & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers) {

		int maxF = rn.getMaxFollower();
		int score = rn.score();

		for (int idxPlayer = 0; idxPlayer < NUMBER_OF_PLAYERS; idxPlayer++) {
			// si le joueur est propriétaire
			if (rn.getCumulatedFollower(idxPlayer) == maxF)
				scores[idxPlayer] += score;
			// libération des partisans
			followers[idxPlayer] -= rn.getCumulatedFollower(idxPlayer);
		}
	}

	template <typename Node, int nbPlayers>
	void unnoticeCompletedNode(const Node & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers) {
		int maxF = nd.getMaxFollower();
		int score = nd.score();

		for (int idxPlayer = 0; idxPlayer < nbPlayers; idxPlayer++) {
			// si le joueur est propriétaire
			if (nd.getCumulatedFollower(idxPlayer) == maxF)
				scores[idxPlayer] -= score;
			// retour des partisans sur le plateau
			followers[idxPlayer] += nd.getCumulatedFollower(idxPlayer);
		}
	}

	template<typename Node, int nbPlayers>
	void noticeDirectFollower(Node & nd, char idxPlayer, BlocStatic<int, nbPlayers>& scores, BlocStatic<int, nbPlayers>& followers)
	{
		if (nd.canSetFollower() && !nd.hasDirectFollower()) {

			nd.setDirectFollower(idxPlayer);
			if (nd.isCompleted()) {
				scores[nd.getDirectFollower()] += nd.score(); // les points sont comptés, le partisan est placé puis immédiatement remis à la réserve.
			} else {
				followers[nd.getDirectFollower()]++; // les points ne sont pas comptés, le partisan est placé.
			}

		}
		else {
			throw "Can't set follower";
		}

	}

	template<typename Node, int nbPlayers>
	void unnoticeDirectFollower(Node & nd, BlocStatic<int, nbPlayers>& scores, BlocStatic<int, nbPlayers>& followers)
	{
		if (nd.canSetFollower() && nd.hasDirectFollower()) {

			if (nd.isCompleted()) {
				// les points ont été comptés, le partisan n'est plus sur place
				// le partisan est déjà libéré, et le score est rendu normal.
				scores[nd.getDirectFollower()] -= nd.score();
			}
			else {
				// les points n'ont pas été comptés, le partisan est toujours sur place
				// donc le score ne change pas, et le partisan est libéré.
				followers[nd.getDirectFollower()]--;
			}

			nd.setNoDirectFollower();
		}
		else {
			throw "Can't cancel follower";
		}
	}

	template<typename Node, int nbNodes, int nbPlayers>
	template<typename T>
	inline void NodeContainer<Node, nbNodes, nbPlayers>::unlinkChildren(const T idx)
	{
		auto & sons = nodes[idx].getSons();
		for (auto iSon = 0; iSon < sons.length(); iSon++)
			nodes[sons[iSon]].setNoFather();
	}
}
