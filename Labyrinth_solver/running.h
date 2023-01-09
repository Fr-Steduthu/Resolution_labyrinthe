#include <string>

#include "labyrinth.h"
#include "grid.h"
#include "player.h"
#include "Solver.h"

class running : public Solver {
public:


	virtual state move() {
		cout << "move() called" << endl;
	}


}