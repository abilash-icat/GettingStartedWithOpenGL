#pragma once

#include <vector>
#include "OrthoCamera.h"
#include "SceneNode.h"

class SceneGraph
{
public:
	SceneGraph();
	~SceneGraph();

	void addSceneNode(SceneNode* sceneNode);
	void setCamera(OrthoCamera* camera) { this->camera = camera; }
	const OrthoCamera* getCamera() const { return camera; }

	const std::vector<SceneNode*> getSceneNodes()const { return sceneNodes; }

private:
	std::vector<SceneNode*> sceneNodes;
	OrthoCamera* camera;
};

