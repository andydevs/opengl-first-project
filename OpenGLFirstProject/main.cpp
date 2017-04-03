// Headers being used
#include "Window.h"
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"

// Libraries being used
#include <iostream>
#include <SDL2\SDL.h>
#include <GL\glew.h>
#include <GLM\glm.hpp>

/**
 * The main function of the program
 *
 * @param argc the number of command line arguments
 * @param argv the command line arguments
 *
 * @return status code
 */
int main(int argc, char* argv[])
{
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,     8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,   8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,   8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Create window
	Window window("Hello World!", 800, 600);

	// Initialize glew
	GLenum status = glewInit();
	if (status != GLEW_OK) {
		std::cerr << "ERROR: Glew failed to initialize!" << std::endl;
		SDL_Quit();
		return 1;
	}

	// Load resources
	Shader shader("./res/shader.glsl");
	Texture texture("./res/bricks.jpg");

	// Initialize mesh
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5,  -0.5f,  0.0f), glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3( 0.0f,  0.5f,  0.0f), glm::vec2(0.5f,1.0f)),
		Vertex(glm::vec3( 0.5f, -0.5f,  0.0f), glm::vec2(1.0f,0.0f))
	};
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	// Start main loop
	while (!window.IsClosed()) {
		// Clear window
		glClearColor(0.0f, 0.15f, 0.33f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Bind resources
		shader.Bind();
		texture.Bind();

		// Draw mesh
		mesh.Draw();

		// Update window
		window.Update();
	}

	// End SDL
	SDL_Quit();
	return 0;
}