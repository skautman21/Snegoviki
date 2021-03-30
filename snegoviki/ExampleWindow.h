/*
 * ExampleWindow.h
 *
 *  Created on: 16 но€б. 2020 г.
 *      Author: unyuu
 */
#pragma once
#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "SimpleModel.h"
#include "Ground.h"
#include "Texture.h"

class ExampleWindow: public Window
{
protected:
	double _angle { 0. };
	double _camera_z { 0. };
	double z1 { -0.7 };
	double z2 { -0.05 };
	double z3 { 0.6 };
	double z_carrot { 0.65 };

	SimpleModel _cube = SimpleModel::create_cube();
	Texture _crate_texture;
	Texture _snowman_texture;
	Texture _tree_texture;
	Texture _carrot_texture;
	Ground _ground = Ground::create_ground();

public:
	ExampleWindow(	int width = DEFAULT_WIDTH,
					int height = DEFAULT_HEIGHT	);
	virtual ~ExampleWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic() override;
};

#endif /* EXAMPLEWINDOW_H_ */
