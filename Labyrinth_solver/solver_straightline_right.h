#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_straightline_right : public solver
		{
		private:
			state move();

		public:
			solver_straightline_right(labyrinth l) : solver(l) {}
		};

		state solver_straightline_right::move() {

			if (!this->lab.move(East)) {
				if (!this->lab.move(South)) return defeat;
			}

			return running;
		}
	}
}