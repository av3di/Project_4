#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Geode.h"

class Sphere : public Geode
{
public:
	Sphere();
	~Sphere();
	virtual void draw(Matrix4 &c);
};

#endif