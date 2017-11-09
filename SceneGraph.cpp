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