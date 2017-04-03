// Headers being used
#include "Mesh.h"

/**
 * Creates a vertex with the given data
 *
 * @param p the position of the vertex
 */
Vertex::Vertex(glm::vec3 p, glm::vec2 t)
{
	pos = p;
	tex = t;
}

/**
 * Creates a mesh with the given 
 *
 * @param vertices    the vertices to draw
 * @param numVertices the number of vertices to draw
 */
Mesh::Mesh(Vertex* vertices, unsigned numVertices)
{
	// Set numVertices
	m_numVertices = numVertices;

	// Create arrays
	glGenVertexArrays(1, &m_vertexArrayObject);
	glGenBuffers(1, &m_vertexDataBuffer);

	// Fill data array
	glBindVertexArray(m_vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexDataBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	// Set attribute array
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*)12);

	// Unbind array
	glBindVertexArray(0);
}

/**
 * Destroys the Mesh
 */
Mesh::~Mesh()
{
	glDeleteBuffers(1, &m_vertexDataBuffer);
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

/**
 * Draws the Mesh
 */
void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, m_numVertices);
	glBindVertexArray(0);
}