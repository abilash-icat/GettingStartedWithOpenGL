#include "Model.h"



Model::Model(unsigned int vaoID,
	unsigned int numVertices,
	Material* material,
	int width,
	int height)
	:Mesh(vaoID, numVertices)
	,material(material)
	,width(width)
	,height(height)
{
}

Model::~Model()
{
}

Material* Model::getMaterial() const {
	return material;
}