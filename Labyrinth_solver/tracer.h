#pragma once
#include <string>
#include <vector>

namespace labyrinth
{

	enum direction
	{
		Up, Left, Down, Right
	};

	class tracer
	{
	public:

		//tracer();

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

		unsigned int steps_taken() const {
			return this->steps;
		}
		std::vector<std::vector<<bool>> cells_stepped(); //Renvoie la string correspondant au chemin pris

	protected:

	private:
		unsigned int steps;
		std::vector<direction> path;
	};


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
