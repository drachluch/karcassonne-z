#include "Game.h"
#include <string>

const TileBlueprint Game::blueprints[NUMBER_OF_DISTINCT_TILES] = {
	TileBlueprint{
	"1aFefnowxst",
	1,
	true,
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	0,
	CityNodeBlueprint{},
	CityNodeBlueprint{},
	1,
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"1Cenwsc",
	1,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 4, true, 0 },
	CityNodeBlueprint{},
	0,
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"1ReRnRwRsFetFfnFowFxs",
	1,
	false,
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Road, 1, 1, 2 },
	SideBlueprint{ SideType::Road, 2, 2, 3 },
	SideBlueprint{ SideType::Road, 3, 3, 0 },
	4,
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{ 1 },
	0,
	CityNodeBlueprint{},
	CityNodeBlueprint{},
	4,
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{ 0 }
},
TileBlueprint{
	"2CeCwFnost01",
	2,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::City, 1 },
	SideBlueprint{ SideType::Field, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	2,
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	1,
	FieldNodeBlueprint{ 2,{ 0, 1 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"2CewcFno0Fst0",
	2,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 1 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 2, true, 2,{ 0, 1 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"2CewFno0Fst0",
	2,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 1 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 2, false, 2,{ 0, 1 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"2RewFexstFfnow",
	2,
	false,
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Field, 1 },
	SideBlueprint{ SideType::Road, 0, 1, 0 },
	SideBlueprint{ SideType::Field, 0 },
	1,
	RoadNodeBlueprint{ 2 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	0,
	CityNodeBlueprint{},
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4aReFefnowxst",
	4,
	true,
	SideBlueprint{ SideType::Road, 0, 0, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	1,
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	0,
	CityNodeBlueprint{},
	CityNodeBlueprint{},
	1,
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CeCnFwxst01",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 1 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	2,
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	1,
	FieldNodeBlueprint{ 2,{ 0, 1 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CeFnowxst0",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	CityNodeBlueprint{},
	1,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CencFwxst0",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 2, true, 1,{ 0 } },
	CityNodeBlueprint{},
	1,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CencRwsFwt0Fxs",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Road, 0, 1, 0 },
	1,
	RoadNodeBlueprint{ 2 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 2, true, 1,{ 0 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CenFwxst0",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 2, false, 1,{ 0 } },
	CityNodeBlueprint{},
	1,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CenRwsFwt0Fxs",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Road, 0, 1, 0 },
	1,
	RoadNodeBlueprint{ 2 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 2, false, 1,{ 0 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CenwcFst0",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 3, true, 1,{ 0 } },
	CityNodeBlueprint{},
	1,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CenwcRsFs0Ft0",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	1,
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 3, true, 2,{ 0, 1 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CenwFst0",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	0,
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 3, false, 1,{ 0 } },
	CityNodeBlueprint{},
	1,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CenwRsFs0Ft0",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	1,
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 3, false, 2,{ 0, 1 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CeRnRwRsFnt0FowFxs",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Road, 1, 1, 2 },
	SideBlueprint{ SideType::Road, 2, 2, 0 },
	3,
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	CityNodeBlueprint{},
	3,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CeRnsFnt0Fowxs",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Field, 1 },
	SideBlueprint{ SideType::Road, 0, 1, 0 },
	1,
	RoadNodeBlueprint{ 2 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CeRnwFnxst0Fow",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Road, 0, 1, 0 },
	SideBlueprint{ SideType::Field, 0 },
	1,
	RoadNodeBlueprint{ 2 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4CeRwsFnowt0Fxs",
	4,
	false,
	SideBlueprint{ SideType::City, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Road, 0, 1, 0 },
	1,
	RoadNodeBlueprint{ 2 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	1,
	CityNodeBlueprint{ 1, false, 1,{ 0 } },
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 1,{ 0 } },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4RenFeowxstFfn",
	4,
	false,
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Road, 0, 1, 0 },
	SideBlueprint{ SideType::Field, 0 },
	SideBlueprint{ SideType::Field, 0 },
	1,
	RoadNodeBlueprint{ 2 },
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	RoadNodeBlueprint{},
	0,
	CityNodeBlueprint{},
	CityNodeBlueprint{},
	2,
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{},
	FieldNodeBlueprint{}
},
TileBlueprint{
	"4ReRnRwFexstFfnFow",
	4,
	false,
	SideBlueprint{ SideType::Road, 0, 0, 1 },
	SideBlueprint{ SideType::Road, 1, 1, 2 },
	SideBlueprint{ SideType::Road, 2, 2, 0 },
	SideBlueprint{ SideType::Field, 0 },
	3,
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{ 1 },
	RoadNodeBlueprint{},
	0,
	CityNodeBlueprint{},
	CityNodeBlueprint{},
	3,
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{ 0 },
	FieldNodeBlueprint{}
},
};


static const int standardInventory[NUMBER_OF_DISTINCT_TILES] = {
	4, 1, 1, 3, 2, 1,
	8, 2, 2, 5, 2, 2,
	3, 3, 1, 2, 3, 1,
	3, 4, 3, 3, 9, 4,
};


void Game::reachablePositions_reach(int ir) 
{
	auto reached = reachablePositions[ir];
	const Position nearPos[4] = { reached.east(), reached.north(), reached.west(), reached.south() };
	bool alreadyIn[4] = { false, false, false, false };
	int nbNewPos = 4;
	int i;

	// calcul du nombre de nouvelles positions parmi celles qui sont autour de la position atteinte.
	for (int j = 0; j < 4; j++)
		if (!alreadyIn[j] && isReachable(nearPos[j])) {
			alreadyIn[j] = true;
			nbNewPos--;
		}

	// vérification de l'occupation
	// les positions occupées ne doivent pas retourner dans la lsite des positions atteingnables.
	for (int j = 0; j < 4; j++)
		if (!alreadyIn[j] && isOccupied(nearPos[j])) {
			alreadyIn[j] = true;
			nbNewPos--;
		}

	// replacement de la position ir par la dernière position de la liste.
	reachablePositions[ir] = reachablePositions.last();

	// ajout des nouvelles positions à la fin de la liste.
	i = reachablePositions.length() - 1;
	
	// update list length
	reachablePositions.addLength(nbNewPos - 1);

	for (int j = 0; j < 4; j++)
		if (!alreadyIn[j]) {
			reachablePositions[i] = nearPos[j];
			i++;
		}

	reachableLogs.push(ReachablePositionLog{ ir, nbNewPos - 1 });

}

void Game::reachablePositions_cancel(const Position & pCancel)
{

	auto & log = reachableLogs.pop();

	reachablePositions.addLength(-log.addedLength);

	reachablePositions.last() = reachablePositions[log.oldIndex];

	reachablePositions[log.oldIndex] = pCancel;

}

void Game::tiles_reach(const Position & p, IndexBlueprint indexBlueprint, const Direction & direction) 
{
	inventory[indexBlueprint]--;
	remainingTiles--;

	const TileBlueprint & tb = getBlueprint(indexBlueprint);

	tiles.push(Tile{ indexBlueprint, tb, direction });
	positions.push(p);

	cloisters_reach(p, tb.hasCloister());

	if (tb.getNumberOfRoadNodes() > 0)
		roadnodes_reach(p, tiles.length() - 1);
}

void Game::tiles_cancel() 
{
	const auto & t = tiles.pop();
	const TileBlueprint & tb = getBlueprint(t.getIndexBlueprint());

	cloisters_cancel(positions.pop(), tb.hasCloister());
	if (tb.getNumberOfRoadNodes() > 0)
		roadnodes_cancel(tb.getNumberOfRoadNodes());
	
	inventory[t.indexBlueprint]++;

	remainingTiles++;
}

void Game::cloisters_reach(const Position & p, bool newCloister) 
{
	for (int i = 0; i < cloisters.length(); i++) {
		auto & c = cloisters[i];
		if (c.withinRange(p)) {
			c.incrCompleteness();

			if (c.isCompleted() && c.hasDirectFollower()) {
				scores[c.getDirectFollower()] += c.score();
				followers[c.getDirectFollower()]++;
			}
		}
	}

	if (newCloister) {
		cloisters.push(Cloister{p});
		auto & c = cloisters.last();

		const Position ps[8] = { p.east(), p.east().north(), p.east().south(), p.north(), p.west(), p.west().north(), p.west().south(), p.south() };

		for (const Position & p : ps)
			if (isOccupied(p))
				c.incrCompleteness();

	}
}

void Game::cloisters_cancel(const Position & p, bool newCloister) 
{
	for (int i = 0; i < cloisters.length(); i++) {
		auto & c = cloisters[i];
		if (c.withinRange(p)) {
			if (c.isCompleted() && c.hasDirectFollower()) {
				scores[c.getDirectFollower()] -= c.score();
				followers[c.getDirectFollower()]--;
			}

			c.decrCompleteness();
		}
	}

	if (newCloister) {
		if (cloisters.last().hasDirectFollower())
			cancelMonk();
		
		cloisters.pop();
	}
}


// only if tb.getNumberOfRoadNodes() > 0
void Game::roadnodes_reach(const Position & p, int idxTile)
{
	auto & t = tiles[idxTile];
	auto & tb = getBlueprint(t.getIndexBlueprint());

	int first = roadnodes.length();
	int nbNodes = tb.getNumberOfRoadNodes();
	roadnodes.addLength(nbNodes);
	bool set[4] = { false, false, false, false };

	// initialisation des noeuds de route
	for (int i = 0; i < 4; i++) {
		const Direction d{ i };
		const Direction dTr = d.rotateTrigo(t.getDirection());

		if (tb.getSideType(dTr) == SideType::Road) {
			int relativIdxRoadnode = tb.getRoadNode(dTr);

			t.setRoadNode(d, first + relativIdxRoadnode);

			if (!set[relativIdxRoadnode]) {
				// nbNodes > 1 => position ambigue
				auto & bp = tb.getRoadNodeBlueprint(relativIdxRoadnode);

				roadnodes[first + relativIdxRoadnode] = nbNodes > 1
					? RoadNode(tb.getRoadNodeBlueprint(relativIdxRoadnode), idxTile)
					: RoadNode(tb.getRoadNodeBlueprint(relativIdxRoadnode));
				set[relativIdxRoadnode] = true;
			}
		}
	}
	
	// interaction avec les noeuds des tuiles adjacentes
	for (int i = 0; i < 4; i++) {
		const Direction d{ i };

		if (t.getSideType(d) == SideType::Road) {
			int idxRoadnode = t.getRoadNode(d);
			RoadNode & rn = roadnodes[idxRoadnode];

			int indexNextTile = getIndexPosition(p.next(d));
			if (indexNextTile != -1) {

				RoadNode & rootNextRn = roadnodes[getTile(indexNextTile).getRoadNode(d.opposite())].getRoot();
				RoadNode & rootCurrentRn = rn.getRoot();

				// you can't become your own father
				// and nextRn.getRoot() can't be a child, because it's the result of getRoot()
				if (&rootCurrentRn != &rootNextRn) {
					rootCurrentRn.becomeFatherOf(&rootNextRn);
				}
			}
		}
	}

	// décompte des points pour les routes terminées avec des partisans déjà dessus
	for (int relativIdxRoadnode = 0; relativIdxRoadnode < nbNodes; relativIdxRoadnode++) {
		RoadNode & rn = roadnodes[first + relativIdxRoadnode];
		if (!rn.hasFather() && rn.isCompleted() && rn.hasAnyFollower())
			updateForCompleted(rn, scores, followers);
	}
}

// nbNodes > 0
void Game::roadnodes_cancel(int nbNodes) 
{
	int first = roadnodes.length() - nbNodes;

	for (int relativIdxRoadNode = 0; relativIdxRoadNode < nbNodes; relativIdxRoadNode++) {
		RoadNode & rn = roadnodes[first + relativIdxRoadNode];

		if (rn.hasAnyFollower() && !rn.hasFather()) {
			if (rn.hasDirectFollower()) {
				cancelThiefOnRoadnode(first + relativIdxRoadNode);
			}
			else {
				if (rn.isCompleted())
					cancelUpdateForCompleted(rn, scores, followers);
			}
		}

		rn.unlinkChildren();
	}

	roadnodes.addLength(-nbNodes);

}

void Game::setThiefOnRoadnode(int indexRoadnode)
{
	auto & rn = roadnodes[indexRoadnode];

	if (rn.canSetThief() && !rn.hasDirectFollower() && !followerLogs.last().hasFollower()) {
		followerLogs.last().setThief(tiles.last().getFirstDirectionOfRoadnode(indexRoadnode));

		rn.setDirectFollower(currentPlayer);
		if (rn.isCompleted()) {
			// les points sont comptés, le partisan est placé puis immédiatement remis à la réserve.
			scores[rn.getDirectFollower()] += rn.score();
		}
		else {
			// les points ne sont pas comptés, le partisan est placé.
			followers[rn.getDirectFollower()]--;
		}

	}
	else {
		throw "Can't set thief";
	}
}

void Game::cancelThiefOnRoadnode(int indexRoadnode)
{
	auto & rn = roadnodes[indexRoadnode];

	if (rn.canSetThief() && rn.hasDirectFollower() && followerLogs.last().hasThief()) {
		followerLogs.last().setNoFollower();

		if (rn.isCompleted()) {
			// les points ont été comptés, le partisan n'est plus sur place
			// le partisan est déjà libéré, et le score est rendu normal.
			scores[rn.getDirectFollower()] -= rn.score();
		}
		else {
			// les points n'ont pas été comptés, le partisan est toujours sur place
			// donc le score ne change pas, et le partisan est libéré.
			followers[rn.getDirectFollower()]++;
		}

		rn.setNoDirectFollower();
	}
	else {
		throw "Can't cancel thief";
	}
}

void Game::discardedBlueprints_reach() 
{
	discardedBlueprintLogs.push(DiscardedBlueprintLog{0});
}

void Game::discardedBlueprints_cancel() 
{
	const auto & log = discardedBlueprintLogs.pop();

	for (int i = discardedBlueprintStorage.length() - log.nbDiscardedBlueprints; i < discardedBlueprintStorage.length(); i++)
		inventory[discardedBlueprintStorage[i]]++;

	remainingTiles += log.nbDiscardedBlueprints;
	discardedBlueprintStorage.addLength(-log.nbDiscardedBlueprints);
}

Game::Game()
	: random_engine(std::random_device()())
{
	memcpy(inventory, standardInventory, sizeof(standardInventory));
	
	reachablePositions.push(Position{ 0,0 });

	discardedBlueprintLogs.push(DiscardedBlueprintLog{ 0 });

	memset(scores, 0, sizeof(scores));
	for (int & i : followers) i = NUMBER_OF_FOLLOWERS;

}

//*
int Game::nextBlueprintIndex()
{
	if (remainingTiles == 0)
		throw "No remaining tiles.";

	if (remainingTiles != NUMBER_OF_TILES) {
		std::uniform_int_distribution<int> uniform_dist(0, remainingTiles - 1);
		int numTB = uniform_dist(random_engine);
		int indexTB;

		for (indexTB = 0; indexTB < NUMBER_OF_DISTINCT_TILES && numTB >= inventory[indexTB]; numTB -= inventory[indexTB], indexTB++);

		if (indexTB == NUMBER_OF_DISTINCT_TILES)
			throw "The number of remaining tiles is wrong.";

		return indexTB;
	}
	else {
		const int indexTB = 19;
		return indexTB;
	}
}
//*/
/*
int Game::nextBlueprintIndex() {
	static const int nums[] = {10, 43, 56, 60, 11, 14, 39, 33, 46, 33, 4, 42, 45, 45, 15, 32, 28, 52, 47, 48, 10, 29, 12, 8, 10, 7, 23, 17, 10, 17, 32, 4, 21, 28, 33, 17, 24, 23, 25, 15, 19, 22, 15, 2, 6, 25, 19, 23, 10, 8, 3, 13, 5, 6, 0, 12, 4, 8, 12, 8, 1, 0, 0, 3, 6, 0, 1, 0, 0, 1, 0};
	
	if (remainingTiles == 0)
		throw "No remaining tiles.";

	if (remainingTiles != NUMBER_OF_TILES) {
		int numTB = nums[tiles.length()-1];
		int indexTB;

		for (indexTB = 0; indexTB < NUMBER_OF_DISTINCT_TILES && numTB >= inventory[indexTB]; numTB -= inventory[indexTB], indexTB++);

		if (indexTB == NUMBER_OF_DISTINCT_TILES)
			throw "The number of remaining tiles is wrong.";

		return indexTB;
	}
	else {
		const int indexTB = 19;
		return indexTB;
	}
}
//*/

void Game::discardBlueprint(IndexBlueprint i) 
{
	remainingTiles--;
	inventory[i]--;

	discardedBlueprintLogs.last().nbDiscardedBlueprints++;

	discardedBlueprintStorage.push(i);
}

void Game::setTile(int indexReachablePosition, IndexBlueprint indexBlueprint, const Direction & direction)
{
	discardedBlueprints_reach();
	tiles_reach(getReachablePosition(indexReachablePosition), indexBlueprint, direction);
	reachablePositions_reach(indexReachablePosition);
	followerLogs.push(FollowerLog{});
}

bool Game::canSetTile(const Position & p, const TileBlueprint & tb, const Direction & direction) const 
{
	for (int i = 0; i < 4; i++) {
		auto idxPosition = getIndexPosition(p.next(Direction{ i }));
		if (idxPosition != -1)
			if (!getTile(idxPosition).compatible(tb, direction, Direction{ i }))
				return false;
	}
	return true;
}

bool Game::canSetMonk() const 
{
	return getBlueprint(tiles.last().getIndexBlueprint()).hasCloister() && !followerLogs.last().hasFollower();
}

void Game::setMonk() 
{
	auto & c = cloisters.last();

	if (!c.hasDirectFollower() && !followerLogs.last().hasFollower()) {
		followerLogs.last().setMonk();

		const int indexPlayer = getCurrentPlayer();
		c.setDirectFollower(indexPlayer);
		if (c.isCompleted())
			scores[indexPlayer] += c.score();
		else
			followers[indexPlayer]--;
	}
	else {
		throw "Can't set monk. Cloister already occupied, and according to the logs, a follower has already been set this turn.";
	}
}

void Game::cancelMonk() 
{
	auto & c = cloisters.last();

	if (c.hasDirectFollower() && followerLogs.last().hasMonk()) {
		followerLogs.last().setNoFollower();

		const int indexPlayer = c.getDirectFollower();
		c.setNoDirectFollower();
		if (c.isCompleted())
			scores[indexPlayer] -= c.score();
		else
			followers[indexPlayer]++;
	}
	else {
		throw "Can't cancel monk. Cloister not occupied, or a follower has not been set, or the follower is not a monk.";
	}
}

int Game::waysToSetThief() const 
{
	int nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfRoadNodes();
	int first = roadnodes.length() - nbNodes;
	int ways = 0;

	for (int relativIdxRoadnode = 0; relativIdxRoadnode < nbNodes; relativIdxRoadnode++) {
		const RoadNode & rn = roadnodes[first + relativIdxRoadnode];
		if (rn.canSetThief())
			ways++;
	}

	return ways;
}

void Game::setThief(int wayThief) 
{
	int nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfRoadNodes();
	int first = roadnodes.length() - nbNodes;
	int ways = 0;

	for (int relativIdxRoadnode = 0; relativIdxRoadnode < nbNodes; relativIdxRoadnode++) {
		RoadNode & rn = roadnodes[first + relativIdxRoadnode];
		if (rn.canSetThief()) {
			if (ways == wayThief) {

				setThiefOnRoadnode(first + relativIdxRoadnode);
				return;
			}

			ways++;
		}
	}
}

void Game::cancelThief(int wayThief) 
{
	int nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfRoadNodes();
	int first = roadnodes.length() - nbNodes;
	int ways = 0;

	for (int relativIdxRoadnode = 0; relativIdxRoadnode < nbNodes; relativIdxRoadnode++) {
		RoadNode & rn = roadnodes[first + relativIdxRoadnode];
		if (rn.canSetThief()) {
			if (ways == wayThief) {

				cancelThiefOnRoadnode(first + relativIdxRoadnode);
				return;
			}

			ways++;
		}
	}
}

void Game::cancel()
{
	const auto & lastP = positions.last();

	tiles_cancel();
	reachablePositions_cancel(lastP);
	discardedBlueprints_cancel();
	followerLogs.pop();
}

void Game::end()
{
	auto nbCloisters = getNumberCloisters();
	
	for (int idxCloister = 0; idxCloister < nbCloisters; idxCloister++) {
		const auto & c = getCloister(idxCloister);
		if (!c.isCompleted() && c.hasDirectFollower())
			scores[c.getDirectFollower()] += c.score();
	}
	
	auto nbRoadnodes = getNumberRoadNodes();

	for (int idxRoadnode = 0; idxRoadnode < nbRoadnodes; idxRoadnode++) {
		const auto & rn = getRoadNode(idxRoadnode);
		if (!rn.hasFather() && !rn.isCompleted() && rn.hasAnyFollower()) {
			int maxF = rn.getMaxFollower();
			int t_score = rn.score();
			for (int idxPlayer = 0; idxPlayer < NUMBER_OF_PLAYERS; idxPlayer++)
				if (rn.getCumulatedFollower(idxPlayer) == rn.getMaxFollower())
					scores[idxPlayer] += t_score;
		}
	}

}



