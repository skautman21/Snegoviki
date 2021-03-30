/*
 * Window.h
 *
 *  Created on: 16 но€б. 2020 г.
 *      Author: unyuu
 */
#pragma once
#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <memory>

class Window
{
public:
	static constexpr int DEFAULT_WIDTH = 1920;
	static constexpr int DEFAULT_HEIGHT = 1080;
protected:
	std::shared_ptr<SDL_Window> _window;
	std::shared_ptr<void> _gl_context;

	int _width, _height;
public:
	Window(	int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	int height() const { return _height; }
	int width() const { return _width; }

	virtual void setup() {}
	virtual void render() {}

	virtual void do_logic() {}
	virtual void handle_event(const SDL_Event &event) {}
	virtual void handle_keys(const Uint8 *keys) {}

	void main_loop();
};

#endif /* WINDOW_H_ */
