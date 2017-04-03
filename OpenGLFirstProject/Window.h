#pragma once

// Libraries being used
#include <SDL2\SDL.h>
#include <string>

/**
 * An SDL GL window
 *
 * @author  Anshul Kharbanda
 * @created 4 - 2 - 2017 
 */
class Window
{
private:
	/**
	 * SDL Window handle
	 */
	SDL_Window* m_window;

	/**
	 * SDL GL Context
	 */
	SDL_GLContext m_glcontext;

	/**
	 * Holds an SDL event
	 */
	SDL_Event m_event;

	/**
	 * True if the window is closed
	 */
	bool m_closed;
public:
	/**
	 * Creates a Window with the given title, width, and height
	 *
	 * @param title  the window title
	 * @param width  the width of the window
	 * @param height the height of the window
	 */
	Window(const std::string& title, unsigned width, unsigned height);

	/**
	 * Destroys the window
	 */
	virtual ~Window();

	/**
	 * Updates the window
	 */
	void Update();

	/**
	 * Returns true if the window is closed
	 *
	 * @return true if the window is closed
	 */
	bool IsClosed();
};