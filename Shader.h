#pragma once

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Shader
{
public:
	Shader();
	~Shader();

	bool createShader(const char * vertex_file_path, const char * fragment_file_path);
	void start();
	void stop();

private:
	void bindAttributes();

public:
	int shaderID;
	int textureLoc, transformLoc, combinedLoc, elapsedTimeLoc;
};

