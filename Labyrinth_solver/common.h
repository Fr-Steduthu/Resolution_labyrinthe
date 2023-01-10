#pragma once

#define DEBUG
#include "logger.h"

namespace labyrinth_solver {
	enum direction { North, West, South, East };

	enum facing { Front, Back, Left, Right };

	typedef unsigned long long int coordinate; // Permet de creer de treeeeeeees grands labyrinthes

	struct coords {
		coordinate x;
		coordinate y;
	};

	bool equals(const coords& self, const coords& other) {
		return (
			(self.x == other.x)
			&&
			(self.y == other.y)
			)
		;
	}
}