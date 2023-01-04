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
			tracer() {}
			~tracer() = default;

			//Procedures
			void up() {
				this->path.push_back(Up);
			}
			void down() {
				this->path.push_back(Down);
			}
			void left() {
				this->path.push_back(Left);
			}
			void right() {
				this->path.push_back(Right);
			}

			std::vector<direction> optimized() const {
				tracer cpy(*this);

				//TODO : supprimer les occurences du genre -> <- / v| ^| / <- -> / ...

				return cpy.path;
			}

			//Accessors
			size_t steps_taken() const {
				return this->path.size();
			}

			const std::vector<direction>& path_taken() const {
				return this->path;
			}

		protected:

		private:
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
