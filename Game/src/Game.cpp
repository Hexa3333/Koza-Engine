#include <iostream>
#include <algorithm>
#include <format>

#include <KozaEngine.h>

// TODO:
// Default shader which takes position data
// and displays them in a missing texture format for
// gizmos and stuff
using namespace Koza_Core;

int main(void)
{
    Application::Init("Game");

    Shader basShader("res/Shaders/myVert.shader", "res/Shaders/myFrag.shader");
    Gameobject* go = new Gameobject(new Sprite("res/napoleon.jpg"), &basShader);

    while (Application::GetAppShouldRun())
        Application::Run();
    
    delete go;
    return 0;
}