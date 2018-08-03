#pragma once
#include "Game.h"

void cloisterOnePlayer();
float exploreTheFuture_cloisterOnePlayer(Game & g, int depth);
int evaluateCloistersState(const Game & g);


void roadnodeOnePlayer();
float exploreTheFuture_roadnodeOnePlayer(Game & g, int depth);
float evaluateRoadnodesState(const Game & g);


void bothOnePlayer();
float evaluateBothState(const Game & g);





