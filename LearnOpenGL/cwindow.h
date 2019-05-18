#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

float processInput(GLFWwindow *window, int *lock, float *ctl)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
		return *ctl;
	}
	else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		if ((*lock) == 0) {
			*lock = 1;
			return 1.0f;
		}
		else {
			return *ctl;
		}		
	}
	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		if ((*lock) == 1) {
			*lock = 0;
			return -1.0f;
		}
		else {
			return *ctl;
		}
	}
	else
	{
		return *ctl;
	}		
}

GLFWwindow* createWindow(int screenwidth, int screenheight) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(screenwidth, screenheight, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return NULL;
	}

	//glViewport(0, 0, 500, 400);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return window;
}
