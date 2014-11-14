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

void Geode::draw(Matrix4 &c, Matrix4 &option)
{
	setModelView(c);
	this->render(c, option);
}

void Geode::setModelView(Matrix4 &c)
{
	glMatrixMode(GL_MODELVIEW);  // make sure we're in Modelview mode
	c.transpose();
	glLoadMatrixd(c.getPointer());
}

void Geode::render(Matrix4 &c, Matrix4 &option)
{

}
