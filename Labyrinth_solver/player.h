#pragma once

#include "tracer.h"
#include "coordinates.h"

namespace labyrinth
{
	namespace 
	{

		class player
		{
		public:
			//Memory
			player() : _x(0), _y(0), _front(Up) {};
			~player() {};

			inline coordinate x() const  {
				return this->_x;
			}
			inline coordinate y() const  {
				return this->_y;
			}
			coords coordinates() const {
				coords c;
				c.x = this->_x;
				c.y = this->_y;
				return c;
			}

			inline void set_x(const coordinate& n) {
				this->_x = n;
			}
			inline void set_y(const coordinate& n) {
				this->_y = n;
			}

			//Accessors
			inline const direction& faces() const {
				return this->_front;
			}
			inline const tracer& path_taken() const { //On renvoie le tracer pour utiliser pouvoir utiliser la fonction tracer::optimize()
				return this->_path;
			}

		protected:

		private:
			coordinate _x;
			coordinate _y;

			direction _front; //indique la direction dnas laquelle "regarde" le joueur

			tracer _path;
		};
	}
}
