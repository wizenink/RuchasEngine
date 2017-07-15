#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "window/window.h"
#include "shaders\shader.h"
int main()
{

	std::string vertexteststring = R"(
	#version 330 core
	in vec2 position;
	void main()
	{
		gl_Position = vec4(position,0.0f,1.0f);
	}
	)";

	std::string fragmentteststring = R"(
	#version 330 core
	out vec4 color;
	void main()
	{
		color = vec4(1.0f,0.0f,0.0f,1.0f);
	}
	)";


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


	GLfloat vertices[] =
	{
		0.0f,0.5f,
		0.5f,-0.5f,
		-0.5f,-0.5f
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	

	Shader testShaders;
	testShaders.compileShaders(vertexteststring, fragmentteststring);
	testShaders.bind();
    while(window.shouldClose() != 1)
    {
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 3);
       window.swapBuffers();
    }
	glBindVertexArray(0);
	testShaders.unbind();
    glfwTerminate();
}

