#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window
{
protected:
	std::shared_ptr<SDL_Texture> _bee;
	std::shared_ptr<SDL_Texture> _skying;
	std::shared_ptr<SDL_Texture> _sun;
	std::shared_ptr<SDL_Texture> _cloud1;
	std::shared_ptr<SDL_Texture> _cloud11;
	std::shared_ptr<SDL_Texture> _cloud2;
	std::shared_ptr<SDL_Texture> _lug;
	std::shared_ptr<SDL_Texture> _lug1;
	std::shared_ptr<SDL_Texture> _mounts;
	std::shared_ptr<SDL_Texture> _mounts1;
	std::shared_ptr<SDL_Texture> _road;
	std::shared_ptr<SDL_Texture> _stolbiki;
	std::shared_ptr<SDL_Texture> _car;
	std::shared_ptr<SDL_Texture> _drevo;
	std::shared_ptr<SDL_Texture> _kust;
	std::shared_ptr<SDL_Texture> _flower;
	std::shared_ptr<SDL_Texture> _znak;
	std::shared_ptr<SDL_Texture> _bee_main;
	int _bee_x, _bee_y, _car_x, _car_y ,_sun_x, _sun_y,
	_mounts_x, _mounts_y, _mounts_x1, _mounts_y1,_cloud1_x,_cloud1_y,_cloud11_x,_cloud11_y,
	_cloud2_x,_cloud2_y,_road_x,_road_y,_road1_x,_road1_y,
	_lug_x,_lug_y,_lug1_x,_lug1_y,
	_stolbiki_rect11_x,_stolbiki_rect12_x,_stolbiki_rect13_x,_stolbiki_rect14_x,_stolbiki_rect15_x,
	_stolbiki_rect21_x,_stolbiki_rect22_x,_stolbiki_rect23_x,_stolbiki_rect24_x,_stolbiki_rect25_x,
	_drevo_x, _drevo_y,_kust_x, _kust_y,_flower_x, _flower_y,_znak_x, _znak_y,
	_bee_main_x, _bee_main_y;
	double _bee_phase;

public:
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
};


#endif /* EXAMPLEWINDOW_H_ */
