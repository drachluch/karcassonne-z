#pragma once
#include "Game.h"

void cloisterOnePlayer();
float exploreTheFuture_cloisterOnePlayer(kar::Game & g, int depth);
int evaluateCloistersState(const kar::Game & g);


void roadnodeOnePlayer();
float exploreTheFuture_roadnodeOnePlayer(kar::Game & g, int depth);
float evaluateRoadnodesState(const kar::Game & g);


void bothOnePlayer();
float evaluateBothState(const kar::Game & g);





