#include "Geode.h"


Geode::Geode()
{
	model2world.identity();
}


Geode::~Geode()
{
}

Matrix4& Geode::getMatrix()
{
	return model2world;
}

void Geode::draw(Matrix4 &c)
{
	//setModelView(c);
	//this->render(c);
}

void Geode::setModelView(Matrix4 &c)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);  // make sure we're in Modelview mode

	glEnable(GL_LIGHTING);
	c.transpose();
	glLoadMatrixd(c.getPointer());
}

void Geode::render(Matrix4 &c)
{

}
