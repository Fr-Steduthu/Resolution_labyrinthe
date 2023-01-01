#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "../Labyrinth_solver/labyrinth.h"

int main()
{
	std::ifstream data_input("./lab3_3x3.txt");
	std::ostringstream data("");
	while (!data_input.eof()) {
		data << data_input.get();
	}

	labyrinth::dungeon lab(data.str());

	std::cout << std::string(lab);
}
