#include "Game.h"
#include <string>
#include "Neighborhood.h"

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

	//*
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
	//*/

	/*
	for (auto j = 0; j < 4; j++)
		if (!alreadyIn[j] && (isReachable(nearPos[j]) || isOccupied(nearPos[j]))) {
			alreadyIn[j] = true;
			nbNewPos--;
		}
	*/

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

	if (tb.hasCloister())
		cloisters.reachNewCloister(p, [&](const Position & p) { return positions.find(p); });
	else
		cloisters.reachNoCloister(p);
	
	roads.add(tb.getRoadNodeBlueprints());
	linkRoads(p);
	roads.checkForCompletedNodes();
	
	cities.add(tb.getCityNodeBlueprints());
	linkCities(p);
	cities.checkForCompletedNodes();

	fields.add(tb.getFieldNodeBlueprints());
	linkFields(p);
	
	setNeighbors_OfManyFields(fields, tb.getFieldNodeBlueprints(), cities);
}

void Game::tiles_cancel() 
{
	const auto & t = tiles.pop();
	const auto & tb = getBlueprint(t.getIndexBlueprint());

	cloisters.cancel(positions.pop());
	
	roads.cancel();
	cities.cancel();
	fields.cancel();

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



void Game::linkCities(const Position & p)
{
	auto & t = tiles.last();
	const auto & tb = getBlueprint(t.getIndexBlueprint());
	const auto first = cities.getNumberOfNodes() - tb.getNumberOfCityNodes();

	// initialisation des noeuds de route
	for (int i = 0; i < 4; i++) {
		const Direction d{ i };
		const Direction dTr = d.rotateTrigo(t.getDirection());

		if (tb.getSideType(dTr) == SideType::City) {
			
			const auto relativIdxCitynode = tb.getCityNode(dTr);
			const auto idxCitynode = first + relativIdxCitynode;

			t.setCityNode(d, idxCitynode);

			const auto indexNextTile = getIndexPosition(p.next(d));
			if (indexNextTile != -1) {
				
				const auto rootNextCn    = cities.getIndexOfRoot(getTile(indexNextTile).getCityNode(d.opposite()));
				const auto rootCurrentCn = cities.getIndexOfRoot(idxCitynode);

				if (rootCurrentCn != rootNextCn)
					cities.makeFatherAndSon(rootCurrentCn, rootNextCn);
			}
		}
	}
}

void Game::linkFields(const Position & p)
{
	auto & t = tiles.last();
	const auto & tb = getBlueprint(t.getIndexBlueprint());
	const auto first = fields.getNumberOfNodes() - tb.getNumberOfFieldNodes();

	// initialisation des noeuds de route
	for (int i = 0; i < 4; i++) {
		const Direction d{ i };
		const Direction dTr = d.rotateTrigo(t.getDirection());

		if (tb.getSideType(dTr) == SideType::Field) {
			const auto relativIdxFieldnode = tb.getFieldNode(dTr);
			const auto idxFieldnode = first + relativIdxFieldnode;

			t.setFieldNode(d, idxFieldnode);

			const auto indexNextTile = getIndexPosition(p.next(d));
			if (indexNextTile != -1) {
				const auto rootNextFn = fields.getIndexOfRoot(getTile(indexNextTile).getFieldNode(d.opposite()));
				const auto rootCurrentFn = fields.getIndexOfRoot(idxFieldnode);

				if (rootCurrentFn != rootNextFn)
					fields.makeFatherAndSon(rootCurrentFn, rootNextFn);
			}
		}
		else {
			if (tb.getSideType(dTr) == SideType::Road) {
				{
					const auto relativIdxFilednode = tb.getLeftFieldNode(dTr);
					const auto idxFieldnode = first + relativIdxFilednode;

					t.setLeftFieldNode(d, idxFieldnode);

					const auto indexNextTile = getIndexPosition(p.next(d));
					if (indexNextTile != -1) {
						const auto rootNextFn = fields.getIndexOfRoot(getTile(indexNextTile).getRightFieldNode(d.opposite()));
						const auto rootCurrentFn = fields.getIndexOfRoot(idxFieldnode);
						if (rootCurrentFn != rootNextFn)
							fields.makeFatherAndSon(rootCurrentFn, rootNextFn);
					}
				}
				{
					const auto relativIdxFilednode = tb.getRightFieldNode(dTr);
					const auto idxFieldnode = first + relativIdxFilednode;

					t.setRightFieldNode(d, idxFieldnode);

					const auto indexNextTile = getIndexPosition(p.next(d));
					if (indexNextTile != -1) {
						const auto rootNextFn = fields.getIndexOfRoot(getTile(indexNextTile).getLeftFieldNode(d.opposite()));
						const auto rootCurrentFn = fields.getIndexOfRoot(idxFieldnode);
						if (rootCurrentFn != rootNextFn)
							fields.makeFatherAndSon(rootCurrentFn, rootNextFn);
					}
				}
			}
		}
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
	: random_engine(std::random_device()()), farmerScores(0)
{
	memcpy(inventory, standardInventory, sizeof(standardInventory));
	
	reachablePositions.push(Position{ 0,0 });

	discardedBlueprintLogs.push(DiscardedBlueprintLog{ 0 });

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

int Game::waysToSetKnight() const { return cities.waysToSetFollower(); }

void Game::setKnight(int wayKnight)
{
	const auto idxCity = cities.setFollower(wayKnight, currentPlayer);
	const auto dir = tiles.last().getFirstDirectionOfCitynode(idxCity);
	followerLogs.last().setKnight(dir);
}

void Game::cancelKnight(int wayKnight)
{
	followerLogs.last().setNoFollower();
	cities.cancelFollower(wayKnight);
}

int Game::waysToSetFarmer() const { return fields.waysToSetFollower(); }

void Game::setFarmer(int wayFarmer)
{
	const auto idxField = fields.setFollower(wayFarmer, currentPlayer);
	const auto dir = tiles.last().getFirstDirectionOfFieldnode(idxField);
	followerLogs.last().setFarmer(dir);
}

void Game::cancelFarmer(int wayFarmer)
{
	followerLogs.last().setNoFollower();
	fields.cancelFollower(wayFarmer);
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
	cities.noticeEnd();
	farmerScores = countEndFarmerScore(fields, cities);
}

void Game::cancelEnd()
{
	cloisters.unnoticeEnd();
	roads.unnoticeEnd();
	cities.unnoticeEnd();
	farmerScores.reset(0);
}





}