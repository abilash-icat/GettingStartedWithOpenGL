#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "SceneGraph.h"
#include "Model.h"
#include "SceneNode.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void render(float delta);
	void setSceneGraph(SceneGraph* sceneGraph) { activeSceneGraph = sceneGraph; }
	void setShader(Shader* shader) { activeShader = shader; }

private:
	void updateShaderValues(const SceneNode* node);
	void processSceneNode(const SceneNode* node);

	void renderModel(const Model* modelPtr);

private:
	Shader *basicShader, *activeShader;
	SceneGraph *activeSceneGraph;
};

