#pragma once
#include <iostream>
#include <vector>
#include "ARenderAble.h"
#include "Gameobject.h"

class Renderer
{
private:
	Renderer() = default;

public:
	static Renderer& INST()
	{
		static Renderer _instance;
		return _instance;
	}

	std::vector<ARenderAble*> Entities;

	void Init();
	void Run();
};