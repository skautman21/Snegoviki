/*
 * Texture.cc
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: unyuu
 */

#include "Texture.h"

#include <memory>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Texture::Texture(const char *filename)
{
	std::shared_ptr<SDL_Surface> tex_surf;  // Оригинальная текстура
	std::shared_ptr<SDL_Surface> conv_surf; // Конвертированная текстура

	tex_surf = std::shared_ptr<SDL_Surface>(
			IMG_Load(filename),
			SDL_FreeSurface);
	if (tex_surf == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить текстуру: ") +
				std::string(SDL_GetError()));

	conv_surf = std::shared_ptr<SDL_Surface>(
			SDL_CreateRGBSurfaceWithFormat(0,
					tex_surf->w, tex_surf->h,
					32, SDL_PIXELFORMAT_ABGR8888),
			SDL_FreeSurface);
	if (conv_surf == nullptr)
		throw std::runtime_error(
				std::string("Не удалось создать временную поверхность!"));

	SDL_UpperBlit(tex_surf.get(), nullptr, conv_surf.get(), nullptr);

	glGenTextures(1, &_tex);
	glBindTexture(GL_TEXTURE_2D, _tex);
	gluBuild2DMipmaps(GL_TEXTURE_2D,
			GL_RGBA,
			conv_surf->w, conv_surf->h,
			GL_RGBA, GL_UNSIGNED_BYTE,
			conv_surf->pixels);
}

Texture::~Texture()
{
	glDeleteTextures(1, &_tex);
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, _tex);
}
