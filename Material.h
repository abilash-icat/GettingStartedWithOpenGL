#pragma once
class Material
{
public:
	Material(unsigned int textureID);
	~Material();

	unsigned int getTextureID() const { return textureID; }

private:
	unsigned int textureID;
};

