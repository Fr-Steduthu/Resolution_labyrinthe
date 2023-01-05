#pragma once

#include "tracer.h"
#include "coordinates.h"

namespace labyrinth_solver
{
	namespace 
	{

		class player
		{
		public:
			//Memory
			player() {
				this->_coordinates.x = 0;
				this->_coordinates.y = 0;
			};
			player(const coords& c) {
				this->_coordinates = c;
			}
			~player() {};

			inline coordinate x() const  {
				return this->_coordinates.x;
			}
			inline coordinate y() const  {
				return this->_coordinates.y;
			}
			inline coords coordinates() const {
				return this->_coordinates;
			}

			void move(const direction& dir) {
				switch (dir)
				{
				case direction::Up:
					this->_coordinates.x += -1;
					this->_path.up();
					break;
				case direction::Left:
					this->_coordinates.y += -1;
					this->_path.left();
					break;
				case direction::Right:
					this->_coordinates.y += +1;
					this->_path.right();
					break;
				case direction::Down:
					this->_coordinates.x += +1;
					this->_path.down();
					break;
				}
			}

			//Accessors
			inline const tracer& path_taken() const { //On renvoie le tracer pour utiliser pouvoir utiliser la fonction tracer::optimize()
				return this->_path;
			}

		protected:

		private:
			coords _coordinates;

			tracer _path;
		};
	}
}
