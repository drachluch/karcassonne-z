#pragma once
#include "Game.h"
#include <ostream>

namespace kar {
	void writeMap20180729(std::ostream & out, const Game & g);

	// !! attention : la partie est d�roul�e dans le sens oppos�, ce qui la laissera dans l'�tat de d�part d'une partie vierge.
	void writeStats20180817(std::ostream & out, Game & g);
}

