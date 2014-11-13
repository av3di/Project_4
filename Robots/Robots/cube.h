#ifndef _CUBE_H_
#define _CUBE_H_

#include "Matrix4.h"
#include "Geode.h"


class Cube : public Geode
{
protected:
	int size;
	double red;
	double green;
	double blue;
  public:

    Cube(int, double, double, double);   // Constructor
	virtual void render(Matrix4 &c);
};

#endif

