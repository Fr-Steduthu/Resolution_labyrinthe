#pragma once
#include <string>
#include <vector>

#include "common.h"

namespace labyrinth_solver
{

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
				this->path.push_back(North);
			}
			void down() {
				this->path.push_back(South);
			}
			void left() {
				this->path.push_back(West);
			}
			void right() {
				this->path.push_back(East);
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
