#include "Game.h"

namespace Koza_Core
{
	std::vector<Game*> Game::AllBehaviorObjects;

	Game::Game()
	{
		AllBehaviorObjects.push_back(this);
	}

	void Game::MStart()
	{
		for (auto obj : AllBehaviorObjects) obj->Start();
	}

	void Game::MUpdate()
	{
		for (auto obj : AllBehaviorObjects) obj->Update();
	}
}