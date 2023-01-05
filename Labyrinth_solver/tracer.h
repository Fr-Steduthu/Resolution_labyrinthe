#pragma once
#include <string>
#include <vector>

namespace labyrinth_solver
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

			void append(const direction& dir) {
				this->path.push_back(dir);
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
}
