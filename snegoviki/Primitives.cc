/*
 * Primitives.cc
 *
 *  Created on: 30 но€б. 2020 г.
 *      Author: work
 */

#include "Primitives.h"
#include <cmath>
#include <GL/gl.h>

static constexpr double Pi = acos(-1.);

void cart2cyl(	double x, double y, double z,
				double &r, double &phi, double &cz)
{
	r = hypot (y, x);
	phi = atan2(y , x);
	cz = z;
}

void cyl2cart(	double r, double phi, double cz,
				double &x, double &y, double &z)
{
	x = r * cos(phi);
	y = r * sin(phi);
	z = cz;
}

void cart2sph(	double x, double y, double z,
				double &r, double &phi, double &theta)
{
	r = sqrt (x*x + y*y + z*z);
	phi = atan2(y,x);
	theta = atan2(hypot(x,y), z);
}

void sph2cart(	double r, double phi, double theta,
				double &x, double &y, double &z)
{
	x = r * sin(theta) * cos(phi);
	y = r * sin(theta) * sin(phi);
	z = r * cos(theta);
}
void draw_prism(int sides)
{
	double phi_step = 2. * Pi / sides;
	for (int side = 0; side < sides; side++){
		double 	phi1 = phi_step * side,
				phi2 = phi_step * (side + 1),
				phin = (phi1+phi2)/2;

		double x1, x2, y1, y2, z1, z2, xn, yn, zn;
		cyl2cart(1., phi1, 0, x1, y1, z1);
		cyl2cart(1., phi2, 1, x2, y2, z2);
		cyl2cart(1., phin, 0, xn, yn, zn);
		glBegin(GL_TRIANGLES);
		{
			glNormal3d(0., 0., 1.);
			glVertex3d(0., 0., 1.);
			glVertex3d(x1, y1, 1.);
			glVertex3d(x2, y2, 1.);
			glNormal3d(0., 0., -1.);
			glVertex3d(0., 0., 0.);
			glVertex3d(x2, y2, 0.);
			glVertex3d(x1, y1, 0.);
		}
		glEnd();
		glBegin(GL_QUADS);
		{
			glNormal3d(xn, yn, zn);
			glVertex3d(x2, y2, 1.);
			glVertex3d(x1, y1, 1.);
			glVertex3d(x1, y1, 0.);
			glVertex3d(x2, y2, 0.);
		}
		glEnd();

	}
}

void draw_cylinder(int sides)
{
	double phi_step = 2. * Pi / sides;
	for (int side = 0; side < sides; side++){
		double 	phi1 = phi_step * side,
				phi2 = phi_step * (side + 1);

		double x1, x2, y1, y2, z1, z2;
		cyl2cart(0.3, phi1, 0, x1, y1, z1);
		cyl2cart(0.3, phi2, 1, x2, y2, z2);
		glBegin(GL_TRIANGLES);
		{
			glNormal3d(0., 0., 1.);
			glVertex3d(0., 0., 1.);
			glVertex3d(x1, y1, 1.);
			glVertex3d(x2, y2, 1.);
			glNormal3d(0., 0., -1.);
			glVertex3d(0., 0., 0.);
			glVertex3d(x2, y2, 0.);
			glVertex3d(x1, y1, 0.);
		}
		glEnd();
		glBegin(GL_QUADS);
		{
			glNormal3d(x1, y1, 0.);
			glVertex3d(x1, y1, 1.);
			glVertex3d(x1, y1, 0.);
			glNormal3d(x2, y2, 0.);
			glVertex3d(x2, y2, 0.);
			glVertex3d(x2, y2, 1.);
		}
		glEnd();

	}
}

void draw_pyramid(int sides)
{
	double phi_step = 2. * Pi / sides;
	for (int side = 0; side < sides; side++){
		double 	phi1 = phi_step * side,
				phi2 = phi_step * (side + 1),
				phin = (phi1+phi2)/2;

		double x1, x2, y1, y2, z1, z2, xn, yn, zn;
		cyl2cart(0.15, phi1, 0, x1, y1, z1);
		cyl2cart(0.15, phi2, 1, x2, y2, z2);
		sph2cart(0.15, phin, Pi/4, xn, yn, zn);
		glBegin(GL_TRIANGLES);
		{
			glNormal3d(xn, yn, zn);
			glVertex3d(0., 0., 1.);
			glVertex3d(x1, y1, 0.);
			glVertex3d(x2, y2, 0.);
			glNormal3d(0., 0., -1.);
			glVertex3d(0., 0., 0.);
			glVertex3d(x2, y2, 0.);
			glVertex3d(x1, y1, 0.);
		}
		glEnd();
	}
}

void draw_cone(int sides)
{
	double phi_step = 2. * Pi / sides;
	for (int side = 0; side < sides; side++){
		double 	phi1 = phi_step * side,
				phi2 = phi_step * (side + 1),
				phin = (phi1+phi2)/2;

		double x1, x2, y1, y2, z1, z2, xn, yn, zn;
		double xn1, xn2, yn1, yn2, zn1, zn2;
		cyl2cart(1., phi1, 0, x1, y1, z1);
		cyl2cart(1., phi2, 1, x2, y2, z2);
		sph2cart(1., phin, Pi/4, xn, yn, zn);
		sph2cart(1., phin, Pi/4, xn1, yn1, zn1);
		sph2cart(1., phin, Pi/4, xn2, yn2, zn2);
		glBegin(GL_TRIANGLES);
		{
			glNormal3d(0., 0., -1.);
			glVertex3d(0., 0., 0.);
			glVertex3d(x2, y2, 0.);
			glVertex3d(x1, y1, 0.);
		}
		glEnd();
		glBegin(GL_QUADS);
		{
			glNormal3d(xn1, yn1, zn1);
			glVertex3d(0., 0., 1.);
			glVertex3d(x1, y1, 0.);
			glNormal3d(xn2, yn2, zn2);
			glVertex3d(x2, y2, 0.);
			glVertex3d(0., 0., 1.);
		}
		glEnd();
	}
}

void draw_sphere(int cols, int rows)
{
	double 	phi_step = 2. * Pi / cols,
			theta_step = 2. * Pi /rows;
	glBegin(GL_QUADS);
	for (int row = 0; row<rows; ++row){
		for(int col = 0; col < cols; ++col){
			double 	phi1 	= phi_step*col,
					phi2 	= phi_step * (col+1),
					theta1 	= theta_step * row,
					theta2 	= theta_step * (row+1),
					phin	= (phi1 + phi2) / 2.,
					thetan	= (theta1 + theta2) / 2.;
			double 	x11, x12, x21, x22,
					y11, y12, y21, y22,
					z11, z12, z21, z22,
					xn, yn, zn;
			sph2cart(0.35, phi1, theta1, x11, y11, z11);
			sph2cart(0.35, phi1, theta2, x12, y12, z12);
			sph2cart(0.35, phi2, theta1, x21, y21, z21);
			sph2cart(0.35, phi2, theta2, x22, y22, z22);
			sph2cart(0.35, phin, thetan, xn, yn, zn);

			glNormal3d(xn, yn, zn);
			glVertex3d(x11, y11, z11);
			glVertex3d(x12, y12, z12);
			glVertex3d(x21, y21, z21);
			glVertex3d(x22, y22, z22);
		}
	}
	glEnd();
}

void draw_sphere_smooth(int cols, int rows) {
	double 	phi_step = 2. * Pi / cols,
			theta_step = 2. * Pi /rows;
	glBegin(GL_QUADS);
	for (int row = 0; row<rows; ++row){
		for(int col = 0; col < cols; ++col){
			double 	phi1 	= phi_step*col,
					phi2 	= phi_step * (col+1),
					theta1 	= theta_step * row,
					theta2 	= theta_step * (row+1);

			double 	x11, x12, x21, x22,
					y11, y12, y21, y22,
					z11, z12, z21, z22,
					xn, yn, zn,
					xn1, yn1, zn1,
					xn2, yn2, zn2,
					xn3, yn3, zn3;

			sph2cart(0.35, phi1, theta1, x11, y11, z11);
			sph2cart(0.35, phi1, theta2, x12, y12, z12);
			sph2cart(0.35, phi2, theta1, x21, y21, z21);
			sph2cart(0.35, phi2, theta2, x22, y22, z22);
			sph2cart(0.35, phi1, theta1, xn, yn, zn);
			sph2cart(0.35, phi1, theta2, xn1, yn1, zn1);
			sph2cart(0.35, phi2, theta1, xn2, yn2, zn2);
			sph2cart(0.35, phi2, theta2, xn3, yn3, zn3);


			glNormal3d(xn, yn, zn);
			glVertex3d(x11, y11, z11);
			glNormal3d(xn1, yn1, zn1);
			glVertex3d(x12, y12, z12);
			glNormal3d(xn2, yn2, zn2);
			glVertex3d(x21, y21, z21);
			glNormal3d(xn3, yn3, zn3);
			glVertex3d(x22, y22, z22);

		}
	}
	glEnd();
}
