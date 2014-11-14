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

	extern Vector3 near_normal;
	extern Vector3 near_point;
	extern Vector3 far_normal;
	extern Vector3 far_point;
	extern Vector3 right_normal;
	extern Vector3 right_point;
	extern Vector3 left_normal;
	extern Vector3 left_point;
	extern Vector3 top_normal;
	extern Vector3 top_point;
	extern Vector3 bottom_normal;
	extern Vector3 bottom_point;

	extern bool b_off; // bounding spheres off

	extern double viewAngle;
	extern int camZ;
}

#endif