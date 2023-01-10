#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_left : public solver
		{
		private:
			state move();

		public:
			solver_left(const labyrinth& l) : solver(l) {}
			~solver_left() = default;
		};

		state solver_left::move() {

			if (!this->lab.move(Left)) this->lab.character_rotate(Right);

			return running;
		}
	}
}
