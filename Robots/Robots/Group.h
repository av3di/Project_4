#ifndef _GROUP_H_
#define _GROUP_H_

#include "Node.h"
#include <list>

class Group : public Node
{
protected:
	std::list<Node*> children;

public:
	Group();
	~Group();
	void addChild(Node *tba);
	void removeChild();
	virtual void draw(Matrix4 &c, Matrix4 &option);
};

#endif
