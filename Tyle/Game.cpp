#include "Game.h"
#include <string>
#include "BlocStaticSorted.h"

namespace kar {

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

	const auto & tb = getBlueprint(indexBlueprint);

	tiles.push(Tile{ indexBlueprint, tb, direction });
	positions.push(p);

	if (tb.hasCloister()) {
		auto lambda = [&](const Position & p) { return positions.find(p); };
		
		cloisters.reachNewCloister(p, lambda);
	}
	else
		cloisters.reachNoCloister(p);
	
	roads.add(tb.getRoadNodeBlueprints());
	linkRoads(p);
	roads.checkForCompletedNodes();

	const auto idxTile = tiles.length() - 1;

	if (tb.getNumberOfCityNodes() > 0)
		citynodes_reach(p, idxTile);
	if (tb.getNumberOfFieldNodes() > 0)
		fieldnodes_reach(p, idxTile);

	if (tb.getNumberOfCityNodes() > 0)
		citynodes_setNeighbors(idxTile);
	if (tb.getNumberOfFieldNodes() > 0)
		fieldnodes_setNeighbors(idxTile);
}

void Game::tiles_cancel() 
{
	const auto & t = tiles.pop();
	const auto & tb = getBlueprint(t.getIndexBlueprint());

	cloisters.cancel(positions.pop());
	
	roads.cancel();

	if (tb.getNumberOfCityNodes() > 0)
		citynodes_cancel(tb.getNumberOfCityNodes());
	if (tb.getNumberOfFieldNodes() > 0)
		fieldnodes_cancel(tb.getNumberOfFieldNodes());
	
	inventory[t.indexBlueprint]++;

	remainingTiles++;
}

void Game::linkRoads(const Position & p)
{
	auto & t = tiles.last();
	const auto & tb = getBlueprint(t.getIndexBlueprint());
	const auto first = roads.getNumberOfNodes() - tb.getNumberOfRoadNodes();

	// initialisation des noeuds de route
	for (int i = 0; i < 4; i++) {
		const Direction d{ i };
		const Direction dTr = d.rotateTrigo(t.getDirection());

		if (tb.getSideType(dTr) == SideType::Road) {
			const auto relativIdxRoadnode = tb.getRoadNode(dTr);
			const auto idxRoadnode = first + relativIdxRoadnode;

			t.setRoadNode(d, idxRoadnode);

			const auto indexNextTile = getIndexPosition(p.next(d));
			if (indexNextTile != -1) {

				auto rootNextRn = roads.getIndexOfRoot(getTile(indexNextTile).getRoadNode(d.opposite()));
				auto rootCurrentRn = roads.getIndexOfRoot(idxRoadnode);

				// you can't become your own father
				// and nextRn.getRoot() can't be a child, because it's the result of getRoot()
				if (rootCurrentRn != rootNextRn)
					roads.makeFatherAndSon(rootCurrentRn, rootNextRn);
			}
		}
	}
}

void Game::citynodes_reach(const Position & p, int idxTile)
{
	auto & t = tiles[idxTile];
	auto & tb = getBlueprint(t.getIndexBlueprint());

	auto first = citynodes.length();
	auto nbNodes = tb.getNumberOfCityNodes();
	citynodes.addLength(nbNodes);
	bool set[MAX_CITYNODES_PER_TILE] = { false, false };

	// initialisation des noeuds de ville
	for (int i = 0; i < 4; i++) {
		const Direction d{ i };
		const Direction dTr = d.rotateTrigo(t.getDirection());

		if (tb.getSideType(dTr) == SideType::City) {
			auto relativIdxCitynode = tb.getCityNode(dTr);

			t.setCityNode(d, first + relativIdxCitynode);

			if (!set[relativIdxCitynode]) {
				// nbNodes > 1 => position ambigue
				auto & bp = tb.getCityNodeBlueprint(relativIdxCitynode);

				if (nbNodes > 1)
					citynodes[first + relativIdxCitynode].reset(tb.getCityNodeBlueprint(relativIdxCitynode), idxTile);
				else
					citynodes[first + relativIdxCitynode].reset(tb.getCityNodeBlueprint(relativIdxCitynode));

				set[relativIdxCitynode] = true;
			}
		}
	}

	// interaction avec les noeuds des tuiles adjacentes
	for (int i = 0; i < 4; i++) {
		const Direction d{ i };

		if (t.getSideType(d) == SideType::City) {
			auto idxCitynode = t.getCityNode(d);
			auto & cn = citynodes[idxCitynode];

			int indexNextTile = getIndexPosition(p.next(d));
			if (indexNextTile != -1) {

				auto & rootNextCn = citynodes[getTile(indexNextTile).getCityNode(d.opposite())].getRoot();
				auto & rootCurrentCn = cn.getRoot();

				// you can't become your own father
				// and nextRn.getRoot() can't be a child, because it's the result of getRoot()
				if (&rootCurrentCn != &rootNextCn) {
					rootCurrentCn.becomeFatherOf(&rootNextCn);
				}
			}
		}
	}

	// décompte des points pour les routes terminées avec des partisans déjà dessus
	for (auto relativIdxCitynode = 0; relativIdxCitynode < nbNodes; relativIdxCitynode++) {
		auto & cn = citynodes[first + relativIdxCitynode];
		if (!cn.hasFather() && cn.isCompleted() && cn.hasAnyFollower())
			updateForCompleted(cn, scores, followers);
	}
}

void Game::citynodes_setNeighbors(int idxTile)
{
	auto & t = tiles[idxTile];
	auto & tb = getBlueprint(t.getIndexBlueprint());

	auto nbNodes = tb.getNumberOfCityNodes();
	
	if (nbNodes == 1) {
		setNeighborFields(citynodes.last(), tb.getCityNodeBlueprint(0), fieldnodes, fieldnodes.length() - tb.getNumberOfFieldNodes(), neighborFields);
	}
	else if (nbNodes == 2) {
		auto first = citynodes.length() - nbNodes;
		if (citynodes[first].getDepth() == 0) {
			setNeighborFields(citynodes.last(), tb.getCityNodeBlueprint(1), fieldnodes, fieldnodes.length() - tb.getNumberOfFieldNodes(), neighborFields);
			setNeighborFields(citynodes[first], tb.getCityNodeBlueprint(0), fieldnodes, fieldnodes.length() - tb.getNumberOfFieldNodes(), neighborFields);
		}
		else {
			setNeighborFields(citynodes[first], tb.getCityNodeBlueprint(0), fieldnodes, fieldnodes.length() - tb.getNumberOfFieldNodes(), neighborFields);
			setNeighborFields(citynodes.last(), tb.getCityNodeBlueprint(1), fieldnodes, fieldnodes.length() - tb.getNumberOfFieldNodes(), neighborFields);
		}
	}
	else {
		throw "communism is a lie";
	}
}

// nbNodes > 0
void Game::citynodes_cancel(int nbNodes)
{
	auto first = citynodes.length() - nbNodes;

	for (auto relativIdxCityNode = 0; relativIdxCityNode < nbNodes; relativIdxCityNode++) {
		auto & cn = citynodes[first + relativIdxCityNode];

		if (cn.hasAnyFollower() && !cn.hasFather()) {
			if (cn.hasDirectFollower()) {
				cancelKnightOnCitynode(first + relativIdxCityNode);
			}
			else {
				if (cn.isCompleted())
					cancelUpdateForCompleted(cn, scores, followers);
			}
		}

		cn.unlinkChildren();
		neighborFields.freeSome(cn.getNeighborFields().length);
	}

	citynodes.addLength(-nbNodes);
}

void Game::fieldnodes_reach(const Position & p, int idxTile)
{
	auto & t = tiles[idxTile];
	auto & tb = getBlueprint(t.getIndexBlueprint());

	auto first = fieldnodes.length();
	auto nbNodes = tb.getNumberOfFieldNodes();
	fieldnodes.addLength(nbNodes);
	bool set[MAX_FIELDNODES_PER_TILE] = { false, false, false, false };

	// initialisation des noeuds de ville
	for (int i = 0; i < 4; i++) {
		const Direction d{ i };
		const Direction dTr = d.rotateTrigo(t.getDirection());

		if (tb.getSideType(dTr) == SideType::Field) {
			auto relativIdxFieldnode = tb.getFieldNode(dTr);

			t.setFieldNode(d, first + relativIdxFieldnode);

			if (!set[relativIdxFieldnode]) {
				fieldnodes[first + relativIdxFieldnode].reset();
				set[relativIdxFieldnode] = true;
			}
		}
	}

	// interaction avec les noeuds des tuiles adjacentes
	for (auto i = 0; i < 4; i++) {
		const Direction d{ i };

		if (t.getSideType(d) == SideType::Field) {
			auto idxFieldnode = t.getFieldNode(d);
			auto & fn = fieldnodes[idxFieldnode];

			auto indexNextTile = getIndexPosition(p.next(d));
			if (indexNextTile != -1) {

				auto & rootNextFn = fieldnodes[getTile(indexNextTile).getFieldNode(d.opposite())].getRoot();
				auto & rootCurrentFn = fn.getRoot();

				// you can't become your own father
				// and nextRn.getRoot() can't be a child, because it's the result of getRoot()
				if (&rootCurrentFn != &rootNextFn) {
					rootCurrentFn.becomeFatherOf(&rootNextFn);
				}
			}
		}
	}
}


// nbNodes > 0 !!
void Game::fieldnodes_setNeighbors(int idxTile)
{
	auto & t = tiles[idxTile];
	auto & tb = getBlueprint(t.getIndexBlueprint());

	auto nbNodes = tb.getNumberOfFieldNodes();
	auto firstCityIdx = citynodes.length() - tb.getNumberOfCityNodes();


	if (nbNodes == 1) {
		setNeighborCities(fieldnodes.last(), tb.getFieldNodeBlueprint(0), citynodes, firstCityIdx, neighborCities);
	}
	else {
		// certains fieldnodes risquent d'être apparentés.
		// il faut traiter les fils avant les pères, car le traitement des pères dépend du traitement des fils.
		auto firstFieldIdx = fieldnodes.length() - nbNodes;
		int depths[MAX_FIELDNODES_PER_TILE];
		int maxDepth = 0;

		for (auto relativIdxFieldNode = 0; relativIdxFieldNode < nbNodes; relativIdxFieldNode++) {
			depths[relativIdxFieldNode] = fieldnodes[firstFieldIdx + relativIdxFieldNode].getDepth();
			if (depths[relativIdxFieldNode] > maxDepth)
				maxDepth = depths[relativIdxFieldNode];
		}

		for (auto currentDepth = maxDepth; currentDepth >= 0; currentDepth--)
			for (auto relativIdxFieldNode = 0; relativIdxFieldNode < nbNodes; relativIdxFieldNode++)
				if (depths[relativIdxFieldNode] == currentDepth)
					setNeighborCities(fieldnodes[firstFieldIdx + relativIdxFieldNode], tb.getFieldNodeBlueprint(relativIdxFieldNode), citynodes, firstCityIdx, neighborCities);
	}
}

void Game::fieldnodes_cancel(int nbNodes)
{
	auto first = fieldnodes.length() - nbNodes;

	for (auto relativIdxFieldNode = 0; relativIdxFieldNode < nbNodes; relativIdxFieldNode++) {
		auto & fn = fieldnodes[first + relativIdxFieldNode];

		if (fn.hasDirectFollower())
			cancelFarmerOnFieldnode(first + relativIdxFieldNode);

		neighborCities.freeSome(fn.getNeighborCities().length);
		fn.unlinkChildren();
	}

	fieldnodes.addLength(-nbNodes);
}

void Game::setKnightOnCitynode(int indexCitynode)
{
	auto & cn = citynodes[indexCitynode];

	if (cn.canSetKnight() && !cn.hasDirectFollower() && !followerLogs.last().hasFollower()) {
		followerLogs.last().setKnight(tiles.last().getFirstDirectionOfCitynode(indexCitynode));

		cn.setDirectFollower(currentPlayer);
		if (cn.isCompleted()) {
			// les points sont comptés, le partisan est placé puis immédiatement remis à la réserve.
			scores[cn.getDirectFollower()] += cn.score();
		}
		else {
			// les points ne sont pas comptés, le partisan est placé.
			followers[cn.getDirectFollower()]--;
		}

	}
	else {
		throw "Can't set knight";
	}
}

void Game::cancelKnightOnCitynode(int indexCitynode)
{
	auto & cn = citynodes[indexCitynode];

	if (cn.canSetKnight() && cn.hasDirectFollower() && followerLogs.last().hasKnight()) {
		followerLogs.last().setNoFollower();

		if (cn.isCompleted()) {
			// les points ont été comptés, le partisan n'est plus sur place
			// le partisan est déjà libéré, et le score est rendu normal.
			scores[cn.getDirectFollower()] -= cn.score();
		}
		else {
			// les points n'ont pas été comptés, le partisan est toujours sur place
			// donc le score ne change pas, et le partisan est libéré.
			followers[cn.getDirectFollower()]++;
		}

		cn.setNoDirectFollower();
	}
	else {
		throw "Can't cancel knight";
	}
}

void Game::setFarmerOnFieldnode(int indexFieldnode)
{
	auto &fn = fieldnodes[indexFieldnode];

	if (fn.canSetFarmer() && !fn.hasDirectFollower() && !followerLogs.last().hasFollower()) {
		followerLogs.last().setFarmer(tiles.last().getFirstDirectionOfFieldnode(indexFieldnode));

		fn.setDirectFollower(currentPlayer);

	}
	else {
		throw "Can't set farmer";
	}
}

void Game::cancelFarmerOnFieldnode(int indexFieldnode)
{
	auto & fn = fieldnodes[indexFieldnode];

	if (fn.canSetFarmer() && fn.hasDirectFollower() && followerLogs.last().hasFarmer()) {
		followerLogs.last().setNoFollower();

		fn.setNoDirectFollower();
	}
	else {
		throw "Can't cancel farmer";
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

bool Game::canSetMonk() const { return cloisters.canSetMonk(); }

void Game::setMonk() 
{
	followerLogs.last().setMonk();
	cloisters.setMonk(getCurrentPlayer());
}

void Game::cancelMonk() 
{
	followerLogs.last().setNoFollower();
	cloisters.cancelMonk();
}

int Game::waysToSetThief() const { return roads.waysToSetFollower(); }

void Game::setThief(int wayThief) {
	const auto idxRoad = roads.setFollower(wayThief, currentPlayer);
	const auto dir = tiles.last().getFirstDirectionOfRoadnode(idxRoad);
	followerLogs.last().setThief(dir);
}

void Game::cancelThief(int wayThief) {
	followerLogs.last().setNoFollower();
	roads.cancelFollower(wayThief);
}

int Game::waysToSetKnight() const
{
	auto nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfCityNodes();
	auto first = citynodes.length() - nbNodes;
	auto ways = 0;

	for (auto relativIdxCitynode = 0; relativIdxCitynode < nbNodes; relativIdxCitynode++)
		if (citynodes[first + relativIdxCitynode].canSetKnight())
			ways++;

	return ways;
}

void Game::setKnight(int wayKnight)
{
	int nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfCityNodes();
	int first = citynodes.length() - nbNodes;
	int ways = 0;

	for (int relativIdxCitynode = 0; relativIdxCitynode < nbNodes; relativIdxCitynode++) {
		auto & cn = citynodes[first + relativIdxCitynode];
		if (cn.canSetKnight()) {
			if (ways == wayKnight) {

				setKnightOnCitynode(first + relativIdxCitynode);
				return;
			}

			ways++;
		}
	}
}

void Game::cancelKnight(int wayKnight)
{
	int nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfCityNodes();
	int first = citynodes.length() - nbNodes;
	int ways = 0;

	for (int relativIdxCitynode = 0; relativIdxCitynode < nbNodes; relativIdxCitynode++) {
		auto & cn = citynodes[first + relativIdxCitynode];
		if (cn.canSetKnight()) {
			if (ways == wayKnight) {

				cancelKnightOnCitynode(first + relativIdxCitynode);
				return;
			}

			ways++;
		}
	}
}

int Game::waysToSetFarmer() const
{
	auto nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfFieldNodes();
	auto first = fieldnodes.length() - nbNodes;
	auto ways = 0;

	for (auto relativIdxFieldnode = 0; relativIdxFieldnode < nbNodes; relativIdxFieldnode++)
		if (fieldnodes[first + relativIdxFieldnode].canSetFarmer())
			ways++;

	return ways;
}

void Game::setFarmer(int wayFarmer)
{
	int nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfFieldNodes();
	int first = fieldnodes.length() - nbNodes;
	int ways = 0;

	for (int relativIdxFieldnode = 0; relativIdxFieldnode < nbNodes; relativIdxFieldnode++) {
		auto & fn = fieldnodes[first + relativIdxFieldnode];
		if (fn.canSetFarmer()) {
			if (ways == wayFarmer) {

				setFarmerOnFieldnode(first + relativIdxFieldnode);
				return;
			}

			ways++;
		}
	}
}

void Game::cancelFarmer(int wayFarmer)
{
	int nbNodes = getBlueprint(tiles.last().getIndexBlueprint()).getNumberOfFieldNodes();
	int first = fieldnodes.length() - nbNodes;
	int ways = 0;

	for (int relativIdxFieldnode = 0; relativIdxFieldnode < nbNodes; relativIdxFieldnode++) {
		auto & fn = fieldnodes[first + relativIdxFieldnode];
		if (fn.canSetFarmer()) {
			if (ways == wayFarmer) {

				cancelFarmerOnFieldnode(first + relativIdxFieldnode);
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
	cloisters.noticeEnd();
	roads.noticeEnd();
}

void setNeighborFields(CityNode & cn, const CityNodeBlueprint & cnb, const Array<FieldNode, NUMBER_OF_FIELDNODES>& fieldnodes, int firstField, NeighborStack<char, MAX_NUMBER_INDEX_NEIGHBOR_FIELDS>& neighborFields)
{
	BlocStaticSorted<char, NUMBER_OF_FIELDNODES> cumulatedAdjacentFieldNodes;
	auto nbAdjacentFieldNodes = cnb.getNumberAdjacentFieldNodes();

	if (nbAdjacentFieldNodes > 0) {
		const int * p = cnb.getAdjacentFieldNodes();
		for (auto i = 0; i < nbAdjacentFieldNodes; i++)
			cumulatedAdjacentFieldNodes.insert(fieldnodes.getIndex(&fieldnodes[p[i] + firstField].getRoot()));
	}

	auto sons = cn.getChildren();

	for (auto idxSonWithinFather = 0; idxSonWithinFather < sons.length(); idxSonWithinFather++) {
		auto & cnSon = *sons[idxSonWithinFather];
		auto & blocSonAdjacentFieldNodes = cnSon.getNeighborFields();
		for (auto idxSonAdjacentFieldNode = 0; idxSonAdjacentFieldNode < blocSonAdjacentFieldNodes.length; idxSonAdjacentFieldNode++)
			cumulatedAdjacentFieldNodes.insert(fieldnodes.getIndex(&fieldnodes[blocSonAdjacentFieldNodes[idxSonAdjacentFieldNode]].getRoot()));
	}

	auto bloc = neighborFields.getSome(cumulatedAdjacentFieldNodes.length());
	// copy of sorted cumulatedAdjacentFieldNodes
	for (auto i = 0; i < bloc.length; i++)
		bloc[i] = cumulatedAdjacentFieldNodes[i];

	cn.setNeighborFields(bloc);
}

void setNeighborCities(FieldNode & fn, const FieldNodeBlueprint & fnb, const Array<CityNode, NUMBER_OF_CITYNODES> & citynodes, int firstCity, NeighborStack<char, MAX_NUMBER_INDEX_NEIGHBOR_CITIES> & neighborCities)
{
	BlocStaticSorted<char, NUMBER_OF_CITYNODES> cumulatedAdjacentCityNodes;
	auto nbAdjacentCityNodes = fnb.getNumberAdjacentCityNodes();

	if (nbAdjacentCityNodes > 0) {
		const int * p = fnb.getAdjacentCityNodes();
		for (auto i = 0; i < nbAdjacentCityNodes; i++)
			cumulatedAdjacentCityNodes.insert(citynodes.getIndex(&citynodes[p[i] + firstCity].getRoot()));
	}

	auto sons = fn.getChildren();

	for (auto idxSonWithinFather = 0; idxSonWithinFather < sons.length(); idxSonWithinFather++) {
		auto & fnSon = *sons[idxSonWithinFather];
		auto & blocSonAdjacentCityNodes = fnSon.getNeighborCities();
		for (auto idxSonAdjacentFieldNode = 0; idxSonAdjacentFieldNode < blocSonAdjacentCityNodes.length; idxSonAdjacentFieldNode++)
			cumulatedAdjacentCityNodes.insert(citynodes.getIndex(&citynodes[blocSonAdjacentCityNodes[idxSonAdjacentFieldNode]].getRoot()));
	}

	auto bloc = neighborCities.getSome(cumulatedAdjacentCityNodes.length());
	// copy of sorted cumulatedAdjacentFieldNodes
	for (auto i = 0; i < bloc.length; i++)
		bloc[i] = cumulatedAdjacentCityNodes[i];

	fn.setNeighborCities(bloc);
}



}