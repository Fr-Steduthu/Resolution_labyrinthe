#pragma once

#include "tracer.h"

namespace labyrinth
{
	class player
	{
	public:

		player();

		void move(const direction& dir); //mets a jour les coordonees et le path

	protected:

	private:
		unsigned int x;
		unsigned int y;

		tracer path;
	};
}
