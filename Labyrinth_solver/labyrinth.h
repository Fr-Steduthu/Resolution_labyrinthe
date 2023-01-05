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

		//dungeon(std::ifstream file);
		dungeon(std::string data, char wall = '#') : wall(wall){
			LOG("\tBuilding dungeon");
			//Le _player par defaut est OK
			this->_grid = labyrinth::grid(data, wall);
			LOG("\tdungeon built");
		}
		~dungeon() = default;

		/**Fonctions du joueur**/

		//Returns wether or not the player has been moved
		bool move(const direction& dir) {
			coordinate target_x(this->_player.x());
			coordinate target_y(this->_player.y());

			switch (dir)
			{
			case Up :
				target_x += -1;
				break;
			case Left :
				target_y += -1;
				break;
			case Right :
				target_y += 1;
				break;
			case Down :
				target_x += +1;
				break;
			}

			if (!this->_grid.walkable(target_x, target_y)) {
				return false;
			}

			this->_player.set_x(target_x);
			this->_player.set_y(target_y);
			this->_player.set_facing(dir);

			return true;
		}
		bool move_relative(const direction& dir);

		inline bool is_over() const { return this->is_won() || this->is_stuck(); }
		inline bool is_won() const { return equals(this->_player.coordinates(), this->_grid.exit()); }
		inline bool is_stuck() const { return false; }
		/**Operators**/
		operator std::string() {
			std::ostringstream s;

			for (coordinate x = 0; x <= this->_grid.MAX_X(); x++) {
				for (coordinate y = 0; y <= this->_grid.MAX_Y(); y++) {

					if(this->_player.x() == x && this->_player.y() == y) {
						s << (this->wall == '#' ? "@" : "#");
						//LOG("Player is at (" << x << "; " << y << ")");
						continue;
					}
					
					s << (this->_grid.walkable(x, y) ? " " : &this->wall);
				}
				s << "\n";
			}

			return s.str();
		}

		/**Data access**/
		const player& character() const {
			return this->_player;
		}

		bool walkable(const coordinate& x, const coordinate& y) const {
			return this->_grid.walkable(x, y);
		}

	protected:

	private:

		player _player;
		grid _grid;

		const char wall;
	};
}
