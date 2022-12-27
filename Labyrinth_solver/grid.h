#pragma once

#include <vector>
#include <sstream>
#include <string>

#include "player.h"

namespace labyrinth
{
	class grid
	{
	public:
		//Depart a (0; 0), Sortie a (MAX_X; MAX_Y)
		const unsigned int MAX_X;
		const unsigned int MAX_Y;

		//TODO : Le charactere du mur peut possiblement etre determine depuis le fichier, pusique le seul charactere qui n'est pas egal a " "
		grid(std::ifstream, char wall='#');
		grid(std::string data, char wall = '#'); //TODO : Cree un player ou non ? //Un mur ne peut pas etre de valeur " "

		inline const bool& walkable(const unsigned int& x, const unsigned int& y) const {
			return this->walkable_matrix[x][y];
		}

		inline operator std::string() const {
			std::ostringstream s;

			for (const std::vector<bool> column : this->walkable_matrix) {
				for (const bool& walkable : column) {
					s << (walkable ? " " : &this->wall);
				}
				s << "\n";
			}

			return s.str();
		}

	protected:

	private:
		const std::vector<std::vector<bool>> walkable_matrix; //true = cas vide
		const char wall;
		//player character; //?

	};

}
