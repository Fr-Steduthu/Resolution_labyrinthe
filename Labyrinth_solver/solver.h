#pragma once

#include <iostream>
#include <string>

#include "labyrinth.h"
#include "grid.h"
#include "player.h"

namespace labyrinth_solver
{
	namespace solvers
	{
		enum state { victory, defeat, running, movement_denied };

		class solver //Classe mere des heuristiques
		{
		public:

			solver(std::string lab, const char& wall = '#') : lab(labyrinth_solver::labyrinth(lab, wall)), last_move_state(running) {};
			solver(labyrinth d) : lab(d), last_move_state(running) {};
			virtual ~solver() {};

			//resolution_time

			state step() {
				this->last_move_state = this->move();
				return this->last_move_state;
			}

			bool solve() {
				//start chrono
				while (this->last_move_state != victory && this->last_move_state != defeat) {
					this->step();
				}
				//end chrono
			}

			inline operator std::string() {
				return this->lab.operator std::string();
			}

			std::ostream& operator<<(std::ostream& out) {
				return (out << std::string(*this));
			}

		protected:
			labyrinth lab;
			state last_move_state;

			virtual state move() = 0; //Code du bot

		private:

		};
	}
}

