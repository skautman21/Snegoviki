#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <memory>
#include <SDL2/SDL.h>

class Texture {
protected:
	std::shared_ptr<SDL_Renderer> _renderer;
	std::shared_ptr<SDL_Texture> _texture;

	int _width {0};
	int _height {0};
public:
	Texture(std::shared_ptr<SDL_Renderer> &renderer, const char *filename);
	virtual ~Texture() = default;

	int getHeight() const { return _height; }
	int getWidth() const { return _width; }

	void draw(SDL_Rect *what, SDL_Rect *where);
};

#endif /* TEXTURE_H_ */
