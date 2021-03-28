#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>

#include <SDL2/SDL_main.h>

#include "ExampleWindow.h"

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {
		ExampleWindow w;

		w.main_loop();

	} catch (std::exception & e) {
		std::cerr << "Во время работы программы возникло исключение:"
				<< std::endl
				<< e.what()
				<< std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Во время работы программы возникло "
				"неизвестное исключение!" << std::endl;
		return 1;
	}

	return 0;
}

