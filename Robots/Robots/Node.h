#include "Matrix4.h"
class Node
{
public:
	Node();
	~Node();
	virtual void draw(Matrix4 c) = 0;
};

