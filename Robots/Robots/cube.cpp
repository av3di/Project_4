#include "Cube.h"
#include "Matrix4.h"
#include <GL/glut.h>

using namespace std;


Cube::Cube(int s, double r, double g, double b) :size(s), red(r), green(g), blue(b)
{
}

void Cube::render(Matrix4 &c)
{
	glColor3d(red, green, blue);
	glutSolidCube(size);
}