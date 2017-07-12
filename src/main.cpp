#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

[[deprecated("This function is deprecated")]]
void test()
{
    return;
}
int main()
{
    test();
    [[maybe_unused]]
    int i = 0;
    if(!glfwInit())
    {
        std::cerr << "Could not start glfw: critical error" << std::endl;
    }

    GLFWwindow *window = glfwCreateWindow(1920,1080,"title",NULL,NULL);
    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    glfwSwapInterval(1);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

   std::cout << "prueba" << std::endl;
}

