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

		enum state { victory, defeat, running };

		class solver //Classe mere des heuristiques
		{
		public:

			solver(std::string lab, const char& wall = '#') : lab(labyrinth_solver::labyrinth(lab, wall)), last_move_state(running) {};
			solver(const labyrinth& d) : lab(d), last_move_state(running) {};
			virtual ~solver() {};

			state step() {
				if (this->last_move_state == victory || this->lab.is_won()) {
					this->last_move_state = victory;
					std::cout << "Victory!" << std::endl;
					return victory;
				}
				
				if (this->last_move_state == defeat) {
					std::cout << "Defeat..." << std::endl;
					return defeat;
				}

				this->last_move_state = this->move();
				return this->last_move_state;
			}

			tracer solve() {
				while (this->last_move_state != victory && this->last_move_state != defeat) {
					this->step();
				}

				return this->lab.character().path_taken();
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

