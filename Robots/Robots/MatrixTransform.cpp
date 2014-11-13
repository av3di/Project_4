#include "MatrixTransform.h"


MatrixTransform::MatrixTransform()
{
	m.identity();
}


MatrixTransform::~MatrixTransform()
{
}

Matrix4& MatrixTransform::getMatrix()
{
	return m;
}

void MatrixTransform::translate(double x, double y, double z)
{
	Matrix4 translation;
	translation.makeTranslate(x, y, z);
	m = translation * m;
}


void MatrixTransform::draw(Matrix4 &c)
{
	Matrix4 c_new = c * m;
	Group::draw(c_new);
}

void MatrixTransform::rotate(double a)
{
	Matrix4 rotation;
	rotation.makeRotateX(a);
	m = rotation * m;
}

void MatrixTransform::getIdentity()
{
	m.identity();
}
