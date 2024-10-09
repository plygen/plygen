#include "PlyGenGui/Main.hpp"
#include "AshLogger/AshLoggerPassage.h"
#include "GLFW/glfw3.h"
#include "PlyGenGui/App.hpp"
#include "PlyGenGui/Renderer/Vulkan.hpp"
#include <AshLogger/AshLogger.h>

int main(int argc, char** argv)
{
    glfwInit();

    plygen::gui::App app = plygen::gui::App();
    return app.Run(argc, argv);
}
