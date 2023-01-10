#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_left : public solver
		{
		private:
			unsigned short int steps_on_tile; //Init a 0;
			coords tile_stepped;

			state move();

		public:
			solver_left(const labyrinth& l) : solver(l), steps_on_tile(0), tile_stepped(this->lab.character().coordinates()) {}
			~solver_left() = default;
		};

		state solver_left::move() {

			if (!this->lab.move(LeftSide)) {

				this->lab.character_rotate(LeftSide);
				this->steps_on_tile++;

				if (this->steps_on_tile >= 4) {
					return defeat;
				}

			}
			else {
				this->tile_stepped = this->lab.character().coordinates();
				this->steps_on_tile = 0;
			}

			return running;
		}
	}
}
