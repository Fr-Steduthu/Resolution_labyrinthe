#pragma once

#include <vector>
#include <sstream>
#include <string>
#include <iostream>

#include "coordinates.h"

namespace labyrinth_solver
{
	namespace
	{

		class grid
		{
		public:

			grid() = default; //Ne sert qu'a initialiser les champs

			//On suppose que les terrains sont OBLIGATOIREMENT des rectangles
			grid(const std::string& data) {
				LOG("\t\tBuilding grid");
				std::istringstream in(data);
				size_t index = -1;


				while (!in.eof()) {
					index++;
					this->_walkables.push_back(std::vector<bool>());
					LOG("Reading row " << index);


					std::string str;
					std::getline(in, str);
					LOG(str);

					for (char c : str) {
						if (c == '\n') continue;
						c == ' ' ? this->_walkables[index].push_back(true) : this->_walkables[index].push_back(false);
					}
					
				}

				this->_walkables.pop_back(); //Supression de la ligne vide

				//check_format();
				LOG("\t\tgrid built");
			}

			inline bool walkable(const coordinate& x, const coordinate& y) const {
				//LOG("Asking if (" << x << "; " << y << ") is walkable");
				//this->_walkables[x][y] ? LOG("\t(" << x << "; " << y << ") is walkable") : LOG("\t(" << x << "; " << y << ") is NOT walkable");

				if (x > this->MAX_X() || y > this->MAX_Y()) return false;

				LOG("(" << x << ", " << y << ")");

				return this->_walkables[x][y];
			}

			inline bool walkable(const coords& c) const {
				return this->walkable(c.x, c.y);
			}

			/*inline coords entrance() const {
				coords entrance;
				entrance.x = 0;
				entrance.y = 0;
				return entrance;
			}*/
			inline coords exit() const {
				coords exit_point;
				exit_point.x = this->MAX_X();
				exit_point.y = this->MAX_Y();
				return exit_point;
			}

			inline coordinate MAX_X() const {
				return this->_walkables.size() - 1;
			}
			inline coordinate MAX_Y() const {
				return this->_walkables[0].size() - 1;
			}

		protected:

		private:
			std::vector<std::vector<bool>> _walkables;

		};
	}

}
