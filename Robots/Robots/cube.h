#ifndef _CUBE_H_
#define _CUBE_H_

#include "Matrix4.h"
#include "Geode.h"


class Cube : public Geode
{
  public:

    Cube();   // Constructor
	virtual void draw(Matrix4 &c);
};

#endif

