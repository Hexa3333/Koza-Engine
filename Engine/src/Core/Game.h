#pragma once
#include <vector>

namespace KozaCore
{
	class Game
	{
	protected:
		Game();

		virtual void Start() = 0;
		virtual void Update() = 0;
	public:
		static std::vector<Game*> AllBehaviorObjects;
		
		static void MStart();
		static void MUpdate();
	};
}