#pragma once
#include "Game.h"

void cloisterOnePlayer();
float exploreTheFuture_cloisterOnePlayer(Karcassonne::Game & g, int depth);
int evaluateCloistersState(const Karcassonne::Game & g);


void roadnodeOnePlayer();
float exploreTheFuture_roadnodeOnePlayer(Karcassonne::Game & g, int depth);
float evaluateRoadnodesState(const Karcassonne::Game & g);


void bothOnePlayer();
float evaluateBothState(const Karcassonne::Game & g);





