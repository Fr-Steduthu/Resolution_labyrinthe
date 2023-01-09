#pragma once

#include <random>
#include <ctime> //Pour rand

#include "solver.h"

namespace labyrinth_solver {
	namespace solvers {
		class solver_random : solver {
		public:
			solver_random(labyrinth l) : solver(l) {
				std::srand(std::time(nullptr));
			};

		private :
			coords previous;
		};

		state solver_random::solver::move() {
			unsigned short int nb = this->lab.walkable(Front) + this->lab.walkable(RightSide) + this->lab.walkable(LeftSide);
			if (nb == 1) {
				this->lab.move(Front);
				this->lab.move(LeftSide);
				this->lab.move(RightSide);
				return running;
			}

			if (nb == 0) {
				this->lab.move(Back);
				return running;
			}

			int r(std::rand());

			if (nb == 2) {

				if (r <= RAND_MAX / 2) {
					if (!this->lab.move(Front)) this->lab.move(RightSide);
				}
				else {
					if (!this->lab.move(LeftSide)) this->lab.move(RightSide);
				}

				return running;
			}

			if (nb == 3) {
				if (r <= RAND_MAX / 3) {
					this->lab.move(Front);
				}
				else if (r >= RAND_MAX / 3 * 2) {
					this->lab.move(RightSide);
				}
				else {
					this->lab.move(LeftSide);
				}
				return running;
			}
		}
	}
}

