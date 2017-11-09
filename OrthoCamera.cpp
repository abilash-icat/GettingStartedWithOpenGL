#include "OrthoCamera.h"



OrthoCamera::OrthoCamera()
{
	initDefaultValues();
	updateMatrices();
}

OrthoCamera::~OrthoCamera()
{
}

void OrthoCamera::initDefaultValues() {

	nearPlane = 0.0f;
	farPlane = 10.0f;

	left = -1;
	right = 1;
	top = 1;
	bottom = -1;

	position.x = position.y = position.z = 0;

	lookAt.x = lookAt.y = 0;
	lookAt.z = 1.0f;

	up.x = up.z = 0;
	up.y = 1;
}

void OrthoCamera::updateMatrices() {
	view = glm::translate(glm::mat4(1), -position);
	projection = glm::ortho(left, right, bottom, top, nearPlane, farPlane);

	combinedMatrix = projection * view;
}

void OrthoCamera::setViewport(float width, float height){
	left = -(width / 2.0f);
	right = width / 2.0f;

	bottom = -(height / 2.0f);
	top = height / 2.0f;

	updateMatrices();
}

void OrthoCamera::setNearAndFarPlane(float nearPlane, float farPlane) {
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;

	updateMatrices();
}