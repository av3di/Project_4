#include "Cube.h"
#include "Matrix4.h"
#include <GL/glut.h>
#include "main.h"

using namespace std;


Cube::Cube(int s, double r, double g, double b) :size(s), red(r), green(g), blue(b)
{
}

void Cube::render(Matrix4 &c)
{
	glColor3d(red, green, blue);
	glutSolidCube(size);
	if (!Globals::b_off)
		update();
}

void Cube::update()
{
	// Find center of bounding sphere
	double midx = (min_x + max_x) / 2.0;
	double midy = (min_y + max_y) / 2.0;
	double midz = (min_z + max_z) / 2.0;

	bounding_sphere.setX(midx);
	bounding_sphere.setY(midy);
	bounding_sphere.setZ(midz);
	bounding_sphere.setW(1);

	// Find radius of bounding sphere

	bs_radius = sqrt(((max_x - midx) * (max_x - midx)) + ((max_y - midy)*(max_y - midy)));
	glColor3d(1, 1, 1);
	glutWireSphere(bs_radius, 10, 10);
}