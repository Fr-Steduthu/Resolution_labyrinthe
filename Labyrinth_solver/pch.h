// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include "framework.h"

#include "grid.h"
#include "player.h"
#include "tracer.h"

#include "coordinates.h"

#include "labyrinth.h"
#include "solver.h"

#ifdef INCLUDE_SOLVERS
#include "solver_left.h"
#include "solver_left_alt.h"
#include "solver_random.h"
#include "solver_right.h"
#include "solver_right_alt.h"
#include "solver_straightline_right.h"
#endif

#endif //PCH_H
