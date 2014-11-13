#ifndef _MAIN_H_
#define _MAIN_H_

#include "Cube.h"
#include "Camera.h"
#include "House.h"
#include "Bunny.h"
#include "Dragon.h"
#include "MatrixTransform.h"
#include "Sphere.h"

namespace Globals
{
	extern MatrixTransform root;
	extern Matrix4 identity;

	extern double viewAngle;
	extern int camZ;
}

#endif