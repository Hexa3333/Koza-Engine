#pragma once
#include <vector>
#include "../Interfaces/IRenderAble.h"
#include "../Gameobject.h"

namespace Koza_Core
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

		static std::vector<IRenderAble*> Entities;

		void Init();
		void Run();
		void Kill();
	};
}