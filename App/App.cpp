#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "../Labyrinth_solver/pch.h"


labyrinth_solver::labyrinth&& play(labyrinth_solver::labyrinth&& c) {

	std::cout << "Game starting" << std::endl;

	while (!c.is_won()) {
		std::cout.flush();
		std::string s;
		std::getline(std::cin, s);
		if (s == "up") { c.move(labyrinth_solver::direction::Up); }
		if (s == "down") { c.move(labyrinth_solver::direction::Down); }
		if (s == "left") { c.move(labyrinth_solver::direction::Left); }
		if (s == "right") { c.move(labyrinth_solver::direction::Right); }
		std::cout << c << std::endl;
	}

	std::cout << "Game over ; took " << c.character().path_taken().steps_taken() << " steps." << std::endl;

	return std::move(c);
}

int main()
{
	std::ifstream data_input("C:\\Users\\erwan\\Documents\\GitHub\\Resolution_labyrinthe\\App\\lab3_3x3.txt"); //Probleme a la lecture ; UTF-8 en cause ?
	std::ostringstream data("");

	while (!data_input.eof()) {
		std::string s;
		std::getline(data_input, s);
		data << s << (data_input.eof() ? "" : "\n");
	}

	std::string d("   #######\n         #\n####  ####\n#     #  #\n#  #  #  #\n#  #      \n#######   \n");

	labyrinth_solver::labyrinth lab(data.str());

	//std::cout << (std::string) lab;

	std::cout << lab;

	lab.move(labyrinth_solver::Down);

	std::cout << (std::string) lab;

	labyrinth_solver::labyrinth over(std::move(play(std::move(lab))));

	//lab.character().path_taken();

	return 0;
}
