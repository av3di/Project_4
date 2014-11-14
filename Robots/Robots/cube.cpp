#include "Cube.h"
#include "Matrix4.h"
#include <GL/glut.h>
#include "main.h"

using namespace std;


Cube::Cube(int s, double r, double g, double b) :size(s), red(r), green(g), blue(b)
{
}

void Cube::render(Matrix4 &c, Matrix4 &option)
{
	if (update(c, option))
	{
		glColor3d(red, green, blue);
		glutSolidCube(size);
	}
}

bool Cube::update(Matrix4 &c, Matrix4 &option)
{
	// Find center of bounding sphere
	double midx = (min_x + max_x) / 2.0;
	double midy = (min_y + max_y) / 2.0;
	double midz = (min_z + max_z) / 2.0;

	Matrix4 b_s;
	b_s.setCol(3, 1, 1, 1, 1);
	b_s = option * b_s;
	bounding_sphere.setX(b_s.get(3, 0));
	bounding_sphere.setX(b_s.get(3, 1));
	bounding_sphere.setX(b_s.get(3, 2));
	bounding_sphere.setX(b_s.get(3, 3));

	bs_radius = sqrt(((max_x - midx) * (max_x - midx)) + ((max_y - midy)*(max_y - midy)));

	double near_d = Globals::near_normal.dot(Globals::near_point);
	double far_d = Globals::far_normal.dot(Globals::far_point);
	double left_d = Globals::left_normal.dot(Globals::left_point);
	double right_d = Globals::right_normal.dot(Globals::right_point);
	double top_d = Globals::near_normal.dot(Globals::top_point);
	double bottom_d = Globals::far_normal.dot(Globals::bottom_point);

	double near_dist = bounding_sphere.dot(Globals::near_normal) - near_d;
	double far_dist = bounding_sphere.dot(Globals::far_normal) - far_d;
	double left_dist = bounding_sphere.dot(Globals::left_normal) - left_d;
	double right_dist = bounding_sphere.dot(Globals::right_normal) - right_d;
	double top_dist = bounding_sphere.dot(Globals::top_normal) - top_d;
	double bottom_dist = bounding_sphere.dot(Globals::bottom_normal) - bottom_d;

	bool in_view = true;
	if (near_dist > bs_radius)
		in_view = false;
	else if (near_dist < (-1 * bs_radius))
		in_view = true;
	else
		in_view = true;
	if (far_dist > bs_radius)
		in_view = false;
	else if (far_dist < (-1 * bs_radius))
		in_view = true;
	else
		in_view = true;
	if (left_dist > bs_radius)
		in_view = false;
	else if (left_dist < (-1 * bs_radius))
		in_view = true;
	else
		in_view = true;
	if (right_dist > bs_radius)
		in_view = false;
	else if (right_dist < (-1 * bs_radius))
		in_view = true;
	else
		in_view = true;
	if (top_dist > bs_radius)
		in_view = false;
	else if (top_dist < (-1 * bs_radius))
		in_view = true;
	else
		in_view = true;
	if (bottom_dist > bs_radius)
		in_view = false;
	else if (bottom_dist < (-1 * bs_radius))
		in_view = true;
	else
		in_view = true;
	if (in_view && !Globals::b_off)
	{
		glColor3d(1, 1, 1);
		glutWireSphere(bs_radius, 10, 10);
	}
	return in_view;
}