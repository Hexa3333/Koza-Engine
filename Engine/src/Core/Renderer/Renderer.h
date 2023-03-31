#pragma once
#include <vector>
#include <memory>
#include "../Interfaces/IRenderAble.h"
#include "../Gameobject.h"
#include "../Camera.h"

namespace KozaCore
{
	class Renderer
	{
	private:
		Renderer();
	public:
		static Renderer& MAIN()
		{
			static Renderer _instance;
			return _instance;
		}
		static unique_ptr<Camera> m_Camera;
		static std::vector<IRenderAble*> Entities;

		void Init();
		void Run();
		void Kill();
	};
}