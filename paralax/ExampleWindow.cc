#include "ExampleWindow.h"

#include <stdexcept>
#include <SDL2/SDL_image.h>

ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height), _bee_x(500), _bee_y(300), _bee_phase(0.),
  _car_x(180), _car_y(610),_sun_x(1500), _sun_y(150),_mounts_x(0),_mounts_y(350),_mounts_x1(1900),_mounts_y1(350),
  _cloud1_x(0),_cloud1_y(60),_cloud11_x(1900),_cloud11_y(60),_cloud2_x(800),_cloud2_y(120),
  _road_x(0),_road_y(650),_road1_x(1900),_road1_y(650),
  _lug_x(0),_lug_y(150),_lug1_x(1900),_lug1_y(150),
  _stolbiki_rect11_x(200),_stolbiki_rect12_x(510),_stolbiki_rect13_x(850),_stolbiki_rect14_x(1170),_stolbiki_rect15_x(1500),
  _stolbiki_rect21_x(200),_stolbiki_rect22_x(510),_stolbiki_rect23_x(850),_stolbiki_rect24_x(1170),_stolbiki_rect25_x(1500),
  _drevo_x(750),_drevo_y(400),_kust_x(2600),_kust_y(550),_flower_x(870), _flower_y(870),
  _znak_x(2700), _znak_y(750),_bee_main_x(870), _bee_main_y(870)

{

	//_bee = std::shared_ptr<SDL_Texture>(
	//		IMG_LoadTexture(_renderer.get(), "bzzzz2.png"),
	//		SDL_DestroyTexture);
	//if (_bee == nullptr)
	//	throw std::runtime_error(
	//			std::string("Не удалось загрузить пчелу: ") +
	//			std::string(SDL_GetError()));
	_skying = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "skying.png"),
			SDL_DestroyTexture);
		if (_skying == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить небо: ") +
				std::string(SDL_GetError()));
	_sun = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "sun.png"),
				SDL_DestroyTexture);
		if (_sun == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить Солнце: ") +
				std::string(SDL_GetError()));
	_cloud1 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "cloud1.png"),
				SDL_DestroyTexture);
		if (_cloud1 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить первый слой облаков: ") +
				std::string(SDL_GetError()));
	_cloud11 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "cloud11.png"),
				SDL_DestroyTexture);
		if (_cloud11 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить первый слой облаков: ") +
				std::string(SDL_GetError()));
	_cloud2 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "cloud2.png"),
				SDL_DestroyTexture);
		if (_cloud2 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить второй слой облаков: ") +
				std::string(SDL_GetError()));
	_lug = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "lug.png"),
				SDL_DestroyTexture);
		if (_lug == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить луг: ") +
				std::string(SDL_GetError()));
	_lug1 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "lug1.png"),
				SDL_DestroyTexture);
		if (_lug1 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить луг: ") +
				std::string(SDL_GetError()));
	_mounts = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "mounts.png"),
				SDL_DestroyTexture);
		if (_mounts == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить горы: ") +
				std::string(SDL_GetError()));
	_mounts1 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "mounts1.png"),
				SDL_DestroyTexture);
		if (_mounts1 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить горы: ") +
				std::string(SDL_GetError()));
	_road = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "road.png"),
				SDL_DestroyTexture);
		if (_road == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить дорогу: ") +
				std::string(SDL_GetError()));
	_stolbiki = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "stolbiki.png"),
				SDL_DestroyTexture);
		if (_stolbiki == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить дорожные столбики: ") +
				std::string(SDL_GetError()));
	_car = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "Nissan.png"),
				SDL_DestroyTexture);
		if (_car == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить машину: ") +
				std::string(SDL_GetError()));
	_drevo = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "drevo.png"),
				SDL_DestroyTexture);
		if (_drevo == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить дерево: ") +
				std::string(SDL_GetError()));
	_kust = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "kust.png"),
				SDL_DestroyTexture);
		if (_kust == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить куст: ") +
				std::string(SDL_GetError()));
	_flower = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "flower.png"),
				SDL_DestroyTexture);
		if (_flower == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить цветок: ") +
				std::string(SDL_GetError()));
	_znak = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "znak.png"),
				SDL_DestroyTexture);
		if (_znak == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить дорожный знак: ") +
				std::string(SDL_GetError()));
	_bee_main = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "bee.png"),
				SDL_DestroyTexture);
		if (_bee_main == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить главную пчелу: ") +
				std::string(SDL_GetError()));


}


void ExampleWindow::render()
{
	SDL_SetRenderDrawColor(_renderer.get(), 173, 255, 47, 0);
	SDL_RenderClear(_renderer.get());

	//SDL_Rect bee_rect { _bee_x, _bee_y, 256, 256 };
	SDL_Rect sky_rect { 0, 0, 1920, 520 };
	SDL_Rect sun_rect { _sun_x, _sun_y, 128, 128 };
	SDL_Rect cloud1_rect { _cloud1_x, _cloud1_y, 1920, 450 };
	SDL_Rect cloud11_rect {_cloud11_x, _cloud11_y, 1920, 450 };
	SDL_Rect cloud2_rect {_cloud2_x, _cloud2_y, 250, 250 };
	SDL_Rect lug_rect { _lug_x, -_lug_y, 1920, 1150 };
	SDL_Rect lug1_rect { _lug1_x, -_lug1_y, 1920, 1150 };
		SDL_Rect mounts_rect { _mounts_x, _mounts_y, 1920, 400 };
		SDL_Rect mounts_rect1 { _mounts_x1, _mounts_y1, 1920, 400 };
	SDL_Rect road_rect { _road_x, _road_y, 1920, 200 };
	SDL_Rect road1_rect { _road1_x, _road1_y, 1920, 200 };
	SDL_Rect stolbiki_rect11 { _stolbiki_rect11_x, 580, 200, 80 };
	SDL_Rect stolbiki_rect12 { _stolbiki_rect12_x, 580, 200, 80 };
	SDL_Rect stolbiki_rect13 { _stolbiki_rect13_x, 580, 200, 80 };
	SDL_Rect stolbiki_rect14 { _stolbiki_rect14_x, 580, 200, 80 };
	SDL_Rect stolbiki_rect15 { _stolbiki_rect15_x, 580, 200, 80 };
		SDL_Rect stolbiki_rect21 { _stolbiki_rect21_x, 753, 220, 100 };
		SDL_Rect stolbiki_rect22 { _stolbiki_rect22_x, 753, 220, 100 };
		SDL_Rect stolbiki_rect23 { _stolbiki_rect23_x, 753, 220, 100 };
		SDL_Rect stolbiki_rect24 { _stolbiki_rect24_x, 753, 220, 100 };
		SDL_Rect stolbiki_rect25 { _stolbiki_rect25_x, 753, 220, 100 };
	SDL_Rect car_rect { _car_x, _car_y, 500, 300 };
	SDL_Rect drevo_rect { _drevo_x, _drevo_y, 300, 200 };
	SDL_Rect kust_rect { _kust_x, _kust_y, 200, 120 };
	SDL_Rect flower_rect { _flower_x, _flower_y, 100, 100 };
	SDL_Rect znak_rect { _znak_x, _znak_y, 200, 200 };
	SDL_Rect bee_main_rect { _bee_main_x, _bee_main_y, 100, 100 };
	//SDL_RenderCopy(_renderer.get(), _bee.get(), nullptr, &bee_rect);
	SDL_RenderCopy(_renderer.get(), _skying.get(), nullptr, &sky_rect);
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud2_rect);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud1_rect);
	SDL_RenderCopy(_renderer.get(), _cloud11.get(), nullptr, &cloud11_rect);
	SDL_RenderCopy(_renderer.get(), _sun.get(), nullptr, &sun_rect);
	SDL_RenderCopy(_renderer.get(), _lug.get(), nullptr, &lug_rect);
	SDL_RenderCopy(_renderer.get(), _lug1.get(), nullptr, &lug1_rect);
		SDL_RenderCopy(_renderer.get(), _mounts.get(), nullptr, &mounts_rect);
		SDL_RenderCopy(_renderer.get(), _mounts1.get(), nullptr, &mounts_rect1);
	SDL_RenderCopy(_renderer.get(), _drevo.get(), nullptr, &drevo_rect);
	SDL_RenderCopy(_renderer.get(), _kust.get(), nullptr, &kust_rect);
	SDL_RenderCopy(_renderer.get(), _road.get(), nullptr, &road_rect);
	SDL_RenderCopy(_renderer.get(), _road.get(), nullptr, &road1_rect);
	SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect11);
	SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect12);
	SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect13);
	SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect14);
	SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect15);
	SDL_RenderCopy(_renderer.get(), _car.get(), nullptr, &car_rect);
		SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect21);
		SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect22);
		SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect23);
		SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect24);
		SDL_RenderCopy(_renderer.get(), _stolbiki.get(), nullptr, &stolbiki_rect25);
	SDL_RenderCopy(_renderer.get(), _flower.get(), nullptr, &flower_rect);
	SDL_RenderCopy(_renderer.get(), _znak.get(), nullptr, &znak_rect);
	SDL_RenderCopy(_renderer.get(), _bee_main.get(), nullptr, &bee_main_rect);




}

void ExampleWindow::do_logic()
{
	//_bee_x += 6;
	//if (_bee_x >= width())
	//	_bee_x = -256;
	//_bee_y += 8 * sin(_bee_phase);
	//_bee_phase += 0.1;
	_sun_x -= 1;
		if (_sun_x <= 0)
			_sun_x = 1900;

	_mounts_x -= 2;
		if (_mounts_x <= -width())
			_mounts_x = 1900;
	_mounts_x1 -= 2;
		if (_mounts_x1 <= -width())
			_mounts_x1 = 1900;

	_cloud1_x -= 3;
		if (_cloud1_x <= -width())
			_cloud1_x = 1900;
	_cloud11_x -= 3;
		if (_cloud11_x <= -width())
			_cloud11_x = 1900;
	_cloud2_x -= 3;
		if (_cloud2_x <= 0)
			_cloud2_x = 1900;

	_drevo_x -= 3;
		if (_drevo_x <= -width())
			_drevo_x = 2000;

	_stolbiki_rect11_x -= 4;
		if (_stolbiki_rect11_x <= 0)
			_stolbiki_rect11_x = 1700;
	_stolbiki_rect12_x -= 4;
		if (_stolbiki_rect12_x <= 0)
			_stolbiki_rect12_x = 1700;
	_stolbiki_rect13_x -= 4;
		if (_stolbiki_rect13_x <= 0)
			_stolbiki_rect13_x = 1700;
	_stolbiki_rect14_x -= 4;
		if (_stolbiki_rect14_x <= 0)
			_stolbiki_rect14_x = 1700;
	_stolbiki_rect15_x -= 4;
		if (_stolbiki_rect15_x <= 0)
			_stolbiki_rect15_x = 1700;

	_car_x += 1;
		if (_car_x >= width())
			_car_x = -256;
	_road_x -= 5;
		if (_road_x <= -width())
			_road_x = 1900;
	_road1_x -= 5;
		if (_road1_x <= -width())
			_road1_x = 1900;

	_stolbiki_rect21_x -= 6;
		if (_stolbiki_rect21_x <= 0)
			_stolbiki_rect21_x = 1700;
	_stolbiki_rect22_x -= 6;
		if (_stolbiki_rect22_x <= 0)
			_stolbiki_rect22_x = 1700;
	_stolbiki_rect23_x -= 6;
		if (_stolbiki_rect23_x <= 0)
			_stolbiki_rect23_x = 1700;
	_stolbiki_rect24_x -= 6;
		if (_stolbiki_rect24_x <= 0)
			_stolbiki_rect24_x = 1700;
	_stolbiki_rect25_x -= 6;
		if (_stolbiki_rect25_x <= 0)
			_stolbiki_rect25_x = 1700;

	_kust_x -= 7;
		if (_kust_x <= -width())
			_kust_x = 2000;
	_flower_x -= 7;
		if (_flower_x <= -width())
			_flower_x = 2000;
	_znak_x -= 7;
		if (_znak_x <= -width())
			_znak_x = 2000;

	_lug_x -= 3;
		if (_lug_x <= -width())
			_lug_x = 1900;
	_lug1_x -= 3;
		if (_lug1_x <= -width())
			_lug1_x = 1900;
}


void ExampleWindow::handle_keys(const Uint8 *keys)
{
	//if (keys[SDL_SCANCODE_DOWN])
	//	_bee_y += 6;
	//if (keys[SDL_SCANCODE_UP])
	//	_bee_y -= 6;

	if (keys[SDL_SCANCODE_DOWN]){
		if((_bee_main_y + 6 + 200) < height())
		_bee_main_y += 6;
	}
	if (keys[SDL_SCANCODE_UP]){
		if((_bee_main_y - 6 - 100) > 0)
		_bee_main_y -= 6;
	}

	if (keys[SDL_SCANCODE_LEFT]){
		if((_bee_main_x - 6 - 200) > 0)
		_bee_main_x -= 6;
	}

	if (keys[SDL_SCANCODE_RIGHT]){
		if((_bee_main_x + 6 + 300) < width())
		_bee_main_x += 6;
	}

}
