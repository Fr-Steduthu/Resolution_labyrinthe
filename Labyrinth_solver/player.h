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
			player() : _facing(Up) {
				this->_coordinates.x = 0;
				this->_coordinates.y = 0;
			};
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

			inline void set_x(const coordinate& n) {
				this->_coordinates.x = n;
			}
			inline void set_y(const coordinate& n) {
				this->_coordinates.y = n;
			}
			inline void set_facing(const direction& dir) {
				this->_facing = dir;
			}

			//Accessors
			inline const direction& faces() const {
				return this->_facing;
			}
			inline const tracer& path_taken() const { //On renvoie le tracer pour utiliser pouvoir utiliser la fonction tracer::optimize()
				return this->_path;
			}

		protected:

		private:
			coords _coordinates;

			direction _facing; //indique la direction dans laquelle "regarde" le joueur

			tracer _path;
		};
	}
}
