#include "FieldNode.h"
#include <string>


namespace kar {

	void FieldNode::reset()
	{
		father = nullptr;
		sons.cleanse();

		garbageDirectFollower = -2;
		cumulatedFollowers.reset(0);

		neighborCities = { 0, nullptr };
	}

	void FieldNode::becomeFatherOf(FieldNode * son)
	{
		sons.push(son);
		son->father = this;

		// followers
		if (son->hasAnyFollower()) {
			if (garbageDirectFollower == -2)
				garbageDirectFollower = -1;
			cumulatedFollowers = son->cumulatedFollowers;
		}

	}

	void FieldNode::unlinkChildren()
	{
		for (int i = 0; i < sons.length(); i++)
			sons[i]->father = nullptr;
	}

}