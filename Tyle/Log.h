#pragma once
#include "Direction.h"

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

enum class FieldPosition {
	Center, Right, Left
};

class FollowerLog {
	OptionFollowerType type = OptionFollowerType::None;
	Direction dir;
	FieldPosition hd;

public:
	FollowerLog()=default;
	
	void setNoFollower() { type = OptionFollowerType::None; }
	void setMonk() { type = OptionFollowerType::Monk; }
	void setThief(const Direction & d) { type = OptionFollowerType::Thief; dir = d; }
	void setKnight(const Direction & d) { type = OptionFollowerType::Knight; dir = d; }
	void setFarmer(const Direction & d, const FieldPosition fp) { type = OptionFollowerType::Farmer; dir = d; hd = fp; }

	bool hasFollower() const { return type != OptionFollowerType::None; }
	bool hasThief() const { return type == OptionFollowerType::Thief; }
	bool hasKnight() const { return type == OptionFollowerType::Knight; }
	bool hasMonk() const { return type == OptionFollowerType::Monk; }
	bool hasFarmer() const { return type == OptionFollowerType::Farmer; }
	OptionFollowerType getFollowerType() const { return type; }

	const Direction & getDirection() const { return dir; }
	FieldPosition getFieldPosition() const { return hd; }
	
};

