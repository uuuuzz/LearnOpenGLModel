#pragma once
#include <glad/glad.h> 
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"Shader.h"
#include<string>
#include<vector>

using namespace std;

#define MAX_BONE_INFLUENCE 4

struct Vertex {
    //顶点
    glm::vec3 Position;
    //法向量
    glm::vec3 Normal;
    //纹理坐标
    glm::vec2 TexCoords;
    //切线
    glm::vec3 Tangent;
    //双切线
    glm::vec3 Bitangent;
    //影响此顶点的骨骼索引
    int m_BoneIDs[MAX_BONE_INFLUENCE];
    //每根骨骼的权重
    float m_Weights[MAX_BONE_INFLUENCE];
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};

class Mesh
{
public:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;

    //构造函数
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    //渲染网格
    void Draw(Shader& shader);
    
private:
    unsigned int VBO, EBO;
    void setupMesh();
};

