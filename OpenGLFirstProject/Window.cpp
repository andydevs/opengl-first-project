// Headers being used
#include "Window.h"

/**
 * Creates a Window with the given title, width, and height
 *
 * @param title  the window title
 * @param width  the width of the window
 * @param height the height of the window
 */
Window::Window(const std::string& title, unsigned width, unsigned height)
{
	m_window = SDL_CreateWindow(title.c_str(), 
								SDL_WINDOWPOS_CENTERED, 
								SDL_WINDOWPOS_CENTERED, 
								width, height,
								SDL_WINDOW_OPENGL);
	m_glcontext = SDL_GL_CreateContext(m_window);
	m_closed = false;
}

/**
 * Destroys the window
 */
Window::~Window()
{
	SDL_GL_DeleteContext(m_glcontext);
	SDL_DestroyWindow(m_window);
}

/**
 * Updates the window
 */
void Window::Update()
{
	// Swap buffers
	SDL_GL_SwapWindow(m_window);

	// Check for close event
	while (SDL_PollEvent(&m_event)) {
		if (m_event.type == SDL_QUIT) {
			m_closed = true;
			break;
		}
	}
}

/**
 * Returns true if the window is closed
 *
 * @return true if the window is closed
 */
bool Window::IsClosed()
{
	return m_closed;
}