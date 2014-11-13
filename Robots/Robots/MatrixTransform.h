#ifndef _MATRIXTRANSFORM_H_
#define _MATRIXTRANSFORM_H_

#include "Group.h"
#include "Geode.h"
class MatrixTransform : public Group
{
public:
	Matrix4 m;
public:
	MatrixTransform();
	~MatrixTransform();
	Matrix4& getMatrix();
	void getIdentity();
	void translate(double x, double y, double z);
	void MatrixTransform::rotate(double a);
	void walk();
	virtual void draw(Matrix4 &c);
};

#endif

