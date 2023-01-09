#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_straightline_right : solver
		{
		private:

			friend state labyrinth_solver::solvers::solver_straightline_right::solver::move();

		public:
			solver_straightline_right(labyrinth l) : solver(l) {}
		};

		state solver_straightline_right::solver::move() {

			if (!this->lab.move(Right)) {
				if (!this->lab.move(Down)) return defeat;
			}

			return running;
		}
	}
}