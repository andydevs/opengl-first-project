#pragma once

// Libraries being used
#include <GL/glew.h>
#include <GLM\glm.hpp>

/**
 * An OpenGL mesh vertex
 *
 * @author  Anshul Kharanda
 * @created 4 - 2 - 2017
 */
struct Vertex {
	/**
	 * Position of the vertex
	 */
	glm::vec3 pos;

	/**
	 * Creates a vertex with the given data
	 *
	 * @param p the position of the vertex
	 */
	Vertex(glm::vec3 p);
};

/**
 * An OpenGL object mesh
 *
 * @author  Anshul Kharanda
 * @created 4 - 2 - 2017
 */
class Mesh
{
private:
	/**
	 * Number of vertices
	 */
	unsigned m_numVertices;

	/**
	 * Vertex array object
	 */
	GLuint m_vertexArrayObject;

	/**
	 * Vertex data buffer
	 */
	GLuint m_vertexDataBuffer;
public:
	/**
	 * Creates a mesh with the given 
	 *
	 * @param vertices    the vertices to draw
	 * @param numVertices the number of vertices to draw
	 */
	Mesh(Vertex* vertices, unsigned numVertices);

	/**
	 * Destroys the Mesh
	 */
	~Mesh();

	/**
	 * Draws the Mesh
	 */
	void Draw();
};

