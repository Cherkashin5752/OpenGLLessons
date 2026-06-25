#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int windowWidth = 800;
int windowHeight = 600;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, windowWidth, windowHeight);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
    GLFWwindow* pWindow;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit failed!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    pWindow = glfwCreateWindow(windowWidth, windowHeight, "OpenGLLessons", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);
	
	if (!gladLoadGL())
	{
		std::cout << "Can't load GLAD!" << std::endl;
		return -1;
	}
	
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

	std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;
	
	glClearColor(0.9f, 0.3f, 0.3f, 1.0f);

    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}