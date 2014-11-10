#ifndef _NODE_H_
#define _NODE_H_

#include "Matrix4.h"
#include <GL/glut.h>
#include <string>

class Node
{
protected:
	std::string name;
	Node* parent;
public:
	Node();
	~Node();
	virtual void draw(Matrix4 &c);
};

#endif