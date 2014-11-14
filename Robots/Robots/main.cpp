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

