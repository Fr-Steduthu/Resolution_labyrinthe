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

		labyrinth(std::ifstream& file, const char& wall = '#') : wall(wall) {
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
		bool move(const facing& f) {
			return this->move(this->facing_to_absolute(f));
		}

		/**Grid / Player functions**/
		inline bool is_won() const { return this->_player.x() == this->_grid.exit().x && this->_grid.exit().y == this->_player.y(); }

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
		void character_rotate(const facing& f) {
			this->_player_direction = this->facing_to_absolute(f);
		}

		bool walkable(const coordinate& x, const coordinate& y) const {
			return this->_grid.walkable(x, y);
		}
		bool walkable(const coords& c) const {
			this->_grid.walkable(c);
		}
		bool walkable(const direction& d) const {
			coords c(this->_player.coordinates());

			switch (d)
			{
			case direction::Up :
				c.x += -1;
				break;
			case direction::Left:
				c.y += -1;
				break;
			case direction::Right:
				c.y += +1;
				break;
			case direction::Down:
				c.x += +1;
				break;
			}

			return this->_grid.walkable(c);
		}
		bool walkable(const facing& f) const {
			return this->walkable(this->facing_to_absolute(f));
		}

	protected:

	private:

		player _player;
		direction _player_direction; //indique la direction dans laquelle "regarde" le joueur

		grid _grid;

		const char wall;

		direction facing_to_absolute(const facing& f) const {
			switch (this->_player_direction) {
			case direction::Up:
				switch (f) {
				case facing::Front:
					return Up;
				case facing::LeftSide:
					return Left;
				case facing::RightSide:
					return Right;
				case facing::Back:
					return Down;
				}

			case direction::Left:
				switch (f) {
				case facing::Front:
					return Left;
				case facing::LeftSide:
					return Down;
				case facing::RightSide:
					return Up;
				case facing::Back:
					return Right;
				}

			case direction::Right:
				switch (f) {
				case facing::Front:
					return Right;
				case facing::LeftSide:
					return Up;
				case facing::RightSide:
					return Down;
				case facing::Back:
					return Left;
				}

			case direction::Down:
				switch (f) {
				case facing::Front:
					return Down;
				case facing::LeftSide:
					return Right;
				case facing::RightSide:
					return Left;
				case facing::Back:
					return Up;
				}
			}

			return Up; //Dead code, on le laisse our les control path du compilo
		}
	};

	std::ostream& operator<<(std::ostream& out, const labyrinth& self) {
		return (out << (std::string) self);
	}
}
