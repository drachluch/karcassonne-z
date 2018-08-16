#pragma once

namespace kar {

	template<class Nd, class Scores, class Followers>
	void noticeCompletedNode(const Nd& nd, Scores& scores, Followers& followers)
	{
		nd.getCoreData().give_points(scores);
		nd.getCoreData().free_followers(followers);
	}
	
	template<class Nd, class Scores, class Followers>
	void noticeDirectFollower(Nd& nd, char idxPlayer, Scores& scores, Followers& followers)
	{
		nd.setDirectFollower(idxPlayer);
		if (nd.isCompleted())
			scores[nd.getDirectFollower()] += nd.getCoreData().score(); // les points sont compt�s, le partisan est plac� puis imm�diatement remis � la r�serve.
		else
			followers[nd.getDirectFollower()]++; // les points ne sont pas compt�s, le partisan est plac�.
	}

	template<class Nd, class Scores, class Followers>
	void unnoticeDirectFollower(Nd& nd, Scores& scores, Followers& followers)
	{
		if (nd.isCompleted())
			scores[nd.getDirectFollower()] -= nd.getCoreData().score();// les points ont �t� compt�s, le partisan n'est plus sur place; le partisan est d�j� lib�r�, et le score est rendu normal.
		else
			followers[nd.getDirectFollower()]--;// les points n'ont pas �t� compt�s, le partisan est toujours sur place donc le score ne change pas, et le partisan est lib�r�.
		nd.setNoDirectFollower();
	}

	template<class Nd, class Scores, class Followers>
	bool noticeCanceled(const Nd& nd, Scores & scores, Followers & followers)
	{
		if (nd.hasAnyFollower() && !nd.hasFather()) 
			if (nd.hasDirectFollower()) {
				if (nd.isCompleted())
					scores[nd.getDirectFollower()] -= nd.getCoreData().score();
				else
					followers[nd.getDirectFollower()]--;
				return true;
			} else
				if (nd.isCompleted()) {
					const auto & core = nd.getCoreData();
					core.take_back_points(scores);
					core.get_back_followers(followers);
					return true;
				}
		return false;
	}

	template<class Nd, class Scores>
	void noticeUncompletedNodeAtTheEnd(const Nd& nd, Scores& scores) { nd.getCoreData().give_points(scores); }

	template<class Nd, class Scores>
	void unnoticeUncompletedNodeAtTheEnd(const Nd& nd, Scores& scores) { nd.getCoreData().take_back_points(scores); }


}
