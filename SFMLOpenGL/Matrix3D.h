/// <summary>
/// @author Cathal Redmond
/// </summary>
#ifndef MATRIX3D
#define MATRIX3D

#include "Vector3D.h"

//forward referencing
class Vector3D;

class Matrix3D
{
public:
	Matrix3D();
	Matrix3D(double t_a11, double t_a12, double t_a13,
			 double t_a21, double t_a22, double t_a23,
			 double t_a31, double t_a32, double t_a33);

	Matrix3D(Vector3D t_row1, 
			 Vector3D t_row2, 
		     Vector3D t_row3);


	Vector3D operator * (Vector3D t_vector) const;
	Matrix3D operator + (Matrix3D t_matrix) const;
	Matrix3D operator - (Matrix3D t_matrix) const;
	Matrix3D operator - () const;
	Matrix3D operator * (double t_scalar) const;
	Matrix3D operator * (float t_scalar) const;
	Matrix3D operator * (int t_scalar) const;
	Matrix3D operator * (Matrix3D t_matrix) const;

	bool operator == (Matrix3D t_matrix) const;
	bool operator != (Matrix3D t_matrix) const;

	Vector3D row(int t_rowNumber) const;
	Vector3D column(int t_columnNumber) const;

	Matrix3D transpose() const;
	double determinant() const;
	Matrix3D inverse() const;


	Matrix3D rotation(double t_angle) const;
	Matrix3D rotationX(double t_angle) const;
	Matrix3D rotationY(double t_angle) const;
	Matrix3D rotationZ(double t_angle) const;
	Matrix3D translate(double t_dx, double t_dy) const;
	Matrix3D scale(double t_dx, double t_dy) const;
	Matrix3D scale3D(double t_dx) const;

	std::string toString() const;

	double A11() const;
	double A12() const;
	double A13() const;
	double A21() const;
	double A22() const;
	double A23() const;
	double A31() const;
	double A32() const;
	double A33() const;

private:
	// value for the number in the first row , first column of the matrix
	double m_a11;
	// value for the number in the first row , second column of the matrix
	double m_a12;
	// value for the number in the first row , third column of the matrix
	double m_a13;
	// value for the number in the second row , first column of the matrix
	double m_a21;
	// value for the number in the second row , second column of the matrix
	double m_a22;
	// value for the number in the second row , third column of the matrix
	double m_a23;
	// value for the number in the third row , first column of the matrix
	double m_a31;
	// value for the number in the third row , second column of the matrix
	double m_a32;
	// value for the number in the third row , third column of the matrix
	double m_a33;
};


#endif // !MATRIX3D
