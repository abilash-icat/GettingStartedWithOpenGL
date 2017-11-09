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

Model* meshWM;
SceneGraph* sceneGraph;
SceneNode *parentNode, *childNode;
BufferLoader* bufferLoader;

OrthoCamera* camera;

void initQuad() {
	float size = 0.5f;
	std::vector<float> positions;

	//left top traingle
	positions.push_back(-size);
	positions.push_back(-size);
	positions.push_back(0);

	positions.push_back(-size);
	positions.push_back(size);
	positions.push_back(0);

	positions.push_back(size);
	positions.push_back(size);
	positions.push_back(0);

	//right bottom traingle
	positions.push_back(-size);
	positions.push_back(-size);
	positions.push_back(0);


	positions.push_back(size);
	positions.push_back(size);
	positions.push_back(0);


	positions.push_back(size);
	positions.push_back(-size);
	positions.push_back(0);
	
	std::vector<float> uvs;

	uvs.push_back(0);
	uvs.push_back(1);

	uvs.push_back(0);
	uvs.push_back(0);

	uvs.push_back(1);
	uvs.push_back(0);


	uvs.push_back(0);
	uvs.push_back(1);

	uvs.push_back(1);
	uvs.push_back(0);

	uvs.push_back(1);
	uvs.push_back(1);
	
	meshWM = new Model(
		bufferLoader->loadToBuffer(positions, uvs), 
		positions.size() / 3, 
		new Material(
			bufferLoader->loadTexture("./assets/smiley.png")));

	parentNode = new SceneNode(meshWM);
	childNode = new SceneNode(meshWM);

	parentNode->addChild(childNode);

	camera = new OrthoCamera();
	camera->setViewport(WINDOW_WIDTH / 50 , WINDOW_HEIGHT / 50);

	sceneGraph = new SceneGraph();
	sceneGraph->setCamera(camera);
	sceneGraph->addSceneNode(parentNode);
}

void main() {

	WindowManager* windowManager = new WindowManager(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	windowManager->init();
	
	bufferLoader = new BufferLoader();
	
	float xpos = -0.5;
	initQuad();

	windowManager->getRenderer()->setSceneGraph(sceneGraph);

	do {
		xpos += 0.000005 * windowManager->getElapsedTime();
		parentNode->setPosition(xpos, 0, 0);
		
		windowManager->update(windowManager->getElapsedTime());
	} while (windowManager->closeNotRequested());

}
