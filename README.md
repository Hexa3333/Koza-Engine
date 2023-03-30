# Koza-Engine
My Personalized 2D Game Engine/Library

## Space Invaders Demo
![Screenshot](https://user-images.githubusercontent.com/70033420/228951908-e32a984f-169a-410f-a507-9e1f27834084.png)

## Setting Up

After linking with KozaEngine.lib, all you have to do is:
```cpp
#include <KozaEngine.h>
using namespace Koza_Core;

int main()
{
  Application::Init("Name Here", screenWidth, screenHeight);
  
  while (Application::GetAppShouldRun())
    Application::Run();
    
  Application::Kill();
}
```
*And that's all. All components/objects created by the user are loaded into memory dynamically.
Though you have to declare class instances before the app initialization **for now**. I will be replacing this behavior
with better solutions in the future.*


### **Examples**
*Creating A Player Object With Basic Movement:*

```cpp

#include <KozaEngine.h>

using namespace std;
using namespace glm;
using namespace Koza_Core;

class Player : Game
{
public:
	unique_ptr<Gameobject> go;

private:
	void Start() override
	{
		go = make_unique<Gameobject>(make_unique<Sprite>("res/character.jpg"),
			make_unique<Shader>("res/Shaders/myVertex.shader", "res/Shaders/myFragment.shader"));

		go->transform.Scale(vec3(.2f));
		go->transform.Translate(-4.0f, 1.3f);
	}

	void Update() override
	{
		
		if (glfwGetKey(Application::GetMainWindow(), GLFW_KEY_W))
			go->transform.Translate(0.f, 5.f * Time::DT);
		if (glfwGetKey(Application::GetMainWindow(), GLFW_KEY_S))
			go->transform.Translate(0.f, -5.f * Time::DT);
		if (glfwGetKey(Application::GetMainWindow(), GLFW_KEY_A))
			go->transform.Translate(-5.f * Time::DT, 0.f);
		if (glfwGetKey(Application::GetMainWindow(), GLFW_KEY_D))
			go->transform.Translate(5.f * Time::DT, 0.f);

	}
  
};
```
