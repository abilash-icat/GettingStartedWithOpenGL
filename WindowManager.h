#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Model.h"
#include "SceneNode.h"
#include "Renderer.h"
#include "UserInteraction.h"

class WindowManager 
{
public:
	WindowManager(int width, int height, const char* title);
	~WindowManager();

	void init();
	void update(float delta);

	bool closeNotRequested();

	Renderer* getRenderer() { return renderer; }

	float getElapsedTime();

private:
	void preRender();
	void postRender();

private: 
	int height, width;
	const char* title;


	Renderer* renderer;
	GLFWwindow* windowPtr;
};

