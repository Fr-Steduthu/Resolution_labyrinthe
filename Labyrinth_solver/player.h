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

			inline void set_x(coordinate n) {
				this->_x = n;
			}
			inline void set_y(coordinate n) {
				this->_y = n;
			}

			//Accessors
			inline direction faces() const {
				return this->_front;
			}
			inline const tracer& path_taken() const {
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
