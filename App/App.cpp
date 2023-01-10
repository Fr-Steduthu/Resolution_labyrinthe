#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <thread>

#define INCLUDE_SOLVERS
#include "../Labyrinth_solver/pch.h"


void study(labyrinth_solver::labyrinth&& l) {
	std::vector<std::thread> solvers;

	solvers.push_back(std::thread(
		[l]() {
			labyrinth_solver::solvers::solver_left solv(l);
			solv.solve();
			LOG("solver_left fini");
		}
	));


	solvers.push_back(std::thread(
		[l]() {
			labyrinth_solver::solvers::solver_left_alt solv(l);
			solv.solve();
			LOG("solver_left_alt fini");
		}
	));


	solvers.push_back(std::thread(
		[l]() {
			labyrinth_solver::solvers::solver_random solv(l);
			solv.solve();
			LOG("solver_random fini");
		}
	));


	solvers.push_back(std::thread(
		[l]() {
			labyrinth_solver::solvers::solver_right solv(l);
			solv.solve();
			LOG("solver_random fini");
		}
	));


	solvers.push_back(std::thread(
		[l]() {
			labyrinth_solver::solvers::solver_right_alt solv(l);
			solv.solve();
			LOG("solver_random fini");
		}
	));


	solvers.push_back(std::thread(
		[&l]() {
			labyrinth_solver::solvers::solver_straightline_right solv(l);
			solv.solve();
			LOG("solver_random fini");
		}
	));

	for (std::thread& t : solvers) {
		t.join();
	}
}

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

int main(int argc, char * argv[])
{
	LOG(argc << " : " << argv[1]);
	if (argc != 2) return -2;

	std::ifstream f(argv[1]);
	labyrinth_solver::labyrinth n(f);

	labyrinth_solver::solvers::solver_left_alt solv(n);
	LOG("Solver built");
	std::cout << solv.solve().steps_taken() << std::endl;
	LOG("Solver over");

	//study(labyrinth_solver::labyrinth(std::ifstream(argv[1])));

	return 0;
}
