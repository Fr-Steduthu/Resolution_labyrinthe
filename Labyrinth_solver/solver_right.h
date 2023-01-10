#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_right : public solver
		{
		private:
			state move();

		public:
			solver_right(labyrinth l) : solver(l) {
				this->lab.character_rotate(South);
			}
			~solver_right() = default;
		};

		state solver_right::move() {

			if (!this->lab.move(Right)) this->lab.character_rotate(Left);

			return running;
		}
	}
}
