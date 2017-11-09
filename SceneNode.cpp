#include "SceneNode.h"



SceneNode::SceneNode(Model* model)
	:modelPtr(model)
{
	parent = nullptr;
}


SceneNode::~SceneNode()
{
}


void SceneNode::setPosition(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;

	updateMatrices();
}

void SceneNode::updateMatrices() {
	glm::mat4 identity;
	translateMatrix = glm::translate(identity, position);
}

bool SceneNode::addChild(SceneNode* node) {
	if (node->isOrphan()) {
		children.push_back(node);
		node->setParent(this);
		return true;
	}
	return false;
}

void SceneNode::setParent(SceneNode* node) {
	parent = node;
}

void SceneNode::reparent(SceneNode* newParent) {
	if (!isOrphan() && parent != newParent) {
		parent->removeChild(this);
		setParent(newParent);
	}
}

void SceneNode::removeChild(SceneNode* existingChild) {
	children.erase(std::remove(children.begin(), children.end(), existingChild), children.end());
}