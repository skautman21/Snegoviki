#ifndef RAYCASTINGWINDOW_H_
#define RAYCASTINGWINDOW_H_

#include <memory>

#include "Window.h"
#include "Map.h"
#include "Player.h"
#include "Texture.h"

class RayCastingWindow: public Window
{
public:
	static constexpr double EPSILON = 0.0001;;
protected:
	std::shared_ptr<Map> _map;
	std::shared_ptr<Player> _player;
	std::shared_ptr<Texture> _wall_texture {nullptr};
	void draw_col(int col, int h);
	void draw_textured_col(int col, int h, double tx);
public:
	RayCastingWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~RayCastingWindow() = default;
	RayCastingWindow(const RayCastingWindow &other) = delete;
	RayCastingWindow(RayCastingWindow &&other) = default;

	virtual void render() override;
	virtual void handle_keys(const Uint8*) override;
};

#endif /* RAYCASTINGWINDOW_H_ */
