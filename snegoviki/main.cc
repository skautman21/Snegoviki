/*
 * main.cc
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: unyuu
 */

/*
 * Список библиотек проекта (для всех ОС, кроме Windows):
 * SDL2
 * SDL2_image
 * GL
 * GLU
 *
 * Для _некоторых_ ОС (напр. Android) первой должна быть
 * SDL2main
 *
 * Список библиотек для Windows, если используется MinGW:
 * mingw32
 * SDL2main
 * SDL2
 * SDL2_image
 * opengl32
 * glu32
 *
 * OpenGL 4.6
 * OpenGL 1.x-2.2	<--
 * OpenGL 3.x-4.6
 * Vulkan ?????
 *
 */
#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "ExampleWindow.h"

#include <SDL2/SDL_main.h>

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {
		ExampleWindow w;

		w.main_loop();

	} catch (const std::exception &e) {
		std::cerr << "При выполнении программы "
				"произошла ошибка:" << std::endl <<
				e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr << "При выполнении программы "
				"произошла неизвестная ошибка!"
				<< std::endl;
		return 1;
	}

	return 0;
}

