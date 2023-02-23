#pragma once
#include <glfw3.h>

namespace Koza_Core
{

	struct Time
	{
		// User Should Never Call This
		static void Calculate();
		

		static float DT;
	};
}