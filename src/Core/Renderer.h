#pragma once
#include <iostream>
#include <vector>
#include "IRenderAble.h"
#include "Gameobject.h"

namespace Kz
{
	class Renderer
	{
	private:
		Renderer() = default;

	public:
		static Renderer& MAIN()
		{
			static Renderer _instance;
			return _instance;
		}

		std::vector<IRenderAble*> Entities;

		void Init();
		void Run();
		void Kill();
	};
}