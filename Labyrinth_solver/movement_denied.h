#include <string>

#include "labyrinth.h"
#include "grid.h"
#include "player.h"
#include "solver.h"

class movement_denied : public Solver {
public:


	virtual state move() {
		cout << "move() called" << endl;
	}

}