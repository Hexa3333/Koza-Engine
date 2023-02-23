#include "Time.h"

namespace Koza_Core
{
	float previous = (float)glfwGetTime();
	float Time::DT;

	void Time::Calculate() 
	{
		float now = (float)glfwGetTime();
		DT = now - previous;
		previous = now;
	}
}