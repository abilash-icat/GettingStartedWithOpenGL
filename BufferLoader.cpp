
#include "BufferLoader.h"



BufferLoader::BufferLoader()
{
}


BufferLoader::~BufferLoader()
{
}

unsigned int BufferLoader::loadToBuffer(std::vector<float> positions, std::vector<float> uvs)
{
	unsigned int vaoID;
	createVAO(&vaoID);
	storeToVBO(positions, POSITION_LOCATION, POSITION_LENGTH);
	storeToVBO(uvs, TEX_COORD_LOCATION, TEX_COORD_LENGTH);
	unbindVAO();
	return vaoID;
}

void BufferLoader::createVAO(unsigned int *vaoID)
{
	glGenVertexArrays(1, vaoID);
	glBindVertexArray(*vaoID);
}

void BufferLoader::storeToVBO(std::vector<float> data, unsigned int location, unsigned int length)
{

	float* floatBufferPtr = new float[data.size()];
	int i = 0;
	for (auto f : data)
		floatBufferPtr[i++] = f;
	/*std::vector<float>::iterator current = data.begin();
	std::vector<float>::iterator end = data.end();
	for (int i = 0; current != end; current++, i++)
	{
		floatBufferPtr[i] = *current;
	}*/

	unsigned int vboID;
	glGenBuffers(1, &vboID);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), floatBufferPtr, GL_STATIC_DRAW);

	glVertexAttribPointer(location, length, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(location);
}

unsigned int BufferLoader::loadTexture(const char* filename, int* width, int* height)
{
	GLuint textureID;
	unsigned char * image;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Load, create texture and generate mipmap
	image = SOIL_load_image(filename, width, height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *width, *height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(image);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	
	return textureID;
}

void BufferLoader::unbindVAO()
{
	glBindVertexArray(0);
}
