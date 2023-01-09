#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_right : solver
		{
		private:
			unsigned short int steps_on_tile; //Init a 0;
			coords tile_stepped;

			friend state labyrinth_solver::solvers::solver_right::solver::move();

		public:
			solver_right(labyrinth l) : solver(l), steps_on_tile(0), tile_stepped(this->lab.character().coordinates()) {}
		};

		state solver_right::solver::move() {

			if (!this->lab.move(RightSide)) {

				this->lab.character_rotate(RightSide);
				((solver_right*)this)->steps_on_tile++;

				if (((solver_right*)this)->steps_on_tile >= 4) {
					return defeat;
				}

			}
			else {
				((solver_right*)this)->tile_stepped = this->lab.character().coordinates();
				((solver_right*)this)->steps_on_tile = 0;
			}

			return running;
		}
	}
}
