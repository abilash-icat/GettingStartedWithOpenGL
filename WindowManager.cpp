
#include "WindowManager.h"



WindowManager::WindowManager(int width, int height, const char* title)
	:width(width)
	,height(height)
	,title(title)
{

}


WindowManager::~WindowManager()
{
}


void WindowManager::init() {
	glfwInit();
	windowPtr = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(windowPtr);

	glewExperimental = true;
	glewInit();

	renderer = new Renderer();
}

void WindowManager::preRender() {
	glClearColor(0.5f, 0.2f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::update(float delta){
	
	// update game

	// render stuff
	preRender();
	renderer->render(delta);
	postRender();
}

void WindowManager::postRender() {
	glfwSwapBuffers(windowPtr);
	glfwPollEvents();
}

float WindowManager::getElapsedTime() {
	return glfwGetTime();
}

bool WindowManager::closeNotRequested() {
	return !glfwWindowShouldClose(windowPtr);
}