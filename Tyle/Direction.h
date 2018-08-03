#pragma once

class Direction
{
	int e = 0;

public:
	void set(int r)  { e = (r % 4 + 4) % 4; }
	
	Direction()  = default;
	explicit Direction(int r)  { set(r); };
	Direction(const Direction & d) = default;
	~Direction()  = default;
	
	Direction rotateTrigo(int r) const  { return Direction(e - r); }
	Direction rotateTrigo(const Direction & d) const  { return Direction(e - d.get()); }
	Direction rotateClock(int r) const  { return Direction(e + r); }
	Direction rotateClock(const Direction & d) const  { return Direction(e + d.get()); }

	Direction opposite() const  { return Direction(e + 2); }
	int get() const  { return e; }

	bool operator==(const Direction & d) const  { return e == d.e; }

};

