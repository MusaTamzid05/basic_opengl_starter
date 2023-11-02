#include "triangle.h"
#include "shader.h"


TriangleMesh::TriangleMesh() {
	
	float vertices[] = {
		 -0.5f, -0.5f, 0.f,  // bottom right
		  0.5f, -0.5f, 0.0f,  // bottom left
		 0.0f,  0.5f, 0.0f   // top left
	}; 

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


}

void TriangleMesh::render() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}


Triangle::Triangle() {
    m_shader = new Shader("../shaders/triangle.vs", "../shaders/triangle.fs");
}

Triangle::~Triangle() {
    delete m_shader;
}

void Triangle::render() {
    m_shader->use();
    mesh.render();


}
