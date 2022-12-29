#pragma once

#include "labyrinth.h"
#include "grid.h"
#include "player.h"

namespace labyrinth
{
	namespace solvers
	{
		enum state { victory, defeat, running, };

		class solver //Classe mere des heuristiques
		{
		public:

			solver(std::string lab, const char& wall = '#') : lab(labyrinth::dungeon(lab, wall)) {};
			solver(dungeon d) : lab(d) {};
			virtual ~solver();

			//retrieve_path
			//resolution_time

			virtual state move() = 0; //Code du bot

			operator std::string() {
				std::string s(this->lab);

				//TODO

				return s;
			}

		protected:
			dungeon lab;

			player& player() { return lab.character; }
			const grid& grid() { return lab.lab; }
		private:

		};
	}
}

