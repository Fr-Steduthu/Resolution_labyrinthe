#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include "tracer.h"
#include "player.h"
#include "grid.h"

namespace labyrinth
{
	class dungeon
	{
	public:
		//Memory
		dungeon(std::ifstream file); // TODO : Le charactere du mur peut possiblement etre determine depuis le fichier, pusique le seul charactere qui n'est pas egal a " "
		dungeon(std::string data, char wall = '#');
		~dungeon() = default;

		/**Fonctions du joueur**/

		//Returns wether or not the player has been moved
		bool move(const direction& dir) {
			int target_x(this->character.x);
			int target_y(this->character.y);

			switch (dir)
			{
			case Up :
				target_y += 1;
				break;
			case Left :
				target_x += -1;
				break;
			case Right :
				target_x += 1;
				break;
			case Down :
				target_y += -1;
				break;
			}

			if (!this->lab.walkable(target_x, target_y)) {
				return false;
			}

			this->character.x = target_x;
			this->character.y = target_y;

			return true;
		}
		bool move_relative(const direction& dir);

		/**Operators**/
		operator std::string() {
			std::ostringstream s;

			for (int x = 0; x <= this->lab.MAX_X(); x++) {
				for (int y = 0; y <= this->lab.MAX_Y(); y++) {

					if(this->character.x == x && this->character.y == y) {
						s << (this->wall == '#') ? "@" : "#";
						continue;
					}
					
					s << this->lab.walkable(x, y) ? " " : &this->wall;
				}
				s << "\n";
			}

			return s.str();
		}

		/***Others**/
		friend class solvers::solver;

	protected:

	private:

		player character;
		const grid lab;

		const char wall;
	};
}
