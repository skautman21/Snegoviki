#include "Window.h"

#include <stdexcept>

Window::Window(int width, int height)
: _width(width), _height(height)
{
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"SDL window",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					_width, _height,
					SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);
	if (_window == nullptr)
		throw std::runtime_error(
				std::string("При создании окна произошла ошибка: ") +
				std::string(SDL_GetError()));

	_renderer = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(
					_window.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (_renderer == nullptr)
		throw std::runtime_error(
				std::string("При создании рендерера "
						"произошла ошибка: ") +
				std::string(SDL_GetError()));
}

void Window::main_loop()
{
	setup();

	auto keys = SDL_GetKeyboardState(nullptr);
	SDL_Event event;
	for(;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
			handle_event(event);
		}
		handle_keys(keys);

		do_logic();

		render();

		SDL_RenderPresent(_renderer.get());
	}
}
