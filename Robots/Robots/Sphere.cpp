#include "Sphere.h"
#include "main.h"

Sphere::Sphere(int rad, int sl, int st, double r, double g, double b) : radius(rad), slices(sl), stacks(st), red(r), green(g), blue(b)
{
}


Sphere::~Sphere()
{
}

void Sphere::render(Matrix4 &c)
{	
	glColor3d(red, green, blue);
	glutSolidSphere(radius, slices, stacks);
	if (!Globals::b_off) // if bounding spheres are not off...
		update();
}

void Sphere::update()
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

	glColor3d(1, 1, 1);
	glutWireSphere(radius, 10, 10);
}