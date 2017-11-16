#include <iostream>
#include <vector>
#include "Definitions.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.h"
#include "Model.h"
#include "SceneNode.h"

#include "SceneGraph.h"

#include "BufferLoader.h"
#include "Renderer.h"
#include "WindowManager.h"

#include "Dino.h"

bool UserInteraction::left = false;
bool UserInteraction::right = false;
bool UserInteraction::up = false;
bool UserInteraction::down = false;
bool UserInteraction::space = false;
bool UserInteraction::escape = false;

SceneGraph* sceneGraph;
BufferLoader* bufferLoader;
OrthoCamera* camera;

Model* createModel(const char* filename, float layer) {
	int width, height, textureID, vaoID;

	textureID = bufferLoader->loadTexture(filename, &width, &height);

	int halfWidth, halfHeight;
	halfWidth = width / 2;
	halfHeight = height / 2;

	std::vector<float> positions;
	positions.push_back(-halfWidth);
	positions.push_back(-halfHeight);
	positions.push_back(layer);

	positions.push_back(-halfWidth);
	positions.push_back(halfHeight);
	positions.push_back(layer);

	positions.push_back(halfWidth);
	positions.push_back(halfHeight);
	positions.push_back(layer);

	positions.push_back(halfWidth);
	positions.push_back(-halfHeight);
	positions.push_back(layer);

	std::vector<float> uvs;

	uvs.push_back(0);
	uvs.push_back(1);

	uvs.push_back(0);
	uvs.push_back(0);

	uvs.push_back(1);
	uvs.push_back(0);

	uvs.push_back(1);
	uvs.push_back(1);

	vaoID = bufferLoader->loadToBuffer(positions, uvs);

	Material* material = new Material(textureID);
	return new Model(vaoID, 4, material, width, height);
}

SceneNode* createSceneNode(const char* filename, float layer) {
	
	Model* model = createModel(filename, layer);

	return new SceneNode(model);
}

Dino* createDino() {

	std::vector<Model*> *idle, *walk, *crouch;

	idle = new std::vector<Model*>();
	walk = new std::vector<Model*>();
	crouch = new std::vector<Model*>();

	idle->push_back(createModel("./assets/dinoIdle.png", -0.01f));

	walk->push_back(createModel("./assets/walk1.png", -0.01f));
	walk->push_back(createModel("./assets/walk2.png", -0.01f));

	crouch->push_back(createModel("./assets/crouched1.png", -0.01f));
	crouch->push_back(createModel("./assets/crouched2.png", -0.01f));

	Animation<Model*> *idleAnim = new Animation<Model*>(*idle, 1);
	Animation<Model*> *walkAnim = new Animation<Model*>(*walk, 8000);
	Animation<Model*> *crouchAnim = new Animation<Model*>(*crouch, 300.f);

	return new Dino(idleAnim, walkAnim, crouchAnim);

}

void initWorld() {

	Model* groundModel = createModel("./assets/ground.png", 0);
	SceneNode* groundNode1 = new SceneNode(groundModel);
	SceneNode* groundNode2 = new SceneNode(groundModel);
	groundNode1->setPosition(0, -80, 0);
	groundNode2->setPosition(groundModel->getWidth(), -80, 0);

	Dino* dino = createDino();
	dino->setPosition(-(groundModel->getWidth() / 2), 0, 0);
	
	camera = new OrthoCamera();
	camera->setViewport(WINDOW_WIDTH, WINDOW_HEIGHT);

	sceneGraph = new SceneGraph();
	sceneGraph->setCamera(camera);
	sceneGraph->addSceneNode(groundNode1);
	sceneGraph->addSceneNode(groundNode2);
	sceneGraph->addSceneNode(dino);
}

void main() {

	WindowManager* windowManager = new WindowManager(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	windowManager->init();
	
	bufferLoader = new BufferLoader();
	
	initWorld();

	windowManager->getRenderer()->setSceneGraph(sceneGraph);

	do {
		float delta = windowManager->getElapsedTime();
		sceneGraph->update(delta);
		windowManager->update(delta);
	} while (windowManager->closeNotRequested());

}
