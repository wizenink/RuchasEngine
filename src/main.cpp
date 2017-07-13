#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "window/window.h"
int main()
{
    if(!glfwInit())
    {
        std::cerr << "Could not start glfw: critical error" << std::endl;
        return -1;
    }

    Window window(1920,1080,"Joseme sucio",false);
    window.takeContext();
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cerr << "Could not start GLAD: critical error" << std::endl;
        return -1;
    }
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));
    while(window.shouldClose() != 1)
    {
       window.swapBuffers();
    }
    glfwTerminate();
}

