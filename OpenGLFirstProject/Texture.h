#pragma once

// Libraries being used
#include <string>
#include <GL\glew.h>

/**
 * Holds a texture in OpenGL
 *
 * @author  Anshul Kharbanda
 * @created 4 - 2 - 2017
 */
class Texture
{
private:
	/**
	 * The texture handle
	 */
	GLuint m_texture;
public:
	/**
	 * Loads a texture from the given filename
	 *
	 * @param filename the name of the file to read
	 */
	Texture(const std::string& filename);
	
	/**
	 * Destroys the Texture
	 */
	~Texture();

	/**
	 * Binds the Texture
	 */
	void Bind();
};

