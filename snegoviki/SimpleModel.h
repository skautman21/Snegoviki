/*
 * SimpleModel.h
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: unyuu
 */

#ifndef SIMPLEMODEL_H_
#define SIMPLEMODEL_H_

#include <vector>
#include <GL/gl.h>

class SimpleModel
{
public:
	using Vertex = std::vector<GLdouble>;
	using Normal = std::vector<GLdouble>;
	using Color = std::vector<GLfloat>;
	// [0] - количество вершин, остальное - индексы
	using Face = std::vector<int>;

protected:
	std::vector<Vertex> _vertices;
	std::vector<Face> _faces;
	std::vector<Color> _colors;
	std::vector<Normal> _normals;
	std::vector<std::vector<Vertex>> _tex_coords;
public:
	SimpleModel(
			const std::vector<Vertex> &vertices,
			const std::vector<Face> &faces,
			const std::vector<Color> &colors,
			const std::vector<Normal> &normals,
			const std::vector<std::vector<Vertex>> tex_coords);
	virtual ~SimpleModel() = default;

	void draw();

	static SimpleModel create_cube();
};

#endif /* SIMPLEMODEL_H_ */
