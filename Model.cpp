#include "Model.h"



Model::Model(unsigned int vaoID,
	unsigned int numVertices,
	Material* material)
	:Mesh(vaoID, numVertices)
	,material(material)
{
}

Model::~Model()
{
}

Material* Model::getMaterial() const {
	return material;
}