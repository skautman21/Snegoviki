/*
 * Window.cc
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: unyuu
 */
#include <stdexcept>
#include "Window.h"

Window::Window(int width, int height)
: _width(width), _height(height)
{
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"OpenGL Window",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width, height,
					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL),
			SDL_DestroyWindow);
	if (_window == nullptr)
		throw std::runtime_error(
				std::string("Не удалось создать окно: ") +
				std::string(SDL_GetError()));

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	_gl_context = std::shared_ptr<void>(
			SDL_GL_CreateContext(_window.get()),
			SDL_GL_DeleteContext);
	if (_gl_context == nullptr)
		throw std::runtime_error(
				std::string("Не удалось создать контекст OpenGL: ") +
				std::string(SDL_GetError()));

	SDL_GL_SetSwapInterval(1);
}

void Window::main_loop()
{
	setup();

	SDL_Event event;
	auto keys = SDL_GetKeyboardState(nullptr);

	for (;;) {
		// Обработка событий
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
			handle_event(event);
		}
		// Обработка клавиш
		if (keys[SDL_SCANCODE_ESCAPE]) return;
		handle_keys(keys);

		// Выполнение логики для подготовки каждого кадра
		do_logic();

		// Отрисовка
		render();

		// Отображение результата
		SDL_GL_SwapWindow(_window.get());
	}
}
