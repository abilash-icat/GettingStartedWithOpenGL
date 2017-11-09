#pragma once

#include "Mesh.h"
#include "Material.h"

class Model : public Mesh
{
public:
	Model(unsigned int vaoID, 
		unsigned int numVertices,
		Material* material);

	~Model();

	Material* getMaterial()const;

private:
	Material* material;
};

