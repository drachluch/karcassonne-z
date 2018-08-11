#pragma once
#include "Direction.h"
#include "FieldPosition.h"


namespace kar {

	struct ReachablePositionLog {
		int oldIndex;
		int addedLength;
	};


	struct DiscardedBlueprintLog {
		int nbDiscardedBlueprints;
	};

	enum class OptionFollowerType {
		None, Thief, Knight, Monk, Farmer
	};



	class FollowerLog {
		OptionFollowerType type = OptionFollowerType::None;
		Direction dir;
		FieldPosition hd;

	public:
		FollowerLog() = default;

		void setNoFollower() { type = OptionFollowerType::None; }
		void setMonk() { type = OptionFollowerType::Monk; }
		void setThief(const Direction & d) { type = OptionFollowerType::Thief; dir = d; }
		void setKnight(const Direction & d) { type = OptionFollowerType::Knight; dir = d; }
		void setFarmer(const CompleteFieldPosition & cfp) { type = OptionFollowerType::Farmer; dir = cfp.direction; hd = cfp.fieldPosition; }

		bool hasFollower() const { return type != OptionFollowerType::None; }
		bool hasThief() const { return type == OptionFollowerType::Thief; }
		bool hasKnight() const { return type == OptionFollowerType::Knight; }
		bool hasMonk() const { return type == OptionFollowerType::Monk; }
		bool hasFarmer() const { return type == OptionFollowerType::Farmer; }
		OptionFollowerType getFollowerType() const { return type; }

		const Direction & getDirection() const { return dir; }
		FieldPosition getFieldPosition() const { return hd; }

	};

}