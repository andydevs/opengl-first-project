#pragma once

// Libraries being used
#include <GL/glew.h>
#include <string>

/**
 * An GLSL shader program
 *
 * @author  Anshul Kharbanda
 * @created 4 - 2 - 2017
 */
class Shader
{
private:
	/**
	 * Number of shaders being held
	 */
	static const unsigned NUM_SHADERS = 2;

	/**
	 * The shader program
	 */
	GLuint m_program;

	/**
	 * The shader being held
	 */
	GLuint m_shaders[NUM_SHADERS];
public:
	/**
	 * Loads a shader from the given filename
	 *
	 * @param filename the name of the file to load
	 */
	Shader(const std::string& filename);

	/**
	 * Destroys the shader
	 */
	~Shader();

	/**
	 * Binds the shader
	 */
	void Bind();

	/**
	 * Returns the program
	 *
	 * @return the program
	 */
	GLuint GetProgram();
};

