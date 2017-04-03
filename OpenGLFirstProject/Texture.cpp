// Headers being used
#include "Texture.h"
#include "stb_image.h"

/**
 * Loads a texture from the given filename
 *
 * @param filename the name of the file to read
 */
Texture::Texture(const std::string& filename)
{
	// Get image data
	int width, height, numComps;
	stbi_uc* img = stbi_load(filename.c_str(), &width, &height, &numComps, 4);

	// Create texture
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	// Set Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Push image data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);

	// Delete image data
	stbi_image_free(img);
}

/**
 * Destroys the Texture
 */
Texture::~Texture()
{
	glDeleteTextures(1, &m_texture);
}

/**
 * Binds the Texture
 */
void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}