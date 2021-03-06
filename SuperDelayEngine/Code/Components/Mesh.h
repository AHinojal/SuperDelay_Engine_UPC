#pragma once
#include <assimp/mesh.h>
#include "../../MathGeoLib/Math/float4x4.h"

class Mesh
{
public:
	Mesh();
	Mesh(unsigned programId);
	~Mesh();

	void CreateVAO();
	void LoadVBO(const aiMesh* mesh);
	void LoadEBO(const aiMesh* mesh);
	void Draw(const std::vector<unsigned>& model_textures);
	unsigned getVBO() { return vbo; };
	unsigned getVAO() { return vao; };
	unsigned getEBO() { return ebo; };
	void CleanUp();
	unsigned int getVertexs() { return nVertexs; };
	unsigned int getIndexs() { return nIndexes;};
	unsigned int getFaces() { return nFaces; };

	void DrawLenna();

private:
	// Program
	unsigned program;
	// VBO & EBO
	unsigned vbo, vao, ebo;
	// Data VBO
	unsigned int nVertexs = 0;
	unsigned int nIndexes = 0;
	unsigned int nFaces = 0;
	unsigned int textureIndex = 0;

};

