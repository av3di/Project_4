#ifndef _NODE_H_
#define _NODE_H_

#include "Matrix4.h"
#include <GL/glut.h>
#include <string>
#include "Vector4.h"

class Node
{
protected:
	double bs_radius; //bounding sphere radius
	Vector3 bounding_sphere; // bounding sphere center point
	double min_y;
	double min_x;
	double min_z;
	double max_y;
	double max_x;
	double max_z;

	std::string name;
	Node* parent;
public:
	Node();
	~Node();
	virtual void draw(Matrix4 &c, Matrix4 &option);
	virtual bool update(Matrix4 &c);
	void setMin(double, double, double); // set min values x, y, z
	void setMax(double, double, double); // set max values x, y, z
};

#endif