#pragma once

#define DEBUG
#include "logger.h"

namespace labyrinth {
	typedef size_t coordinate; //unsigned long int

	struct coords {
		coordinate x;
		coordinate y;
	};
}