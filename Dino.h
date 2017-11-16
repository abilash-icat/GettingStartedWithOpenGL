#pragma once
#include <vector>
#include "Definitions.h"
#include "SceneNode.h"
#include "Model.h"
#include "Animation.h"
#include "UserInteraction.h"
class Dino : public SceneNode
{
public:
	Dino(Animation<Model*> *idle, Animation<Model*> *walk, Animation<Model*> *crouch);
	~Dino();


	virtual void update(float delta);
	void updatePos(float delta);

private:
	bool jumping, jumpPressed;
	float jumpForce, gravity;
	Animation<Model*> *idle, *walk, *crouch, *active;
};

