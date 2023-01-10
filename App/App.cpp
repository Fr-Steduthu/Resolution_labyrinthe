#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

#define INCLUDE_SOLVERS
#include "../Labyrinth_solver/framework.h"


void study(const labyrinth_solver::labyrinth& l) {
	std::vector<std::thread> solvers;
	//std::vector<std::chrono::duration> durations;

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
			LOG("solver_right fini");
		}
	));


	solvers.push_back(std::thread(
		[&l]() {
			labyrinth_solver::solvers::solver_straightline_right solv(l);
			solv.solve();
			LOG("solver_straightline_right fini");
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
		if (s == "up") { c.move(labyrinth_solver::direction::North); }
		if (s == "down") { c.move(labyrinth_solver::direction::South); }
		if (s == "left") { c.move(labyrinth_solver::direction::West); }
		if (s == "right") { c.move(labyrinth_solver::direction::East); }
		std::cout << c << std::endl;
	}

	std::cout << "Game over ; took " << c.character().path_taken().steps_taken() << " steps." << std::endl;

	return std::move(c);
}

int main(int argc, char * argv[])
{
	if (argc != 2) return -2;

	std::ifstream f(argv[1]);
	labyrinth_solver::labyrinth n(f);

	study(n);

	return 0;
}
