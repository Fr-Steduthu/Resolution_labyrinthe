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

	class labyrinth
	{
	public:
		//Memory

		labyrinth(std::ifstream& file, const char& wall = '#');

		labyrinth(std::string data, const char& wall = '#');

		labyrinth(const labyrinth& other);

		inline void operator= (const labyrinth& other) {
			this->wall = other.wall;
			delete this->_grid;
			this->_grid = new grid(*other._grid);
			this->_player = other._player;
			this->_player_direction = other._player_direction;
		}

		~labyrinth() {
			delete this->_grid;
		};

		/**Fonctions du joueur**/

		//Returns wether or not the player has been moved
		bool move(const direction& dir);
		inline bool move(const facing& f) {
			return this->move(this->facing_to_absolute(f));
		}

		/**Grid / Player functions**/
		inline bool is_won() const { return this->_player.x() == this->_grid->exit().x && this->_grid->exit().y == this->_player.y(); }

		/**Operators**/
		inline operator std::string() const {
			std::ostringstream s;

			for (coordinate x = 0; x <= this->_grid->MAX_X(); x++) {
				for (coordinate y = 0; y <= this->_grid->MAX_Y(); y++) {

					if(this->_player.x() == x && this->_player.y() == y) {
						switch (this->_player_direction)
						{
						case North:
							s << "^";
							break;
						case South:
							s << "v";
							break;
						case West:
							s << "<";
							break;
						case East:
							s << ">";
							break;
						}
						//LOG("Player is at (" << x << "; " << y << ")");
						continue;
					}
					
					s << (this->walkable(x, y) ? " " : &this->wall);
				}
				s << "\n";
			}

			return s.str();
		}

		/**Data access**/
		inline const player& character() const {
			return this->_player;
		}
		inline const direction& character_facing() const {
			return this->_player_direction;
		}
		inline void character_rotate(const direction& d) {
			this->_player_direction = d;
		}
		inline void character_rotate(const facing& f) {
			this->_player_direction = this->facing_to_absolute(f);
		}

		inline bool walkable(const coordinate& x, const coordinate& y) const {
			return this->_grid->walkable(x, y);
		}
		inline bool walkable(const coords& c) const {
			this->walkable(c.x, c.y);
		}
		inline bool walkable(const direction& d) const {
			coords c(this->_player.coordinates());

			switch (d)
			{
			case direction::North :
				c.x += -1;
				break;
			case direction::West:
				c.y += -1;
				break;
			case direction::East:
				c.y += +1;
				break;
			case direction::South:
				c.x += +1;
				break;
			}

			return this->walkable(c.x, c.y);
		}
		inline bool walkable(const facing& f) const {
			return this->walkable(this->facing_to_absolute(f));
		}

	protected:

	private:

		player _player;
		direction _player_direction; //indique la direction dans laquelle "regarde" le joueur

		grid * _grid;

		char wall;

		inline direction facing_to_absolute(const facing& f) const {
			switch (this->_player_direction) {
			case direction::North:
				switch (f) {
				case facing::Front:
					return North;
				case facing::Left:
					return West;
				case facing::Right:
					return East;
				case facing::Back:
					return South;
				}

			case direction::West:
				switch (f) {
				case facing::Front:
					return West;
				case facing::Left:
					return South;
				case facing::Right:
					return North;
				case facing::Back:
					return East;
				}

			case direction::East:
				switch (f) {
				case facing::Front:
					return East;
				case facing::Left:
					return North;
				case facing::Right:
					return South;
				case facing::Back:
					return West;
				}

			case direction::South:
				switch (f) {
				case facing::Front:
					return South;
				case facing::Left:
					return East;
				case facing::Right:
					return West;
				case facing::Back:
					return North;
				}
			}

			return North; //Dead code, on le laisse our les control path du compilo
		}
	};

	
}

inline std::ostream& operator<<(std::ostream& out, const labyrinth_solver::labyrinth& self) { // inline, sinon �a compile pas
	return (out << (std::string)self);
}