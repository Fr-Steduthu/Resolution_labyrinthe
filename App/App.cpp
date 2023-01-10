#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

#define INCLUDE_SOLVERS
#include "../Labyrinth_solver/framework.h"

template<typename solverClass, int i>
void __thrd(const labyrinth_solver::labyrinth& l, std::vector<std::time_t> * vec) {
	solverClass solv(l);

	std::chrono::system_clock::time_point s = std::chrono::system_clock::now();
	solv.solve();
	vec->operator[](i) = 489456151;//std::chrono::system_clock::to_time_t(s) - std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

void study(const labyrinth_solver::labyrinth& l) {
	std::vector<std::thread> solvers;
	std::vector<std::time_t> durations(5);
	std::vector<std::string> names{"solver_left", "solver_left_alt", "solver_random", "solver_right", "solver_straigthline"};

	solvers.push_back(std::thread([&l, &durations]() {__thrd<labyrinth_solver::solvers::solver_left, 0>(l, &durations);}));

	solvers.push_back(std::thread([&l, &durations]() {__thrd<labyrinth_solver::solvers::solver_left_alt, 1>(l, &durations);}));

	solvers.push_back(std::thread([&l, &durations]() {__thrd<labyrinth_solver::solvers::solver_random, 2>(l, &durations);}));

	solvers.push_back(std::thread([&l, &durations]() {__thrd<labyrinth_solver::solvers::solver_right, 3>(l, &durations);}));

	solvers.push_back(std::thread([&l, &durations]() {__thrd<labyrinth_solver::solvers::solver_straightline_right, 4>(l, &durations);}));



	size_t i = 0;
	for (std::thread& t : solvers) {
		t.join();
		std::cout << "Solver " << names[i] << " took " << (durations[i] / 1000) << "ms" << std::endl;
		i++;
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
