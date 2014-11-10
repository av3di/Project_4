#include "MatrixTransform.h"


MatrixTransform::MatrixTransform()
{
	m.identity();
}


MatrixTransform::~MatrixTransform()
{
}

void MatrixTransform::draw(Matrix4 &c)
{
	Matrix4 c_new = c * m;
	Group::draw(c_new);
}
