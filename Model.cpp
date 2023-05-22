#include "Model.h"

Model::Model(char* path)
{
}

void Model::Draw(Shader shader)
{
}

void Model::loadModel(string path)
{
}

void Model::processNode(aiNode node, const aiScene* scene)
{
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
    return std::vector<Texture>();
}
