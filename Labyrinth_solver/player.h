#pragma once

#include "tracer.h"

namespace labyrinth
{
	namespace 
	{

		class player
		{
		public:
			//Setters et getters sans verification + innaccessible en dehors de labyrinth -> champs publics
			unsigned int x;
			unsigned int y;

			//Memory
			player() : x(0), y(0), front(Up) {};
			~player() {};

			//Accessors
			inline direction faces() const {
				return this->front;
			}
			inline const tracer& path_taken() const {
				return this->path;
			}

		protected:

		private:

			direction front; //indique la direction dnas laquelle "regarde" le joueur

			tracer path;
		};
	}
}
