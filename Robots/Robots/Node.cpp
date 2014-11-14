#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
}


void Node::draw(Matrix4 &c)
{

}

void Node::update()
{
	// Find center of bounding sphere
	double midx = (min_x + max_x) / 2.0;
	double midy = (min_y + max_y) / 2.0;
	double midz = (min_z + max_z) / 2.0;

	bounding_sphere.setX(midx);
	bounding_sphere.setY(midy);
	bounding_sphere.setZ(midz);
	bounding_sphere.setW(1);

	// Find radius of bounding sphere
	
	double diameter = 1.0;
	if (max_x - min_x >= max_y - min_y)
		diameter = max_x - min_x;
	else
		diameter = max_y - min_y;
	//cout << "diameter is:" << diameter << endl;
	//getchar();
	bs_radius = diameter / 2.0;
	
	glColor3d(1, 1, 1);
	if (bs_radius < 1)
		bs_radius = 1;
	
	cout << "radius: " << bs_radius << endl;
	glutWireSphere(bs_radius+ 1, 10, 10);
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