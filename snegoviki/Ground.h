/*
 * Ground.h
 *
 *  Created on: 16 дек. 2020 г.
 *      Author: Sergey
 */

#ifndef GROUND_H_
#define GROUND_H_

#include <vector>
#include <GL/gl.h>

class Ground
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
	Ground(
			const std::vector<Vertex> &vertices,
			const std::vector<Face> &faces,
			const std::vector<Color> &colors,
			const std::vector<Normal> &normals,
			const std::vector<std::vector<Vertex>> tex_coords);
	virtual ~Ground() = default;

	void draw();

	static Ground create_ground();
};

#endif /* GROUND_H_ */
