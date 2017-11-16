#pragma once

#include <vector>
#include <algorithm>

#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Model.h"

class SceneNode
{
public:
	SceneNode(Model* model);
	~SceneNode();

	const Model* getModel() const { return modelPtr; }
	void setModel(Model* modelPtr) { this->modelPtr = modelPtr; }

	virtual void update(float delta);

	const glm::mat4& getTranslateMatrix() const { return translateMatrix; }

	void setPosition(float x, float y, float z);

	void setParent(SceneNode* node);
	const SceneNode* getParent() const { return parent; }
	bool isOrphan() const { return parent == nullptr; }

	void reparent(SceneNode* newParent);
	void removeChild(SceneNode* existingChild);

	bool addChild(SceneNode* child);
	const std::vector<SceneNode*>& getChildren() const { return children; }
	bool hasChildren() const { return children.size() > 0; }

	const int getWidth() const { modelPtr->getWidth(); }
	const int getHeight() const { modelPtr->getHeight(); }

	float getX() { return position.x; }
	float getY() { return position.y; }

private:
	void updateMatrices();
	
protected:
	SceneNode* parent;

	std::vector<SceneNode*> children;

	Model* modelPtr;
	glm::vec3 position;
	glm::mat4 translateMatrix;
};

