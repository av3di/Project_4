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

	extern MatrixTransform *left_leg_init_rotate;
	extern MatrixTransform *left_leg_offset;

	extern 	MatrixTransform *right_leg_init_rotate;
	extern MatrixTransform *right_leg_offset;

	extern MatrixTransform *left_arm_offset;
	extern MatrixTransform *left_arm_init_rotate;

	extern MatrixTransform *right_arm_init_rotate;
	extern MatrixTransform *right_arm_offset;

	extern double viewAngle;
	extern int camZ;
}

#endif