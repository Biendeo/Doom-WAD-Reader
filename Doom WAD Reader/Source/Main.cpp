#include <iostream>
#include <string>

#include "WAD.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo;
	if (argc != 2) {
		std::cerr << "Please run with a WAD path.\n";
		return EXIT_FAILURE;
	}

	char* wadLocation = argv[1];

	// TODO: Use fewer pointers and switch to smart pointers.
	WAD* testWad = nullptr;

	try {
		testWad = new WAD(wadLocation);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}

	testWad->Write("test.wad");

	delete testWad;

	return EXIT_SUCCESS;
}