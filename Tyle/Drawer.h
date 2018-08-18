#pragma once
#include "Game.h"
#include <ostream>

namespace kar {
	void writeMap20180729(std::ostream & out, const Game & g);

	// !! attention : la partie est déroulée dans le sens opposé, ce qui la laissera dans l'état de départ d'une partie vierge.
	void writeStats20180817(std::ostream & out, Game & g);
}

