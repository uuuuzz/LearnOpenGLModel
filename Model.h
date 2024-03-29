#pragma once

#include<vector>
#include<assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>
#include "Shader.h"
#include "Mesh.h"

class Model
{
public:
    Model(char* path);
    void Draw(Shader shader);

private:
    /*模型数据*/
    std::vector<Mesh>  meshes;
    std::string directory;
    
    /*函数*/
    void loadModel(string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh,const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

