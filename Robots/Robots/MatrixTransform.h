#ifndef _MATRIXTRANSFORM_H_
#define _MATRIXTRANSFORM_H_

#include "Group.h"
class MatrixTransform : public Group
{
protected:
	Matrix4 m;
public:
	MatrixTransform();
	~MatrixTransform();
	virtual void draw(Matrix4 &c);
};

#endif

