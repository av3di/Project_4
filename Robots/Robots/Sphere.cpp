#include "Sphere.h"


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
}