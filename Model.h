#pragma once

#include "Mesh.h"
#include "Material.h"

class Model : public Mesh
{
public:
	Model(unsigned int vaoID, 
		unsigned int numVertices,
		Material* material,
		int width,
		int height);

	~Model();

	Material* getMaterial()const;

	const int getWidth()const { return width; }
	const int getHeight()const { return height; }

private:
	Material* material;
	int width, height;
};

