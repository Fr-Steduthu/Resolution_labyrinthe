#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Labyrinth_solver/common.h"
#include "../Labyrinth_solver/player.h"

namespace Tester
{
	TEST_CLASS(PlayerTester)
	{
	public:
		
		TEST_METHOD(move)
		{
			labyrinth_solver::player origin;
			origin.move(labyrinth_solver::direction::South);
			origin.move(labyrinth_solver::direction::West);
			labyrinth_solver::player p(origin);
			

			p.move(labyrinth_solver::direction::South);
			p.move(labyrinth_solver::direction::North);
			p.move(labyrinth_solver::direction::West);
			p.move(labyrinth_solver::direction::East);

			Assert::AreEqual(origin.x(), p.x());
			Assert::AreEqual(origin.y(), p.y());
		}
	};
}
