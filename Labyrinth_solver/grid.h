#pragma once

#include <vector>
#include <sstream>
#include <string>

#include "player.h"

namespace labyrinth
{
	namespace
	{
		struct coords {
			unsigned int x;
			unsigned int y;
		};

		class grid
		{
		public:

			//On suppose que les terrains sont OBLIGATOIREMENT des rectangles
			grid(const std::string& data, const char& call = '#') {
				std::istringstream in(data);
				size_t index = 0;

				while (!in.eof()) {
					char c;
					in.get(c);

					if (c == '\n') {
						this->_walkables.push_back(std::vector<bool>());
						this->_MAX_X = this->_walkables.size();

						index++;
						continue;
					}

					c == ' ' ? this->_walkables[index].push_back(true) : this->_walkables[index].push_back(false);
				}

				this->_MAX_Y = this->_walkables.size();

				check_format();
			}
			grid(std::vector<std::vector<bool>> data) : _MAX_X(data.size()), _MAX_Y(data[0].size()), _walkables(data) {}

			inline coords entrance() const {
				coords entrance;
				entrance.x = 0;
				entrance.y = 0;
				return std::move(entrance);
			}
			inline coords exit() const {
				coords exit_point;
				exit_point.x = this->_MAX_X;
				exit_point.y = this->_MAX_Y;
				return std::move(exit_point);
			}

			inline const bool& walkable(const unsigned int& x, const unsigned int& y) const {
				return this->_walkables[x][y];
			}

			inline const unsigned int& MAX_X() const {
				return this->_MAX_X;
			}
			inline const unsigned int& MAX_Y() const {
				return this->_MAX_Y;
			}

		protected:

		private:
			//Depart a (0; 0), Sortie a (MAX_X; MAX_Y)
			unsigned int _MAX_X;
			unsigned int _MAX_Y;

			std::vector<std::vector<bool>> _walkables; //true = case vide

			void check_format() const; // throw une erreur // TODO
		};
	}

}
