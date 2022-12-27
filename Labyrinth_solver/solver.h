#pragma once

namespace labyrinth
{
	namespace solvers
	{
		class solver //Classe des heuristiques
		{
		public:

			solver(std::string lab, const char& wall='#');
			solver(labyrinth::dungeon);
			virtual ~solver();

			//retrieve_path
			//resolution_time
			//display

			virtual void move() = 0; //Code du bot

		protected:

			labyrinth::dungeon lab;

		private:

		};
	}
}

