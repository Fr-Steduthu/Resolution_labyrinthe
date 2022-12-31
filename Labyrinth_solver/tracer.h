#pragma once
#include <string>
#include <vector>

namespace labyrinth
{

	enum direction
	{
		Up, Left, Down, Right
	};

	namespace
	{

		class tracer
		{
		public:
			//Memory
			tracer() : steps(0) {}
			~tracer() = default;

			//Procedures
			void up() {
				this->path.push_back(Up);
				this->steps++;
			}
			void down() {
				this->path.push_back(Down);
				this->steps++;
			}
			void left() {
				this->path.push_back(Left);
				this->steps++;
			}
			void right() {
				this->path.push_back(Right);
				this->steps++;
			}

			void optimize() {
				//TODO : supprimer les occurences du genre -> <- / v| ^| / <- -> / ...
			}

			//Accessors
			unsigned int steps_taken() const {
				return this->steps;
			}
			const std::vector<direction>& cells_stepped() const;

		protected:

		private:
			unsigned long int steps;
			std::vector<direction> path;
		};
	}


	/*std::string(const direction& dir) {
		switch (dir)
		{
		case Up :
			return std::string("up");
		case Down :
			return std::string("down");
		case Left : 
			return std::string("left");
		case Right :
			return std::string("right");
		}
	}*/
}
