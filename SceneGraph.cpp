#include "SceneGraph.h"



SceneGraph::SceneGraph()
{
}


SceneGraph::~SceneGraph()
{
}


void SceneGraph::addSceneNode(SceneNode* sceneNode) {
	sceneNodes.push_back(sceneNode);
}

void SceneGraph::update(float delta) {
	for (auto n : sceneNodes) {
		n->update(delta);
	}
}