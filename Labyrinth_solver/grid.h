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
				std::istringstream in(data);
				size_t index = 0;

				this->_walkables.push_back(std::vector<bool>());

				while (!in.eof()) {
					std::string str;
					in >> str;

					for (char c : str) {
							if (c == '\n') {
								this->_walkables.push_back(std::vector<bool>());
								this->_MAX_X = this->_walkables.size() - 1;

								std::cout << this->_MAX_X;

								index++;
								continue;
							}

						c == ' ' ? this->_walkables[index].push_back(true) : this->_walkables[index].push_back(false);
					}
				}

				this->_MAX_Y = this->_walkables.size() -1;

				//check_format();

				std::cout << std::endl;
			}

			inline const bool& walkable(const unsigned int& x, const unsigned int& y) const {
				return this->_walkables[x][y];
			}

			inline coords entrance() const {
				coords entrance;
				entrance.x = 0;
				entrance.y = 0;
				return std::move(entrance);
			}
			inline coords exit() const {
				coords exit_point;
				exit_point.x = this->MAX_X();
				exit_point.y = this->MAX_Y();
				return std::move(exit_point);
			}

			inline const unsigned int& MAX_X() const {
				return this->_walkables.size() - 1;
			}
			inline const unsigned int& MAX_Y() const {
				return this->_walkables[0].size() - 1;
			}

		protected:

		private:
			std::vector<std::vector<bool>> _walkables; //true = case vide

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
