#pragma once
#include <vector>

namespace Koza_Core
{
	class Game
	{
	protected:
		static std::vector<Game*> AllBehaviorObjects;
		Game();

		virtual void Start() = 0;
		virtual void Update() = 0;
	public:
		static void MStart();
		static void MUpdate();
	};
}