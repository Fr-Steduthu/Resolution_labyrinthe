#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "tracer.h"
#include "player.h"
#include "grid.h"

namespace labyrinth_solver
{
	enum facing { Front, Back, LeftSide, RightSide };

	class labyrinth
	{
	public:
		//Memory

		labyrinth(std::ifstream file, const char& wall = '#') : wall(wall) {
			std::ostringstream data;

			while (!file.eof()) {
				std::string s;
				std::getline(file, s);
				data << s << (file.eof() ? "" : "\n");
			}

			this->_grid = grid(data.str());
		}
		labyrinth(std::string data, char wall = '#') : wall(wall){
			LOG("\tBuilding dungeon");
			//Le _player par defaut est OK
			this->_grid = labyrinth_solver::grid(data);
			LOG("\tdungeon built");
		}
		~labyrinth() = default;

		/**Fonctions du joueur**/

		//Returns wether or not the player has been moved
		bool move(const direction& dir) {
			coordinate target_x(this->_player.x());
			coordinate target_y(this->_player.y());
			
			player cpy(this->_player);
			cpy.move(dir);

			if (!this->_grid.walkable(cpy.coordinates())) {
				return false;
			}

			LOG(target_x << ", " << target_y << "is walkable");

			this->_player = cpy;
			this->_player_direction = dir;

			return true;
		}
		bool move(const facing& dir) {
			switch (this->_player_direction) {
			case direction::Up :
				switch (dir) {
				case facing::Front:
					this->move(direction::Up);
					break;
				case facing::LeftSide:
					this->move(direction::Left);
					break;
				case facing::RightSide:
					this->move(direction::Right);
					break;
				case facing::Back:
					this->move(direction::Down);
					break;
				}
				break;
			case direction::Left :
				switch (dir) {
				case facing::Front:
					this->move(direction::Left);
					break;
				case facing::LeftSide:
					this->move(direction::Down);
					break;
				case facing::RightSide:
					this->move(direction::Up);
					break;
				case facing::Back :
					this->move(direction::Right);
					break;
				}
				break;
			case direction::Right :
				switch (dir) {
				case facing::Front :
					this->move(direction::Right);
					break;
				case facing::LeftSide:
					this->move(direction::Up);
					break;
				case facing::RightSide:
					this->move(direction::Down);
					break;
				case facing::Back:
					this->move(direction::Left);
					break;
				}
				break;
			case direction::Down :
				switch (dir) {
				case facing::Front:
					this->move(direction::Down);
					break;
				case facing::LeftSide:
					this->move(direction::Right);
					break;
				case facing::RightSide:
					this->move(direction::Left);
					break;
				case facing::Back:
					this->move(direction::Up);
					break;
				}
				break;
			}
		}

		/**Grid & Player functions**/
		inline bool is_over() const { return this->is_won() || this->is_stuck(); }
		inline bool is_won() const { return this->_player.x() == this->_grid.exit().x && this->_grid.exit().y == this->_player.y(); }
		inline bool is_stuck() const { return false; }

		/**Operators**/
		operator std::string() const {
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
		const direction& character_facing() const {
			return this->_player_direction;
		}

		bool walkable(const coordinate& x, const coordinate& y) const {
			return this->_grid.walkable(x, y);
		}

	protected:

	private:

		player _player;
		direction _player_direction; //indique la direction dans laquelle "regarde" le joueur

		grid _grid;

		const char wall;
	};

	std::ostream& operator<<(std::ostream& out, const labyrinth& self) {
		return (out << (std::string) self);
	}
}
