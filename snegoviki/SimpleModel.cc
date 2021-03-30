/*
 * SimpleModel.cc
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: unyuu
 */

#include "SimpleModel.h"

static const std::vector<SimpleModel::Vertex> s_cube_vertices {
	{  1.0,  1.0,  1.0 },//0
	{  1.0, -1.0,  1.0 },//1
	{ -2.0, -1.0,  1.0 },//2
	{ -2.0,  1.0,  1.0 },//3
	{  1.0,  1.0, -1.0 },//4
	{  1.0, -1.0, -1.0 },//5
	{ -2.0, -1.0, -1.0 },//6
	{ -2.0,  1.0, -1.0 },//7
	//крыша
	{ 1.0,  0.0, 2.0 },//8
	{ -2.0,  0.0, 2.0 },//9
	//труба
	{ -1.0,  0.5, 1.0 },//10
	{ -1.0,  0.75, 1.0 },//11
	{ -1.25,  0.75, 1.0 },//12
	{ -1.25,  0.5, 1.0 },//13
	{ -1.0,  0.5, 2.5 },//14
	{ -1.0,  0.75, 2.5 },//15
	{ -1.25,  0.75, 2.5 },//16
	{ -1.25,  0.5, 2.5 },//17

};

static const std::vector<SimpleModel::Face> s_cube_faces {
	{ 4, 1, 0, 4, 5 },//1
	{ 4, 3, 2, 6, 7 },//2
	{ 4, 2, 3, 0, 1 },//3
	{ 4, 7, 6, 5, 4 },//4
	{ 4, 0, 3, 7, 4 },//5
	{ 4, 2, 1, 5, 6 },//6
	//крыша
	{ 3, 1, 8, 0 },//7
	{ 3, 2, 9, 3 },//8
	{ 4, 0, 8, 9, 3 },//9
	{ 4, 1, 8, 9, 2 },//10
	//труба
	{ 4, 10, 11, 15, 14 },//11
	{ 4, 12, 13, 17, 16 },//12
	{ 4, 11, 12, 16, 15 },//13
	{ 4, 10, 13, 17, 14 },//14
	{ 4, 14, 15, 16, 17 },//15

};

static const std::vector<SimpleModel::Color> s_cube_colors {
	{ 1.0f, 1.0f, 1.0f },//1
	{ 1.0f, 1.0f, 1.0f },//2
	{ 1.0f, 1.0f, 1.0f },//3
	{ 1.0f, 1.0f, 1.0f },//4
	{ 1.0f, 1.0f, 1.0f },//5
	{ 1.0f, 1.0f, 1.0f },//6
	//крыша
	{ 1.0f, 1.0f, 1.0f },//7
	{ 1.0f, 1.0f, 1.0f },//8
	{ 1.0f, 1.0f, 1.0f },//9
	{ 1.0f, 1.0f, 1.0f },//10
	//труба
	{ 1.0f, 1.0f, 1.0f },//11
	{ 1.0f, 1.0f, 1.0f },//12
	{ 1.0f, 1.0f, 1.0f },//13
	{ 1.0f, 1.0f, 1.0f },//14
	{ 1.0f, 1.0f, 1.0f },//15
};

static const std::vector<SimpleModel::Normal> s_cube_normals {
	{  1.0,  0.0,  0.0 },//1
	{ -1.0,  0.0,  0.0 },//2
	{  0.0,  0.0,  1.0 },//3
	{  0.0,  0.0, -1.0 },//4
	{  0.0,  1.0,  0.0 },//5
	{  0.0, -1.0,  0.0 },//6
	//крыша
	{  1.0,  0.0,  0.0 },//7
	{  -1.0, 0.0,  0.0 },//8
	{  0.0,  1.0,  1.0 },//9
	{  0.0, -1.0,  1.0 },//10
	//труба
	{  1.0,  0.0,  0.0 },//11
	{  -1.0, 0.0,  0.0 },//12
	{  0.0,  1.0,  1.0 },//13
	{  0.0, -1.0,  1.0 },//14
	{  0.0, 0.0,  1.0 },//15
};

static const std::vector<std::vector<SimpleModel::Vertex>> s_cube_tex_coords {
	{ { 0.00, 0.00 }, { 0.25, 0.00 }, { 0.25, 0.50 }, {0.00, 0.50 } },//1
	{ { 0.00, 0.50 }, { 0.25, 0.50 }, { 0.25, 1.00 }, {0.00, 1.00 } },//2
	{ { 0.00, 0.50 }, { 0.25, 0.50 }, { 0.25, 1.00 }, {0.00, 1.00 } },//3
	{ { 0.00, 0.50 }, { 0.25, 0.50 }, { 0.25, 1.00 }, {0.00, 1.00 } },//4
	{ { 0.25, 0.00 }, { 0.75, 0.00 }, { 0.75, 0.50 }, {0.25, 0.50 } },//5
	{ { 0.25, 0.00 }, { 0.75, 0.00 }, { 0.75, 0.50 }, {0.25, 0.50 } },//6
	//крыша
	{ { 0.00, 1.00 }, { 0.125, 0.50 }, { 0.25, 1.00 } },//7
	{ { 0.00, 1.00 }, { 0.125, 0.50 }, { 0.25, 1.00 } },//8
	{ { 0.25, 0.50 }, { 0.50, 0.50 }, { 0.50, 1.00 }, {0.25, 1.00 } },//9
	{ { 0.25, 0.50 }, { 0.50, 0.50 }, { 0.50, 1.00 }, {0.25, 1.00 } },//10
	//труба
	{ { 0.25, 0.50 }, { 0.50, 0.50 }, { 0.50, 1.00 }, {0.25, 1.00 } },//11
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, {0.50, 1.00 } },//12
	{ { 0.25, 0.50 }, { 0.50, 0.50 }, { 0.50, 1.00 }, {0.25, 1.00 } },//13
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, {0.50, 1.00 } },//14
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, {0.50, 1.00 } },//15
};


SimpleModel::SimpleModel(
		const std::vector<Vertex> &vertices,
		const std::vector<Face> &faces,
		const std::vector<Color> &colors,
		const std::vector<Normal> &normals,
		const std::vector<std::vector<Vertex> > tex_coords)
: _vertices(vertices),
  _faces(faces),
  _colors(colors),
  _normals(normals),
  _tex_coords(tex_coords)
{
}

void SimpleModel::draw()
{
	for (unsigned face_idx = 0; face_idx < _faces.size(); ++face_idx) {
		int vertices = _faces[face_idx][0];

		if (vertices == 3) glBegin(GL_TRIANGLES);
		else if (vertices == 4) glBegin(GL_QUADS);
		else glBegin(GL_POLYGON);

		glColor3fv(&_colors[face_idx][0]);
		glNormal3dv(&_normals[face_idx][0]);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &_colors[face_idx][0]);

		for (int i = 0; i < vertices; ++i) {
			glTexCoord2dv(&_tex_coords[face_idx][i][0]);
			glVertex3dv(&_vertices[_faces[face_idx][i + 1]][0]);
		}

		glEnd();
	}
}

SimpleModel SimpleModel::create_cube()
{
	return SimpleModel(
			s_cube_vertices,
			s_cube_faces,
			s_cube_colors,
			s_cube_normals,
			s_cube_tex_coords);
}
