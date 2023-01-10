#pragma once

#include "solver.h"

namespace labyrinth_solver
{
	namespace solvers {

		class solver_right_alt : public solver
		{
		private:
			state move();

		public:
			solver_right_alt(labyrinth l) : solver(l) {};
			~solver_right_alt() = default;
		};

		state solver_right_alt::move() {

			if (!this->lab.move(Front)) this->lab.character_rotate(LeftSide);

			LOG(this->lab);

			return running;
		}
	}
}
