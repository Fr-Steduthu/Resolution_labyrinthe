#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Labyrinth_solver/player.h"

namespace Tester
{
	TEST_CLASS(PlayerTester)
	{
	public:
		
		TEST_METHOD(move)
		{
			labyrinth_solver::player p;
			p.move(direction::Up);
		}
	};
}
