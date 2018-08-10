#include <iostream>
#include "MainTest.h"
#include "MainTest2.h"

int main(int argc, char * argv[]) {
	if (argc >= 2) {
		switch (argv[1][0]) {
		case 'r':
			try { roadnodeOnePlayer(); } catch (const char * msg) { std::cerr << msg; }
			break;
		case 'c':
			try { cloisterOnePlayer(); } catch (const char * msg) { std::cerr << msg; }
			break;
		case 'b':
			try { bothOnePlayer(); } catch (const char * msg) { std::cerr << msg; }
			break;
		case 'k':
			try { citiesRoadsAndCloisters_OnePlayer(); } catch (const char *msg) { std::cerr << msg; }
			break;
		default:
			std::cerr << "First argument must be 'r' or 'c'.";
			break;
		}
	} else {
		std::cerr << "Gimme at least one argument.";
		//try { roadnodeOnePlayer(); } catch (const char * msg) { std::cerr << msg; }
		try { citiesRoadsAndCloisters_OnePlayer(); } catch (const char *msg) { std::cerr << msg; }
	}
	


	return 0;
}

