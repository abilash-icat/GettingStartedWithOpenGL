
#include "Renderer.h"



Renderer::Renderer()
{
	basicShader = new Shader();
	basicShader->createShader("./shaders/vs.combined.glsl",
		"./shaders/fs.texture.glsl");
	setShader(basicShader);
}


Renderer::~Renderer()
{
	delete basicShader;
}

void Renderer::render(float delta)
{
	activeShader->start();
	
	glUniformMatrix4fv(activeShader->combinedLoc, 1, GL_FALSE,
		glm::value_ptr(activeSceneGraph->getCamera()->getCombinedMatrix()));

	for each (auto node in activeSceneGraph->getSceneNodes()){
		processSceneNode(node);
	}
	activeShader->stop();
}

void Renderer::updateShaderValues(const SceneNode* node) {
	glUniformMatrix4fv(activeShader->transformLoc, 1, GL_FALSE,
		glm::value_ptr(node->getTranslateMatrix()));
}

void Renderer::processSceneNode(const SceneNode* node) {

	updateShaderValues(node);
	renderModel(node->getModel());
	if (node->hasChildren()) {
		for each (auto child in node->getChildren())
			processSceneNode(child);
	}
}

void Renderer::renderModel(const Model* modelPtr) {
	glBindVertexArray(modelPtr->getVaoID());
	glBindTexture(GL_TEXTURE_2D, modelPtr->getMaterial()->getTextureID());
	glDrawArrays(GL_QUADS, 0, modelPtr->getNumVertices());
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}