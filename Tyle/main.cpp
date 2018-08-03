#include <iostream>
#include "MainTest.h"


int main(int argc, char * argv[]) {
	
	if (argc >= 2) {
		if (argv[1][0] == 'r') {

			try {
				roadnodeOnePlayer();
			}
			catch (const char * msg) {
				std::cerr << msg;
			}
		} else {
			if (argv[1][0] == 'c') {
				try {
					cloisterOnePlayer();
				}
				catch (const char * msg) {
					std::cerr << msg;
				}
			} else {
				if (argv[1][0] == 'b') {
					try {
						bothOnePlayer();
					}
					catch (const char * msg) {
						std::cerr << msg;
					}
				} else {
					std::cerr << "First argument must be 'r' or 'c'.";
				}
			}
		}
	} else {
		std::cerr << "Gimme at least one argument.";
		try {
			roadnodeOnePlayer();
		}
		catch (const char * msg) {
			std::cerr << msg;
		}
	}
	


	return 0;
}

