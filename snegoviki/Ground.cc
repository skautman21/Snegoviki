
#include "Ground.h"

static const std::vector<Ground::Vertex> s_ground_vertices {
	{  -40.0, -20.0, -1.03 },//0
	{  -40.0, 20.0, -1.03 },//1
	{ 40.0, 20.0, -1.03 },//2
	{ 40.0, -20.0, -1.03 },//3
};

static const std::vector<Ground::Face> s_ground_faces {
	{ 4, 0, 1, 2, 3 },//1
};

static const std::vector<Ground::Color> s_ground_colors {
	{ 1.0f, 1.0f, 1.0f },//1
};

static const std::vector<Ground::Normal> s_ground_normals {
	{  0.0,  0.0,  1.0 },//1
};

static const std::vector<std::vector<Ground::Vertex>> s_ground_tex_coords {
	{ { 0.75, 0.00 }, { 1.00, 0.00 }, { 1.00, 0.50 }, {0.75, 0.50 } },//1
};


Ground::Ground(
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

void Ground::draw()
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

Ground Ground::create_ground()
{
	return Ground(
			s_ground_vertices,
			s_ground_faces,
			s_ground_colors,
			s_ground_normals,
			s_ground_tex_coords);
}
