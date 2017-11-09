#pragma once
class Mesh
{
public:
	Mesh(unsigned int vaoID, unsigned int numVertices);
	~Mesh();

	unsigned int getVaoID() const { return vaoID; }
	unsigned int getNumVertices() const { return numVertices; }

private:
	unsigned int vaoID, numVertices;
};

