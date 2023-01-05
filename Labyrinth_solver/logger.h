#pragma once
#ifdef DEBUG

	#ifndef LOUT
		#include <iostream>
		#define LOUT std::cout
	#endif

	#define LOG(message) LOUT << message << std::endl
#else
	#define LOG(message)
#endif