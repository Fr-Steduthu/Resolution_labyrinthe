#pragma once

#include <vector>
#include <sstream>
#include <string>

#include <iostream>

#include "coordinates.h"

namespace labyrinth
{
	namespace
	{

		class grid
		{
		public:

			grid() = default; //Ne sert qu'a initialiser les champs

			//On suppose que les terrains sont OBLIGATOIREMENT des rectangles
			grid(const std::string& data, const char& wall = '#') {
				LOG("\t\tBuilding grid");
				std::istringstream in(data);
				size_t index = 0;


				while (!in.eof()) {

					this->_walkables.push_back(std::vector<bool>());
					LOG("Reading row " << index);

					std::string str;
					std::getline(in, str);
					LOG(str);

					for (char c : str) {
						if (c == '\n') continue;
						c == ' ' ? this->_walkables[index].push_back(true) : this->_walkables[index].push_back(false);
					}
					
					index++;
				}

				//check_format();
				LOG("\t\tgrid built");
			}

			inline bool walkable(const coordinate& x, const coordinate& y) const {
				//LOG("Asking if (" << x << "; " << y << ") is walkable");
				//this->_walkables[x][y] ? LOG("\t(" << x << "; " << y << ") is walkable") : LOG("\t(" << x << "; " << y << ") is NOT walkable");

				if (x > this->MAX_X() || y > this->MAX_Y()) return false;

				return this->_walkables[x][y];
			}

			inline coords&& entrance() const {
				coords entrance;
				entrance.x = 0;
				entrance.y = 0;
				return std::move(entrance);
			}
			inline coords&& exit() const {
				coords exit_point;
				exit_point.x = this->MAX_X();
				exit_point.y = this->MAX_Y();
				return std::move(exit_point);
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

			void check_format() const {
				// throw une erreur // TODO
				for (std::vector<bool> obj : this->_walkables) {
					if (obj.size() != this->MAX_Y()) {
						throw "Grid is not a rectangle";
					}
				}

				//TODO : check si les bords sont biens des murs sauf 4
			}
		};
	}

}
