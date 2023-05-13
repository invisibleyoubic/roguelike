#include <iostream>

#define GLFW_INCLUDE_NONE
#include "libs/glad.h"
#include "GLFW/glfw3.h"

#include "test.hpp"

void Test::testFunc()
{
    std::cout << "test_func" << std::endl;
}

void Test::testOpenGLWindow()
{
    if (!glfwInit())
    {
        std::cout << "init error" << std::endl;
        return;
    }
 
    GLFWwindow* window = glfwCreateWindow(500, 500, "test", NULL, NULL);
    if (nullptr == window)
    {
        std::cout << "creating window error" << std::endl;
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
 
    gladLoadGL();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_TRIANGLES);
            glVertex2f(0.0f, 0.5f);
            glVertex2f(0.0f, -0.5f);
            glVertex2f(0.5f, 0.0f);
        glEnd();

        glColor3f(0.9f, 0.2f, 0.6f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(0.0f, 0.5f);
            glVertex2f(0.0f, -0.5f);
            glVertex2f(0.5f, 0.0f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}