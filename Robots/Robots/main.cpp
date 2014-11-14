#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glut.h>

#include "Window.h"
#include "Cube.h"
#include "Matrix4.h"
#include "main.h"
#include "vector3.h"
#include "Vector4.h"
#include "Camera.h"
#include "House.h"
#include "Bunny.h"
#include "Dragon.h"
#include "MatrixTransform.h"
#include "Sphere.h"

using namespace std;

namespace Globals
{
	MatrixTransform root;
	Matrix4 identity;

	MatrixTransform *left_leg_offset = new MatrixTransform();
	MatrixTransform *left_leg_init_rotate = new MatrixTransform();

	MatrixTransform *right_leg_init_rotate = new MatrixTransform();
	MatrixTransform *right_leg_offset = new MatrixTransform();

	MatrixTransform *left_arm_offset = new MatrixTransform();
	MatrixTransform *left_arm_init_rotate = new MatrixTransform();

	MatrixTransform *right_arm_init_rotate = new MatrixTransform();
	MatrixTransform *right_arm_offset = new MatrixTransform();

	Vector3 near_normal;
	Vector3 near_point;
	Vector3 far_normal;
	Vector3 far_point;
	Vector3 right_normal;
	Vector3 right_point;
	Vector3 left_normal;
	Vector3 left_point;
	Vector3 top_normal;
	Vector3 top_point;
	Vector3 bottom_normal;
	Vector3 bottom_point;

	bool b_off = true; // bounding spheres off
	double viewAngle = 60.0;
	int camZ = -20;
};

int main(int argc, char *argv[])
{
	float specular[]  = {1.0, 1.0, 1.0, 1.0};
	float shininess[] = {100.0};
	float position[]  = {0.0, 1.75, 1.0, 0.0};	// lightsource position
  // 0, 10, 1, 0
	glutInit(&argc, argv);      	      	      // initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   // open an OpenGL context with double buffering, RGB colors, and depth buffering
	glutInitWindowSize(Window::width, Window::height);      // set initial window size
	glutCreateWindow("OpenGL Cube");    	      // open window and set window title

	glEnable(GL_DEPTH_TEST);            	      // enable depth buffering
	glClear(GL_DEPTH_BUFFER_BIT);       	      // clear depth buffer
	glClearColor(0.0, 0.0, 0.0, 0.0);   	      // set clear color to black
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  // set polygon drawing mode to fill front and back of each polygon
	glDisable(GL_CULL_FACE);     // disable backface culling to render both sides of polygons
	glShadeModel(GL_SMOOTH);             	      // set shading to smooth
	glMatrixMode(GL_PROJECTION); 
  
	// Generate material properties:
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
  
	// Generate light source:
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
  
	// Install callback functions:
	glutDisplayFunc(Window::displayCallback);
	glutReshapeFunc(Window::reshapeCallback);
	glutIdleFunc(Window::idleCallback);

	// View Frustum Calculations from Lighthouse3D site
	// find d and p and up
	Vector3 d;
	Vector3 p;
	Vector3 up;
	d.setX(0); d.setY(0); d.setZ(0); // Look at point
	p.setX(0); p.setY(0); p.setZ(-20); // Camera position
	up.setX(0); up.setY(1); up.setZ(0); // Up vector


	// Calculate X Y Z axis
	Vector3 X;
	Vector3 Y;
	Vector3 Z;
	Z = p - d;
	X = up.cross(Z);
	X.normalize();
	Y = Z.cross(X);

	// Find height and width of far plane of view frustum
	double Hfar = 0.0;
	double Wfar = 0.0;

	double farDist = 25; // distance of far plane from camera

	double radians = ((Globals::viewAngle / 2.0) * M_PI) / 180.0;
	Hfar = (tan(radians) * farDist);
	Wfar = Hfar * (Window::width / Window::height);

	double nearDist = 15.0; // Distance to near plane from Camera

	// Find height and width of near plane
	double Hnear = (tan(radians) * nearDist);
	double Wnear = Hnear * (Window::width / Window::height);

	// Find center point of near and far planes
	Z.scale(nearDist);
	Vector3 nc = p - Z;
	Z = p - d; // Reset Z
	Vector3 fc;
	Z.scale(farDist);
	fc = p - Z;
	Z = p - d; // Reset Z


	// Compute 4 corners of the frustum on near plane
	Y.scale(Hnear);
	X.scale(Wnear);

	Vector3 ntl = nc + Y - X;
	Vector3 ntr = nc + Y + X;
	Vector3 nbl = nc - Y - X;
	Vector3 nbr = nc - Y + X;

	// Reset X Y Z 
	Z = p - d;
	X = up.cross(Z);
	X.normalize();
	Y = Z.cross(X);

	// Find 4 corners of far plane
	Y.scale(Hfar);
	X.scale(Wfar);
	Vector3 ftl = fc + Y - X;
	Vector3 ftr = fc + Y + X;
	Vector3 fbl = fc - Y - X;
	Vector3 fbr = fc - Y + X;


	// Find points and normals for all planes
	// Reset X Y Z 
	Z = p - d;
	X = up.cross(Z);
	X.normalize();
	Y = Z.cross(X);
	// Find points and normals for near and far plane

	Globals::near_normal.setX(Z.getX() * -1); Globals::near_normal.setY(Z.getY()* -1); Globals::near_normal.setZ(Z.getZ()* -1);
	Globals::near_point.setX(nc.getX()); Globals::near_point.setY(nc.getY()); Globals::near_point.setZ(nc.getZ());


	Globals::far_normal.setX(Z.getX()); Globals::far_normal.setY(Z.getY()); Globals::far_normal.setZ(Z.getZ());
	Globals::far_point.setX(fc.getX()); Globals::far_point.setY(fc.getY()); Globals::far_point.setZ(fc.getZ());

	// Find points and normals for right and left plane


	X.scale(Wnear);
	using namespace Globals;
	right_normal = nc + X;
	right_normal = right_normal - p;
	right_normal.normalize();
	right_normal = Y.cross(right_normal);
	right_point = nc + X;


	left_normal = nc - X;
	left_normal = left_normal - p;
	left_normal.normalize();
	left_normal = left_normal.cross(Y);
	left_point = nc - X;

	// Find points and normals for top and bottom plane
	// Reset X Z 
	Z = p - d;
	X = up.cross(Z);
	X.normalize();

	Y.scale(Hnear);


	top_normal = nc + Y;
	top_normal = top_normal - p;
	top_normal.normalize();
	top_normal = top_normal.cross(X);
	top_point = nc + Y;


	bottom_normal = nc - Y;
	bottom_normal = bottom_normal - p;
	bottom_normal.normalize();
	bottom_normal = X.cross(bottom_normal);
	bottom_point = nc - Y;


	// Prepare Robot
	Globals::identity.identity();

	MatrixTransform *b4_head = new MatrixTransform();
	b4_head->getIdentity();
	b4_head->translate(0, 2.5, 0);


	Globals::left_arm_offset->getIdentity();
	Globals::left_arm_offset->translate(2, 1, 0);

	MatrixTransform *left_arm_init_pivot = new MatrixTransform();
	left_arm_init_pivot->translate(0.0, -1.0, 0.0);
	Globals::left_arm_init_rotate->getIdentity();
	Globals::left_arm_init_rotate->rotate(-45);


	Globals::right_arm_offset->getIdentity();
	Globals::right_arm_offset->translate(-2, 1, 0);

	MatrixTransform *right_arm_init_pivot = new MatrixTransform();
	right_arm_init_pivot->translate(0.0, -1.0, 0.0);
	Globals::right_arm_init_rotate->getIdentity();
	Globals::right_arm_init_rotate->rotate(45);

	
	Globals::left_leg_offset->getIdentity();
	Globals::left_leg_offset->translate(-1.0, -1.5, 0);
	MatrixTransform *left_leg_init_pivot = new MatrixTransform();
	left_leg_init_pivot->translate(0.0, -0.5, 0.0);

	Globals::left_leg_init_rotate->getIdentity();
	Globals::left_leg_init_rotate->rotate(-45);


	Globals::right_leg_offset->getIdentity();
	Globals::right_leg_offset->translate(1.0, -1.5, 0);
	MatrixTransform *right_leg_init_pivot = new MatrixTransform();
	right_leg_init_pivot->translate(0.0, -0.5, 0.0);

	Globals::right_leg_init_rotate->getIdentity();
	Globals::right_leg_init_rotate->rotate(45);

	//add head
	Cube *head = new Cube(2, 1.0, 0.55, 0.0);
	head->setMax(1, 1, 1);
	head->setMin(-1, -1, -1);
	Globals::root.addChild(b4_head);
	b4_head->addChild(head);

	// add torso
	Cube *torso = new Cube(3, 0.89, 0.96, 1);
	torso->setMin(-1.5, -1.5, -1.5);
	torso->setMax(1.5, 1.5, 1.5);
	Globals::root.addChild(torso);
	
	// add right arm
	Sphere *right_arm = new Sphere(1.0, 20, 20, 0, 0.50, 0.51);
	right_arm->setMin(-1, -1, -1);
	right_arm->setMax(1, 1, 1);
	Globals::root.addChild(left_arm_init_pivot);
	left_arm_init_pivot->addChild(Globals::left_arm_init_rotate);
	Globals::left_arm_init_rotate->addChild(Globals::left_arm_offset);
	Globals::left_arm_offset->addChild(right_arm);
	
	//add left arm
	Sphere *left_arm = new Sphere(1.0, 20, 20, 0, 0.50, 0.51);
	left_arm->setMax(1, 1, 1);
	left_arm->setMin(-1, -1, -1);
	Globals::root.addChild(right_arm_init_pivot);
	right_arm_init_pivot->addChild(Globals::right_arm_init_rotate);
	Globals::right_arm_init_rotate->addChild(Globals::right_arm_offset);
	Globals::right_arm_offset->addChild(left_arm);

	// add left leg
	Cube *left_leg = new Cube(1.0, 1, 0.0, 0.0);
	left_leg->setMax(0.5, 0.5, 0.5);
	left_leg->setMin(-0.5, -0.5, -0.5);
	Globals::root.addChild(left_leg_init_pivot);
	left_leg_init_pivot->addChild(Globals::left_leg_init_rotate);
	Globals::left_leg_init_rotate->addChild(Globals::left_leg_offset);
	Globals::left_leg_offset->addChild(left_leg);

	// add right leg
	Cube *right_leg = new Cube(1.0, 1, 0.0, 0.0);
	right_leg->setMax(0.5, 0.5, 0.5);
	right_leg->setMin(-0.5, -0.5, -0.5);
	Globals::root.addChild(right_leg_init_pivot); 
	right_leg_init_pivot->addChild(Globals::right_leg_init_rotate);
	Globals::right_leg_init_rotate->addChild(Globals::right_leg_offset);
	Globals::right_leg_offset->addChild(right_leg);
	
	// Process the keys pressed
	glutKeyboardFunc(Window::processNormalKeys);
	glutSpecialFunc(Window::processSpecialKeys);

	glutMainLoop();
}

