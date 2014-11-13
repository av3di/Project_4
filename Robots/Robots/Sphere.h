#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Geode.h"

class Sphere : public Geode
{
protected:
	int radius;
	int slices;
	int stacks;
	double red;
	double green;
	double blue;
public:
	Sphere(int, int, int, double, double, double);
	~Sphere();
	virtual void render(Matrix4 &c);
};

#endif