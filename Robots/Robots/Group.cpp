#include "Group.h"


Group::Group()
{
}


Group::~Group()
{
}

void Group::addChild(Node &tba)
{
	children.push_back(&tba);
}

void Group::removeChild()
{
	if (!children.empty())
	{
		children.pop_front();
	}
}

void Group::draw(Matrix4 &c)
{
	Node *child;

	for (std::list<Node*>::iterator it = children.begin(); it != children.end(); it++)
	{
		child = *it; 
		child->draw(c);
	}
}