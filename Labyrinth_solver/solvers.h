#pragma once

#include <random>
#include <ctime>

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

		/*--------------------------------------------------*/
		/*--------------------------------------------------*/
		/*--------------------------------------------------*/

		class solver_left_alt : public solver
		{
		private:
			unsigned short int steps_on_tile; //Init a 0;
			coords tile_stepped;

			state move();

		public:
			solver_left_alt(labyrinth l) : solver(l), steps_on_tile(0), tile_stepped(this->lab.character().coordinates()) {};
			~solver_left_alt() = default;
		};

		state solver_left_alt::move() {
			bool wentfront = this->lab.move(Left);

			if (!wentfront) {
				if (!this->lab.move(Front)) {
					if (!this->lab.move(Right)) this->lab.move(Back);
				};

			}
			else {
				this->tile_stepped = this->lab.character().coordinates();
				this->steps_on_tile = 0;
			}

			return running;
		}


		/*--------------------------------------------------*/
		/*--------------------------------------------------*/
		/*--------------------------------------------------*/


		class solver_random : public solver {
		public:
			solver_random(const labyrinth& l) : solver(l) {
				std::srand(std::time(nullptr));
			};
			~solver_random() = default;

		private:
			state move();
		};

		state solver_random::move() {
			unsigned short int nb = this->lab.walkable(Front) + this->lab.walkable(Right) + this->lab.walkable(Left);
			if (nb == 1) {
				this->lab.move(Front);
				this->lab.move(Left);
				this->lab.move(Right);
				return running;
			}

			if (nb == 0) {
				this->lab.move(Back);
				return running;
			}

			int r(std::rand());

			if (nb == 2) {

				if (r <= RAND_MAX / 2) {
					if (!this->lab.move(Front)) this->lab.move(Right);
				}
				else {
					if (!this->lab.move(Left)) this->lab.move(Right);
				}

				return running;
			}

			if (nb == 3) {
				if (r <= RAND_MAX / 3) {
					this->lab.move(Front);
				}
				else if (r >= RAND_MAX / 3 * 2) {
					this->lab.move(Right);
				}
				else {
					this->lab.move(Left);
				}
				return running;
			}

			return defeat; //Dead code, on le mets juste pour que les control path du compilo ne génère pas de warnings
		}


		/*--------------------------------------------------*/
		/*--------------------------------------------------*/
		/*--------------------------------------------------*/


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


		/*--------------------------------------------------*/
		/*--------------------------------------------------*/
		/*--------------------------------------------------*/


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


		/*--------------------------------------------------*/
		/*--------------------------------------------------*/
		/*--------------------------------------------------*/



	}
}
