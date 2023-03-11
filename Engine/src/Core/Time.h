#pragma once
#include <glfw3.h>

namespace KozaCore
{

	struct Time
	{
		// User Should Never Call This
		static void Calculate();
		

		static float DT;
	};
}