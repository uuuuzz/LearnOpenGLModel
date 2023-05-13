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
    //����
    glm::vec3 Position;
    //������
    glm::vec3 Normal;
    //��������
    glm::vec2 TexCoords;
    //����
    glm::vec3 Tangent;
    //˫����
    glm::vec3 Bitangent;
    //Ӱ��˶���Ĺ�������
    int m_BoneIDs[MAX_BONE_INFLUENCE];
    //ÿ��������Ȩ��
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

    //���캯��
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    //��Ⱦ����
    void Draw(Shader& shader);
    
private:
    unsigned int VBO, EBO;
    void setupMesh();
};

