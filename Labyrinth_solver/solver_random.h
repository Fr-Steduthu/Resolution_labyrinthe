#pragma once

#include "solver.h"
#include <random>
#include <ctime> //Pour rand

namespace labyrinth_solver {
	namespace solvers {
		class solver_random : solver {
		public:
			solver_random(labyrinth l) : solver(l) {}
		};

		state solver_random::solver::move() {
			
		}
	}
}

