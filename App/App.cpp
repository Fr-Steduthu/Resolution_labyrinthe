#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "../Labyrinth_solver/labyrinth.h"

int main()
{
	std::ifstream data_input("C:\\Users\\erwan\\Documents\\GitHub\\Resolution_labyrinthe\\App\\lab3_3x3.txt"); //Probleme a la lecture ; UTF-8 en cause ?
	std::ostringstream data("");
	while (!data_input.eof()) {
		data << data_input.get();
	}

	std::string d("   #######\n         #\n####  ####\n#     #  #\n#  #  #  #\n#  #      \n#######   ");

	labyrinth::dungeon lab(d);

	std::cout << std::string(lab);
}
