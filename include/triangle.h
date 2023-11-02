#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Shader;

struct TriangleMesh {
    TriangleMesh();

    unsigned int VAO;
    unsigned int VBO;


    void render();

};

struct Triangle {
    Triangle();
    virtual ~Triangle();

    TriangleMesh mesh;
    Shader* m_shader;

    void render();
};



#endif
