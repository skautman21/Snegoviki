#include "RayCastingWindow.h"
#include <cassert>
#include <iostream>


RayCastingWindow::RayCastingWindow(int width, int height)
: Window(width, height)
{
	_map = std::make_shared<Map>("map.txt");
	_player = std::make_shared<Player>(_map);
	_wall_texture = std::make_shared<Texture>(_renderer, "stone.jpg");
}
void RayCastingWindow::render()
{

	SDL_Rect r_sky { 0, 0, width(), height() / 2 };
	SDL_Rect r_floor { 0, height() / 2, width(), height() / 2 };
	SDL_SetRenderDrawColor(_renderer.get(), 176, 214, 245, 255);
	SDL_RenderFillRect(_renderer.get(), &r_sky);
	SDL_SetRenderDrawColor(_renderer.get(), 26 , 46, 61, 255);
	SDL_RenderFillRect(_renderer.get(), &r_floor);

	SDL_SetRenderDrawBlendMode(_renderer.get(), SDL_BLENDMODE_BLEND);

	double sd = width() / ( 2 * tan ( _player->DEFAULT_FOV / 2 ) );
		double ry = 0, rx = 0, dy = 0, dx = 0, D_h = 0, D_v = 0, h = 0, gamma = 0, betta = 0, tx = 0;

		for(int col = 0; col < width(); ++col){
			gamma = atan( ( col - width() / 2 ) / sd );

			betta = _player->dir() + gamma;

			if ( -EPSILON <= sin( betta ) and sin( betta ) <= EPSILON){
				D_h = INFINITY;
			}
			else{
				if ( sin( betta ) > EPSILON ){
					dy = 1;
					ry = floor( _player->y() ) + EPSILON;
					dx =  1 / tan( betta );
					rx = _player->x() - ( _player->y() - ry ) * dx;
				}

				else if ( sin( betta ) < -EPSILON ){
					dy = -1;
					ry = ceil( _player->y() ) - EPSILON;
					dx = 1 / tan( -betta );
					rx = _player->x() - ( ry - _player->y() ) * dx;
				}

				do{
					rx += dx;
					ry += dy;
				}while ( not _map->wall(rx, ry) );
				D_h = sqrt( pow( rx - _player->x(), 2 ) + pow( ry - _player->y(), 2 ) );
				tx = rx - floor(rx);
			}

			if ( -EPSILON <= cos( betta ) and cos( betta ) <= EPSILON){
				D_v = INFINITY;
			}
			else{
				if ( cos( betta ) > EPSILON){
					dx = 1;
					rx = floor( _player->x() ) + EPSILON;
					dy = tan( betta );
					ry = _player->y() - ( _player->x() - rx) * dy;
				}

				else if ( cos( betta ) < -EPSILON){
					dx = -1;
					rx = ceil( _player->x() ) - EPSILON;
					dy = tan( -betta );
					ry = _player->y() - ( rx - _player->x() ) * dy;
				}

				do{
					rx += dx;
					ry += dy;
				}while ( not _map->wall(rx, ry) );

				D_v = sqrt( pow( rx - _player->x(), 2 ) + pow( ry - _player->y(), 2 ) );

			}
			if(D_v < D_h){
				h = sd * 0.5 / D_v;
				tx = ry - floor(ry);
			}
			else{
				h = sd * 0.5 / D_h;
			}

			draw_textured_col(col, h, tx);
		}


	SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 64);
	for (int y = 0; y < _map->height(); ++y)
		for (int x = 0; x < _map->width(); ++x) {
			SDL_Rect r { x * 50, y * 50, 50, 50 };
			if (_map->wall(x, y))
				SDL_RenderFillRect(_renderer.get(), &r);
		}

	SDL_Rect r_player {
		int(_player->x() * 50)-10,
		int(_player->y() * 50)-10,
		15, 15
	};
	SDL_Rect r_player_eye {
		int(_player->x() * 50 + 20*cos(_player->dir()))-5,
		int(_player->y() * 50 + 20*sin(_player->dir()))-5,
		7, 7
	};

	SDL_SetRenderDrawColor(_renderer.get(), 255, 64, 64, 255);
	SDL_RenderFillRect(_renderer.get(), &r_player);
	SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 0, 255);
	SDL_RenderFillRect(_renderer.get(), &r_player_eye);
}

void RayCastingWindow::draw_col(int col, int h)
{
	SDL_SetRenderDrawColor(_renderer.get(), 64, 64, 64, 255);
	int y1 = height() / 2 - h / 2;
	int y2 = height() / 2 + h / 2;
	SDL_RenderDrawLine(_renderer.get(), col, y1, col, y2);

}

void RayCastingWindow::draw_textured_col(int col, int h, double tx)
{
	SDL_Rect what { int(floor(_wall_texture->getWidth() * tx)),
	0,
	1,
	_wall_texture->getHeight()};
	SDL_Rect where { col, height() / 2 - h / 2, 1, h };
	_wall_texture->draw(&what, &where);

}

void RayCastingWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_W]) _player->walk_forward();
	if (keys[SDL_SCANCODE_S]) _player->walk_backward();
	if (keys[SDL_SCANCODE_D]) _player->shift_right();
	if (keys[SDL_SCANCODE_A]) _player->shift_left();
	if (keys[SDL_SCANCODE_E]) _player->turn_right();
	if (keys[SDL_SCANCODE_Q]) _player->turn_left();
}
