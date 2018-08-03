#pragma once
#include "first.h"
#include "CityNodeBlueprint.h"
#include <string>

class CityNode
{
	CityNode * father = nullptr;
	int numberOfSons = 0;
	CityNode * sons[4] = { nullptr, nullptr, nullptr, nullptr };
	int directFollower = -1;
	int cumulatedFollowers[NUMBER_OF_PLAYERS];

	int coveredTiles = 1;
	int holes;
	int crest;
	int numberOfAmbigiousPositions = 0;
	int ambigiousPositions[5] = { 0, 0, 0, 0, 0 };

public:
	CityNode()=default;
	CityNode(const CityNodeBlueprint & rnb);
	~CityNode() = default;

	CityNode * getFather() const  { return father; }
	void setFather(CityNode * f)  { father = f; }
	void setNoFather()  { father = nullptr; }

	int getNumberOfSons() const  { return numberOfSons; }
	CityNode * getSon(int i) const  { return sons[i]; }
	void addSon(CityNode * s)  { sons[numberOfSons] = s; numberOfSons++; }
	void cleanseChildren()  { numberOfSons = 0; memset(sons, 0, sizeof(sons)); }

	bool hasDirectFollower() const  { return directFollower != -1; }
	void setDirectFollower(int df)  { directFollower = df; }
	void setNoDirectFollower()  { directFollower = -1; }

	const int * getCumulatedFollowers() const  { return cumulatedFollowers; }
	void addCumulatedFollowers(const int * cf)  { for (int i = 0; i < NUMBER_OF_PLAYERS; cumulatedFollowers[i] += cf[i], i++); }
	void cleanseCumulatedFollowers()  { memset(cumulatedFollowers, 0, sizeof(cumulatedFollowers)); }
	void setOneCumulatedFollower(int p, int e) { cumulatedFollowers[p] += e; }

	int getUnambigiouslyCoveredTiles() const  { return coveredTiles; }
	int setUnambigiouslyCoveredArea(int c)  { coveredTiles = c; }

	int getNumberOfHoles() const  { return holes; }
	void setNumberOfHoles(int h)  { holes = h; }
	bool isCompleted() const  { return holes == 0; }

	int getNumberOfAmbigiousPositions() const  { return numberOfAmbigiousPositions; }
	int getAmbigiousPosition(int i) const  { return ambigiousPositions[i]; }

	void addAmbigiousPosition(int p);

	int getCoveredArea() const  { return coveredTiles + numberOfAmbigiousPositions; }
	bool hasAnyFollower() const ;
	int getPoints() const  { return getCoveredArea(); }


};

