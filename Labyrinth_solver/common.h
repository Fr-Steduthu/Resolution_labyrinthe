#pragma once

//#define DEBUG
#include "logger.h"

namespace labyrinth_solver {
	enum direction { North, West, South, East };

	enum facing { Front, Back, Left, Right };

	typedef unsigned long long int coordinate; // Permet de creer de tres grands labyrinthes mais peux causer des overflow si un labyrinthe atteins la taille max ; tres peu probable

	struct coords {
		coordinate x;
		coordinate y;
	};
}