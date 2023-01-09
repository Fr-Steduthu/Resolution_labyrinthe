#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_left_alt : solver
		{
		private:
			unsigned short int steps_on_tile; //Init a 0;
			coords tile_stepped;

			friend state labyrinth_solver::solvers::solver_left_alt::solver::move();

		public:
			solver_left_alt(labyrinth l) : solver(l), steps_on_tile(0), tile_stepped(this->lab.character().coordinates()) {}
		};

		state solver_left_alt::solver::move() {

			if (!this->lab.move(Front)) {

				this->lab.character_rotate(RightSide);
				((solver_left_alt*)this)->steps_on_tile++;

				if (((solver_left_alt*)this)->steps_on_tile >= 4) {
					return defeat;
				}

			}
			else {
				((solver_left_alt*)this)->tile_stepped = this->lab.character().coordinates();
				((solver_left_alt*)this)->steps_on_tile = 0;
			}

			return running;
		}
	}
}
