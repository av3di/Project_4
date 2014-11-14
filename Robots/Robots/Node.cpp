#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
}


void Node::draw(Matrix4 &c, Matrix4 &option)
{

}

bool Node::update(Matrix4 &c)
{
	return true;
}

void Node::setMin(double x, double y, double z)
{
	min_x = x;
	min_y = y;
	min_z = z;
}

void Node::setMax(double x, double y, double z)
{
	max_x = x;
	max_y = y;
	max_z = z;
}