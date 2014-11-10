#include "Sphere.h"


Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

void Sphere::draw(Matrix4 &c)
{
	double radius = 3;
	int slices = 20;		// subdivisions around Z axis (longitude)
	int stacks = 20;		// subdivisions along Z axis (latitude)
	glutSolidSphere(radius, slices, stacks);
	//cout << "drawing solid sphere" << endl;
}