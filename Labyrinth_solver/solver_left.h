#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_left : solver
		{
		private:
			unsigned short int steps_on_tile; //Init a 0;
			coords tile_stepped;

			friend state labyrinth_solver::solvers::solver_left::solver::move();

		public:
			solver_left(labyrinth l) : solver(l), steps_on_tile(0), tile_stepped(this->lab.character().coordinates()) {}
		};

		state solver_left::solver::move() {

			if (!this->lab.move(LeftSide)) {

				this->lab.character_rotate(LeftSide);
				((solver_left*)this)->steps_on_tile++;

				if (((solver_left*)this)->steps_on_tile >= 4) {
					return defeat;
				}

			}
			else {
				((solver_left*)this)->tile_stepped = this->lab.character().coordinates();
				((solver_left*)this)->steps_on_tile = 0;
			}

			return running;
		}
	}
}
