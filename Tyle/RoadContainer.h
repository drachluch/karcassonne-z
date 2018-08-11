#pragma once
#include "Array.h"
#include "Bloc.h"
#include "TileBlueprint.h"
#include "Road.h"

namespace kar {


	template <int nbPlayers>
	void noticeCompletedNode(const Road<nbPlayers> & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers);

	template <int nbPlayers>
	void unnoticeCompletedNode(const Road<nbPlayers> & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers);

	template <int nbPlayers>
	void noticeDirectFollower(Road<nbPlayers> & nd, char idxPlayer, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers);

	template <int nbPlayers>
	void unnoticeDirectFollower(Road<nbPlayers> & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers);
	

	template <int nbNodes, int nbPlayers, int nbTiles>
	class RoadContainer {
	public:
		using Node = Road<nbPlayers>;
		using Nodes = Array<Node, nbNodes>;
		using Scores = BlocStatic<int, nbPlayers>;
		using Followers = BlocStatic<int, nbPlayers>;
		using Logs = Array<char, nbTiles>;

	private:
		Nodes nodes;
		Logs addedNumberOfRoadsLogs;
		Scores scores = { 0 };
		Followers followers = { 0 };

		template <typename T>
		void unlinkChildren(const T idx);
		
	public:

		void add(const TileBlueprint::RoadNodeBlueprints & rnbs);
		void makeFatherAndSon(const signed char idxFather, const signed char idxChild);
		void checkForCompletedNodes();
		void cancel();

		int waysToSetFollower() const;
		void setFollower(int wayThief, char idxPlayer);
		void cancelFollower(int wayThief);

	};

	template<int nbNodes, int nbPlayers, int nbTiles>
	inline void RoadContainer<nbNodes, nbPlayers, nbTiles>::add(const TileBlueprint::RoadNodeBlueprints & rnbs)
	{
		nodes.addLength(rnbs.length());
		addedNumberOfRoadsLogs.push(rnbs.length());

		if (rnbs.length() == 1)
			nodes.last().reset(rnbs[0]);
		else
			if (rnbs.length() > 1) {
				auto first = nodes.length();
				for (auto i = 0; i < rnbs.length(); i++)
					nodes[first + i].reset(rnbs[i], addedNumberOfRoadsLogs.length());
			}
	}

	template<int nbNodes, int nbPlayers, int nbTiles>
	inline void RoadContainer<nbNodes, nbPlayers, nbTiles>::makeFatherAndSon(const signed char idxFather, const signed char idxChild)
	{
		nodes[idxFather].becomeFatherOf(nodes[idxChild], idxFather, idxChild);
	}

	template<int nbNodes, int nbPlayers, int nbTiles>
	inline void RoadContainer<nbNodes, nbPlayers, nbTiles>::checkForCompletedNodes()
	{
		auto nbNodesChecked = addedNumberOfRoadsLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		// d�compte des points pour les routes termin�es avec des partisans d�j� dessus
		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & rn = nodes[first + i];
			if (!rn.hasFather() && rn.isCompleted() && rn.hasAnyFollower())
				noticeCompletedNode(rn, scores, followers);
		}
	}

	// nbNodes > 0
	template<int nbNodes, int nbPlayers, int nbTiles>
	inline void RoadContainer<nbNodes, nbPlayers, nbTiles>::cancel()
	{
		auto nbNodesCanceled = addedNumberOfRoadsLogs.pop();
		auto first = nodes.length() - nbNodesCanceled;
		for (auto i = 0; i < nbNodesCanceled; i++) {
			auto & nd = nodes[first + i];
			if (nd.hasAnyFollower() && !nd.hasFather()) {
				if (nd.hasDirectFollower()) {
					unnoticeDirectFollower(nd, scores, followers);
				} else {
					if (nd.isCompleted())
						unnoticeCompletedNode(nd, scores, followers);
				}
			}
			unlinkChildren(first + i);
		}
		nodes.addLength(-nbNodesCanceled);
	}

	template<int nbNodes, int nbPlayers, int nbTiles>
	inline int RoadContainer<nbNodes, nbPlayers, nbTiles>::waysToSetFollower() const
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

	template<int nbNodes, int nbPlayers, int nbTiles>
	inline void RoadContainer<nbNodes, nbPlayers, nbTiles>::setFollower(int wayThief, char idxPlayer)
	{
		auto nbNodesChecked = addedNumberOfRoadsLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		auto ways = 0;

		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & rn = nodes[first + i];
			if (rn.canSetThief()) {
				if (ways == wayThief) {
					noticeDirectFollower(rn, idxPlayer, scores, followers);
					return;
				}
				ways++;
			}
		}
	}

	template<int nbNodes, int nbPlayers, int nbTiles>
	inline void RoadContainer<nbNodes, nbPlayers, nbTiles>::cancelFollower(int wayThief)
	{
		auto nbNodesChecked = addedNumberOfRoadsLogs.last();
		auto first = nodes.length() - nbNodesChecked;
		auto ways = 0;

		for (auto i = 0; i < nbNodesChecked; i++) {
			auto & rn = nodes[first + i];
			if (rn.canSetThief()) {
				if (ways == wayThief) {
					unnoticeDirectFollower(rn, scores, followers);
					return;
				}
				ways++;
			}
		}
	}


	template <int nbPlayers>
	inline void noticeCompletedNode(const Road<nbPlayers> & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers) {
		auto maxF = rn.getMaxFollower();
		auto score = rn.score();

		for (auto idxPlayer = 0; idxPlayer < nbPlayers; idxPlayer++) {
			// si le joueur est propri�taire
			if (rn.getCumulatedFollower(idxPlayer) == maxF)
				scores[idxPlayer] += score;
			// lib�ration des partisans
			followers[idxPlayer] -= rn.getCumulatedFollower(idxPlayer);
		}
	}

	template <int nbPlayers>
	inline void unnoticeCompletedNode(const Road<nbPlayers> & nd, BlocStatic<int, nbPlayers> & scores, BlocStatic<int, nbPlayers> & followers) {
		auto maxF = nd.getMaxFollower();
		auto score = nd.score();

		for (auto idxPlayer = 0; idxPlayer < nbPlayers; idxPlayer++) {
			// si le joueur est propri�taire
			if (nd.getCumulatedFollower(idxPlayer) == maxF)
				scores[idxPlayer] -= score;
			// retour des partisans sur le plateau
			followers[idxPlayer] += nd.getCumulatedFollower(idxPlayer);
		}
	}

	template<int nbPlayers>
	inline void noticeDirectFollower(Road<nbPlayers> & nd, char idxPlayer, BlocStatic<int, nbPlayers>& scores, BlocStatic<int, nbPlayers>& followers)
	{
		if (nd.canSetFollower() && !nd.hasDirectFollower()) {

			nd.setDirectFollower(idxPlayer);
			if (nd.isCompleted()) {
				scores[nd.getDirectFollower()] += nd.score(); // les points sont compt�s, le partisan est plac� puis imm�diatement remis � la r�serve.
			} else {
				followers[nd.getDirectFollower()]++; // les points ne sont pas compt�s, le partisan est plac�.
			}

		}
		else {
			throw "Can't set follower";
		}

	}

	template<int nbPlayers>
	inline void unnoticeDirectFollower(Road<nbPlayers> & nd, BlocStatic<int, nbPlayers>& scores, BlocStatic<int, nbPlayers>& followers)
	{
		if (nd.canSetFollower() && nd.hasDirectFollower()) {

			if (nd.isCompleted()) {
				// les points ont �t� compt�s, le partisan n'est plus sur place
				// le partisan est d�j� lib�r�, et le score est rendu normal.
				scores[nd.getDirectFollower()] -= nd.score();
			}
			else {
				// les points n'ont pas �t� compt�s, le partisan est toujours sur place
				// donc le score ne change pas, et le partisan est lib�r�.
				followers[nd.getDirectFollower()]--;
			}

			nd.setNoDirectFollower();
		}
		else {
			throw "Can't cancel follower";
		}
	}

	template<int nbNodes, int nbPlayers, int nbTiles>
	template<typename T>
	inline void RoadContainer<nbNodes, nbPlayers, nbTiles>::unlinkChildren(const T idx)
	{
		auto & sons = nodes[idx].getSons();
		for (auto iSon = 0; iSon < sons.length(); iSon++)
			nodes[sons[iSon]].setNoFather();
	}

	
}
