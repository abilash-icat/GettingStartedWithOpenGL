#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#include <GLFW\glfw3.h>

class UserInteraction {

public:

	static bool left, right, up, down, space, escape;
public:
	UserInteraction() {
	}
	~UserInteraction() {}

	static void keyEvent(GLFWwindow* window, int key, int scancode, int action, int mode) {
		bool keyDown = (action == GLFW_PRESS) | (action == GLFW_REPEAT);

		switch (key)
		{
		case GLFW_KEY_UP:
			up = keyDown;
			break;
		case GLFW_KEY_DOWN:
			down = keyDown;
			break;
		case GLFW_KEY_LEFT:
			left = keyDown;
			break;
		case GLFW_KEY_RIGHT:
			right = keyDown;
			break;
		default:
			break;
		}
	}
};

#endif //USER_INTERACTION_H