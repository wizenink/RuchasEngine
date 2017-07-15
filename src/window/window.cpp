//
// Created by david on 12/07/17.
//
#include "window.h"

 Window::Window(const int width, const int height, const char *title,const bool vsync):
    m_width(width),m_height(height),m_title(title)
 {
     m_window = glfwCreateWindow(m_width,m_height,m_title,NULL,NULL);
     glfwSwapInterval((vsync)?1:0);
 }

Window::~Window()
{
    glfwDestroyWindow(m_window);
}

int Window::getHeight() const noexcept
{
    return m_height;
}

int Window::getWidth() const noexcept
{
    return m_width;
}

void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
}
void Window::swapBuffers()
{

    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

void Window::takeContext()
{
    glfwMakeContextCurrent(m_window);
}

int Window::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
}