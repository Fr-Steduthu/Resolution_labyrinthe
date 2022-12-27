#pragma once*
namespace labyrinth
{
	class dungeon
	{
	public:
		//Memory
		dungeon();
		~dungeon() = default;

		/**Fonctions du joueur**/
		void move(const direction& dir);
		void move_relative(const direction& dir);

	protected:

	private:
		player character;
		const grid lab;
	};
}
