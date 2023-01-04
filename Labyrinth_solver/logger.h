#pragma once
#ifdef DEBUG

	#include <iostream>

	#ifndef LOUT
		#define LOUT std::cout
	#endif

	#define LOG(message) LOUT << message << std::endl
#else 

#endif