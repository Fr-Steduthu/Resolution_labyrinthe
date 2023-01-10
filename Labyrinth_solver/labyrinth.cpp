
#include "pch.h"
#include "labyrinth.h"

//Returns wether or not the player has been moved

labyrinth_solver::labyrinth::labyrinth(std::ifstream& file, const char& wall) : wall(wall), _grid(nullptr), _player_direction(direction::North) {
	std::ostringstream data;

	while (!file.eof()) {
		std::string s;
		std::getline(file, s);
		data << s << (file.eof() ? "" : "\n");
	}

	this->_grid = new grid(data.str());
}

labyrinth_solver::labyrinth::labyrinth(std::string data, const char& wall) : wall(wall), _grid(nullptr), _player_direction(direction::North) {
	//Le _player par defaut est OK
	this->_grid = new labyrinth_solver::grid(data);
}

labyrinth_solver::labyrinth::labyrinth(const labyrinth& other) : wall(other.wall), _grid(nullptr), _player(other._player), _player_direction(other._player_direction) {
	this->_grid = new grid(*other._grid);
}

bool labyrinth_solver::labyrinth::move(const direction& dir) {
	coordinate target_x(this->_player.x());
	coordinate target_y(this->_player.y());

	player cpy(this->_player);
	cpy.move(dir);

	if (!this->_grid->walkable(cpy.coordinates())) {
		return false;
	}

	//LOG(target_x << ", " << target_y << "  walkable");

	//std::cout << *this;

	this->_player = cpy;
	this->_player_direction = dir;

	return true;
}
