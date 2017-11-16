#include "Dino.h"

Dino::Dino(Animation<Model*> *idle, Animation<Model*> *walk, Animation<Model*> *crouch)
	:SceneNode(walk->get(0))
	,idle(idle)
	,walk(walk)
	,crouch(crouch)
{
	active = this->walk;
	jumping = false;
	jumpForce = 0.001;
	gravity = -0.0002;
	jumpPressed = false;
}

Dino::~Dino()
{
}

void Dino::update(float delta)
{
	jumpPressed = UserInteraction::up | UserInteraction::space;

	if (jumpPressed) {
		jumping = true;
		jumpForce = 0.001;
	}

	if (jumping) updatePos(delta);
	setModel(active->get(delta));
	SceneNode::update(delta);
}

void Dino::updatePos(float delta) {
	float y = getY();

	y += jumpForce * delta;
	jumpForce += gravity * delta;

	if (y < GROUND) {
		y = GROUND;
		jumping = false;
	}

	setPosition(getX(), y, -0.01f);
}