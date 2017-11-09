#pragma once

#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class OrthoCamera
{
public:
	OrthoCamera();
	~OrthoCamera();

	void setViewport(float width, float height);
	void setNearAndFarPlane(float nearPlane, float farPlane);

	const glm::mat4& getCombinedMatrix()const { return combinedMatrix; }

private:
	void initDefaultValues();
	void updateMatrices();

private:
	float left, right, top, bottom;
	float nearPlane, farPlane;

	glm::vec3 position, lookAt, up;

	glm::mat4 view, projection, combinedMatrix;
};

