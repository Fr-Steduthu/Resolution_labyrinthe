#pragma once

#include "tracer.h"

namespace labyrinth
{
	namespace 
	{
		class player
		{
		public:

			//Memory
			player();
			~player() {};

			//Procedures
			void move(const direction& dir); //mets a jour les coordonees et le path, ainsi que l'orientation
			void move_relative(const direction& dir);

			//Accessors
			inline direction faces() const {
				return this->front;
			}
			inline const tracer& path_taken() const {
				return this->path;
			}

		protected:

		private:
			unsigned int x;
			unsigned int y;

			direction front; //indique la direction dnas laquelle "regarde" le joueur

			tracer path;
		};
	}
}
