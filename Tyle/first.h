#pragma once

#define NUMBER_OF_TILES 72
#define NUMBER_OF_DISTINCT_TILES 24

#define SQUARE_HALF_SIDE_LENGTH 12

//#define NUMBER_OF_PLAYERS 4
#define NUMBER_OF_PLAYERS 1
#define NUMBER_OF_FOLLOWERS 6
#define NUMBER_OF_CLOISTERS 6

#define NUMBER_OF_ROADNODES 62
#define NUMBER_OF_CITYNODES 49
#define NUMBER_OF_FIELDNODES 126

#define MAX_AMBIGIOUS_POSITIONS_FOR_CITYNODE 5

#define NUMBER_OF_CITYNODES_HAVING_NO_FIELD 1
#define NUMBER_OF_CITYNODES_HAVING_ONE_FIELD 42
#define NUMBER_OF_CITYNODES_HAVING_TWO_FIELDS 6
#define NUMBER_OF_FIELDNODES_HAVING_NO_CITY 77
#define NUMBER_OF_FIELDNODES_HAVING_ONE_CITY 44
#define NUMBER_OF_FIELDNODES_HAVING_TWO_CITIES 5

#define MAX_NUMBER_INDEX_NEIGHBOR_FIELDS 1503
#define MAX_NUMBER_INDEX_NEIGHBOR_CITIES 5618
/* NUMBER_OF_FIELDNODES_HAVING_TWO_CITIES * (NUMBER_OF_FIELDNODES_HAVING_TWO_CITIES + 1)
 * + 2 * NUMBER_OF_FIELDNODES_HAVING_TWO_CITIES * NUMBER_OF_FIELDNODES_HAVING_ONE_CITY + (NUMBER_OF_FIELDNODES_HAVING_ONE_CITY + 1) * NUMBER_OF_FIELDNODES_HAVING_ONE_CITY / 2
 * + (2 * NUMBER_OF_FIELDNODES_HAVING_TWO_CITIES + NUMBER_OF_FIELDNODES_HAVING_ONE_CITY) * NUMBER_OF_FIELDNODES_HAVING_NO_CITY
 */

#define MAX_CITYNODES_PER_TILE 2
#define MAX_ROADNODES_PER_TILE 4
#define MAX_FIELDNODES_PER_TILE 4
