//
// Created by david on 12/07/17.
//
#include <GLFW/glfw3.h>
#include "../glad/glad.h"
#ifndef RUCHAS_CORE_WINDOW_H
#define RUCHAS_CORE_WINDOW_H
/**
 * \brief Defines an encapsulation over GLFW window system.
 */
class Window
{
public:
    GLFWwindow* m_window;
private:
    const int m_width;
    const int m_height;
    const char* m_title;
public:
    /**
     *
     * @param width window width
     * @param height window height
     * @param title window title
     * @param vsync set to *true* to set **vsync** active, set to false otherwise. Default is false
     */
    Window(const int width,const int height,const char* title,const bool vsync = false);
    ~Window();
    int getHeight() const noexcept;
    int getWidth() const noexcept;
    /**
     * \brief swap primary and secondary buffers, practically refreshing the window and printing a frame.
     */
    void swapBuffers();
    /**
     * \brief pass the openGL context to the window object.
     */
    void takeContext();
    /**
     *
     * @return returns true if the window should close, return false otherwise;
     */
    int shouldClose() const;

	void clear();

};
#endif //RUCHAS_CORE_WINDOW_H
