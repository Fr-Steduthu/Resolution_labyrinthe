#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "common.h"

#include "grid.h"
#include "player.h"
#include "tracer.h"

#include "labyrinth.h"

#include "solver.h"

#ifdef INCLUDE_SOLVERS
#include "solver_left.h"
#include "solver_left_alt.h"
#include "solver_random.h"
#include "solver_right.h"
//#include "solver_right_alt.h"
#include "solver_straightline_right.h"
#endif