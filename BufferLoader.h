#pragma once

#include"GL/glew.h"
#include<vector>

#include <SOIL.h>

#include "Definitions.h"
class BufferLoader
{
public:
	BufferLoader();
	~BufferLoader();

	unsigned int loadToBuffer(std::vector<float> positions, std::vector<float> uvs);
	unsigned int loadTexture(const char* filename, int* width, int* height);

private:
	void createVAO(unsigned int *vaoID);
	void storeToVBO(std::vector<float> data, unsigned int location, unsigned int length);
	void unbindVAO();
};

