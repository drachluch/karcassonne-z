#pragma once
#include "TileBlueprint.h"



struct RotateBlueprint
{
	const TileBlueprint & blueprint;
	int indexBlueprint;
	int rq;

public:
	RotateBlueprint(const TileBlueprint & tb, int idx, int r) : blueprint(tb), indexBlueprint(idx), rq(r) {}
	RotateBlueprint(const RotateBlueprint &) = default;
	~RotateBlueprint() = default;

	int getRq() const noexcept { return rq; }
	int getIndexBlueprint() const noexcept { return indexBlueprint; }
	const TileBlueprint & getBlueprint() const noexcept { return blueprint; }

	SideType getSideType(const Direction & d) const noexcept { blueprint.getSideType(d.rotateTrigo(rq)); }
};

