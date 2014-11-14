#ifndef _GEODE_H_
#define _GEODE_H_

#include "Node.h"
class Geode : public Node
{
protected:
	Matrix4 model2world;

public:
	Geode();
	~Geode();
	Matrix4& getMatrix();
	void setModelView(Matrix4 &);
	void draw(Matrix4 &c, Matrix4 &option);
	virtual void render(Matrix4 &c, Matrix4 &option);
};

#endif
