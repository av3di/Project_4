#include <stdio.h>
#include <iostream>
#include <GL/glut.h>

#include "Window.h"
#include "Cube.h"
#include "Matrix4.h"
#include "main.h"
#include "Camera.h"
#include "House.h"

using namespace std;
using namespace Globals;

int Window::width  = 512;   // set window width in pixels here
int Window::height = 512;   // set window height in pixels here

int Window::fkey = 1;  // If 1, show cube, 2->show 1st cam, 3->show 2nd cam


//----------------------------------------------------------------------------
// Callback method called when system is idle.
void Window::idleCallback()
{
	//Globals::cube.spin(0.1);   // rotate cube; if it spins too fast try smaller values and vice versa
	displayCallback();         // call display routine to show the cube
}

//----------------------------------------------------------------------------

void Window::processSpecialKeys(int key, int x, int y)
{/*
	glMatrixMode(GL_MODELVIEW);  // make sure we're in Modelview mode
	switch (key)
	{
	case GLUT_KEY_F1:
		Window::fkey = 1;
		break;
	}*/
}

// Callback method called by GLUT when graphics window is resized by the user
void Window::reshapeCallback(int w, int h)
{
  cerr << "Window::reshapeCallback called" << endl;
  width = w;
  height = h;
  glViewport(0, 0, w, h);  // set new viewport size
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(Globals::viewAngle, double(width)/(double)height, 1.0, 1000.0); // set perspective projection viewing frustum
  glTranslatef(0, 0, Globals::camZ);    // move camera back 20 units so that it looks at the origin (or else it's in the origin)
  glMatrixMode(GL_MODELVIEW);
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when window readraw is necessary or when glutPostRedisplay() was called.
void Window::displayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Globals::root.draw(Globals::identity);

	glutSwapBuffers();
}

void Window::processNormalKeys(unsigned char key, int x, int y){
	/*Model *currentM = &Globals::hop;
	if (fkey == 1)
		currentM = &Globals::hop;
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 't':
		currentM->changeCounter();
		break;
	case 'x':
		currentM->translate(-1.0, 0.0, 0.0);
		break;
	}*/
}