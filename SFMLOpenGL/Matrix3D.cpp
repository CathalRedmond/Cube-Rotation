/// <summary>
/// @author Cathal Redmond
/// </summary>
#include "Matrix3D.h"


/// <summary>
/// @brief basic constructor for the matrix
/// </summary>
Matrix3D::Matrix3D()
{
	m_a11 = 0;
	m_a12 = 0;
	m_a13 = 0;
	m_a21 = 0;
	m_a22 = 0;
	m_a23 = 0;
	m_a31 = 0;
	m_a32 = 0;
	m_a33 = 0;
}

/// <summary>
/// @brief overloaded construcor for the matrix
/// allows specific values for the matrix to be declared
/// </summary>
/// <param name="t_m_a11">row 1, column 1 value</param>
/// <param name="t_m_a12">row 1, column 2 value</param>
/// <param name="t_m_a13">row 1, column 3 value</param>
/// <param name="t_m_a21">row 2, column 1 value</param>
/// <param name="t_m_a22">row 2, column 2 value</param>
/// <param name="t_m_a23">row 2, column 3 value</param>
/// <param name="t_m_a31">row 3, column 1 value</param>
/// <param name="t_m_a32">row 3, column 2 value</param>
/// <param name="t_m_a33">row 3, column 3 value</param>
Matrix3D::Matrix3D(double t_m_a11, double t_m_a12, double t_m_a13, 
				   double t_m_a21, double t_m_a22, double t_m_a23, 
				   double t_m_a31, double t_m_a32, double t_m_a33)
{
	m_a11 = t_m_a11;
	m_a12 = t_m_a12;
	m_a13 = t_m_a13;
	m_a21 = t_m_a21;
	m_a22 = t_m_a22;
	m_a23 = t_m_a23;
	m_a31 = t_m_a31;
	m_a32 = t_m_a32;
	m_a33 = t_m_a33;
}


/// <summary>
/// @brief overloaded constructor for the matrix using 3 vectors for each of the row
/// </summary>
/// <param name="t_row1">vector representing first row</param>
/// <param name="t_row2">vector representing second row</param>
/// <param name="t_row3">vector representing third row</param>
Matrix3D::Matrix3D(Vector3D t_row1, 
		           Vector3D t_row2, 
				   Vector3D t_row3)
{
	m_a11 = t_row1.X();
	m_a12 = t_row1.Y();
	m_a13 = t_row1.Z();
	m_a21 = t_row2.X();
	m_a22 = t_row2.Y();
	m_a23 = t_row2.Z();
	m_a31 = t_row3.X();
	m_a32 = t_row3.Y();
	m_a33 = t_row3.Z();
}



/// <summary>
/// @brief overloaded operator * that returns the product of a matrix by a vector (matrix * vector)
/// </summary>
/// <param name="t_vector">vector to be multiplied</param>
/// <returns>product of the matrix and the vector</returns>
Vector3D Matrix3D::operator*(Vector3D t_vector) const
{
	return Vector3D((m_a11 * t_vector.X()) + (m_a12  *t_vector.Y()) + (m_a13 * t_vector.Z()),
					(m_a21 * t_vector.X()) + (m_a22  *t_vector.Y()) + (m_a23 * t_vector.Z()),
					(m_a31 * t_vector.X()) + (m_a32  *t_vector.Y()) + (m_a33 * t_vector.Z()));
}

/// <summary>
/// @brief overloaded operator + that returns the sum of two matrices
/// </summary>
/// <param name="t_matrix">second matrix</param>
/// <returns>sum of two matrices</returns>
Matrix3D Matrix3D::operator+(Matrix3D t_matrix) const
{
	return Matrix3D(m_a11 + t_matrix.m_a11, m_a12 + t_matrix.m_a12, m_a13 + t_matrix.m_a13,
					m_a21 + t_matrix.m_a21, m_a22 + t_matrix.m_a22, m_a23 + t_matrix.m_a23,
					m_a31 + t_matrix.m_a31, m_a32 + t_matrix.m_a32, m_a33 + t_matrix.m_a33);
}

/// <summary>
/// @breif overloaded operator - that returns the difference of two matrices
/// </summary>
/// <param name="t_matrix">second matrix</param>
/// <returns>difference of two matrices</returns>
Matrix3D Matrix3D::operator-(Matrix3D t_matrix) const
{
	return Matrix3D(m_a11 - t_matrix.m_a11, m_a12 - t_matrix.m_a12, m_a13 - t_matrix.m_a13,
					m_a21 - t_matrix.m_a21, m_a22 - t_matrix.m_a22, m_a23 - t_matrix.m_a23,
					m_a31 - t_matrix.m_a31, m_a32 - t_matrix.m_a32, m_a33 - t_matrix.m_a33);
}

/// <summary>
/// @brief operator - that returns the negative of a matrix
/// retuns matrix * -1
/// </summary>
/// <returns>negated matrix</returns>
Matrix3D Matrix3D::operator-() const
{
	return Matrix3D(-m_a11,-m_a12,-m_a13,
					-m_a21,-m_a22,-m_a23,
					-m_a31,-m_a32,-m_a33);
}

/// <summary>
/// @breif overloaded operator * that returns the product of a matrix by a double
/// </summary>
/// <param name="t_scalar">double value to multiply matrix by</param>
/// <returns>product of the double and the matrix</returns>
Matrix3D Matrix3D::operator*(double t_scalar) const
{
	return Matrix3D(m_a11 * t_scalar, m_a12 * t_scalar, m_a13 * t_scalar,
					m_a21 * t_scalar, m_a22 * t_scalar, m_a23 * t_scalar,
					m_a31 * t_scalar, m_a32 * t_scalar, m_a33 * t_scalar);
}

/// <summary>
/// @breif overloaded operator * that returns the product of a matrix by a float
/// </summary>
/// <param name="t_scalar">float value to multiply matrix by</param>
/// <returns>product of the float and the matrix</returns>
Matrix3D Matrix3D::operator*(float t_scalar) const
{
	return Matrix3D(m_a11 * t_scalar, m_a12 * t_scalar, m_a13 * t_scalar,
					m_a21 * t_scalar, m_a22 * t_scalar, m_a23 * t_scalar,
					m_a31 * t_scalar, m_a32 * t_scalar, m_a33 * t_scalar);
}

/// <summary>
/// @breif overloaded operator * that returns the product of a matrix by a int
/// </summary>
/// <param name="t_scalar">int value to multiply matrix by</param>
/// <returns>product of the int and the matrix</returns>
Matrix3D Matrix3D::operator*(int t_scalar) const
{
	return Matrix3D(m_a11 * t_scalar, m_a12 * t_scalar, m_a13 * t_scalar,
					m_a21 * t_scalar, m_a22 * t_scalar, m_a23 * t_scalar,
					m_a31 * t_scalar, m_a32 * t_scalar, m_a33 * t_scalar);
}

/// <summary>
/// @brief overloaded operator * that returns the product of two matrices
/// </summary>
/// <param name="t_matrix">second matrix</param>
/// <returns>product of the two matrices</returns>
Matrix3D Matrix3D::operator*(Matrix3D t_matrix) const
{
	return Matrix3D(row(0) * t_matrix.column(0), row(0) * t_matrix.column(1), row(0) * t_matrix.column(2),
					row(1) * t_matrix.column(0), row(1) * t_matrix.column(1), row(1) * t_matrix.column(2),
					row(2) * t_matrix.column(0), row(2) * t_matrix.column(1), row(2) * t_matrix.column(2));
}

/// <summary>
/// @brief overloaded operator == that checks if two matrices are equal
/// </summary>
/// <param name="t_matrix">second matrix</param>
/// <returns>true if the matrices are equal , false if they aren't equal</returns>
bool Matrix3D::operator==(Matrix3D t_matrix) const
{
	if (m_a11 == t_matrix.m_a11 && m_a12 == t_matrix.m_a12 && m_a13 == t_matrix.m_a13
		&& m_a21 == t_matrix.m_a21 && m_a22 == t_matrix.m_a22 && m_a23 == t_matrix.m_a23
		&& m_a31 == t_matrix.m_a31 && m_a32 == t_matrix.m_a32 && m_a33 == t_matrix.m_a33)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// @brief overloaded operator != that checks if two matrices aren't equal
/// </summary>
/// <param name="t_matrix">second matrix</param>
/// <returns>true if the two matrices aren't equal, false if they are equal</returns>
bool Matrix3D::operator!=(Matrix3D t_matrix) const
{
	if (m_a11 != t_matrix.m_a11 || m_a12 != t_matrix.m_a12 || m_a13 != t_matrix.m_a13
		|| m_a21 != t_matrix.m_a21 || m_a22 != t_matrix.m_a22 || m_a23 != t_matrix.m_a23
		|| m_a31 != t_matrix.m_a31 || m_a32 != t_matrix.m_a32 || m_a33 != t_matrix.m_a33)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// @brief function that returns the selected row of a matrix as a vector
/// </summary>
/// <param name="t_rowNumber">row that is selected</param>
/// <returns>selected row as a vector</returns>
Vector3D Matrix3D::row(int t_rowNumber) const
{
	switch (t_rowNumber)
	{
	case 0:
		return Vector3D(m_a11, m_a12, m_a13);
		break;
	case 1:
		return Vector3D(m_a21, m_a22, m_a23);
		break;
	case 2:
		return Vector3D(m_a31, m_a32, m_a33);
		break;
	default:
		return Vector3D();
		break;
	}	
}

/// <summary>
/// @brief function that returns the selected column of a matrix as a vector
/// </summary>
/// <param name="t_columnNumber">column that is selected</param>
/// <returns>selected column as a vector</returns>
Vector3D Matrix3D::column(int t_columnNumber) const
{
	switch (t_columnNumber)
	{
	case 0:
		return Vector3D(m_a11, m_a21, m_a31);
		break;
	case 1:
		return Vector3D(m_a12, m_a22, m_a32);
		break;
	case 2:
		return Vector3D(m_a13, m_a23, m_a33);
		break;
	default:
		return Vector3D();
		break;
	}
}

/// <summary>
/// @brief function that returns the transpose of a matrix.
/// first column becomes the first row and so forth
/// </summary>
/// <returns>the transpose of the matrix</returns>
Matrix3D Matrix3D::transpose() const
{
	return Matrix3D(column(0),
					column(1),
					column(2));
}

/// <summary>
/// @brief function that calculates and returns the determinant of a matrix
/// </summary>
/// <returns>determinant of a matrix</returns>
double Matrix3D::determinant() const
{
	// a(ei - hf) - d(bi - hc) + g(bf - ec)
	// | a  b  c |
	// | d  e  f |
	// | g  h  i |
  	//       A          EI           HF             D         BI           HC            G          BF             EC
	return (m_a11 * ((m_a22 * m_a33) - (m_a32 * m_a23))) - (m_a21 * ((m_a12 * m_a33) - (m_a32 * m_a13))) + (m_a31 * ((m_a12 * m_a23) - (m_a22 * m_a13)));
}

/// <summary>
/// @brief function that calculates and returns the inverse of a matrix
/// </summary>
/// <returns>inverse of a matrix</returns>
Matrix3D Matrix3D::inverse() const
{
	if (determinant() == 0)	// prevent division by zero
	{
		return Matrix3D();
	}
	else
	{
		double t_scalar = 1.0 / determinant();
		Matrix3D answer((m_a22 * m_a33 - m_a23 * m_a32), (m_a13 * m_a32 - m_a12 * m_a33), (m_a12 * m_a23 - m_a13 * m_a22),
						(m_a23 * m_a31 - m_a21 * m_a33), (m_a11 * m_a33 - m_a13 * m_a31), (m_a13 * m_a21 - m_a11 * m_a23),
						(m_a21 * m_a32 - m_a22 * m_a31), (m_a12 * m_a31 - m_a11 * m_a32), (m_a11 * m_a22 - m_a12 * m_a21));
		return (answer * t_scalar);
	}
	
}

/// <summary>
/// @brief returns matrix to multiply by to rotate a vector
/// </summary>
/// <param name="t_angle">angle rotated by in degrees</param>
/// <returns>rotation matrix in the z axis</returns>
Matrix3D Matrix3D::rotation(double t_angle) const
{
	double radians = (acos(-1) / 180) * t_angle;  // converting to radians
	return Matrix3D(cos(radians) , sin(radians), 0,
					-sin(radians), cos(radians), 0,
					0, 0, 1);
}

/// <summary>
/// @brief returns matrix to multiply by to rotate a vector
/// </summary>
/// <param name="t_angle">angle rotated by in degrees</param>
/// <returns>rotation matrix in the x axis</returns>
Matrix3D Matrix3D::rotationX(double t_angle) const
{
	double radians = (acos(-1) / 180) * t_angle;  // converting to radians
	return Matrix3D(1, 0, 0,
					0, cos(radians), -sin(radians),
					0, sin(radians), cos(radians));
}

/// <summary>
/// @brief returns matrix to multiply by to rotate a vector
/// </summary>
/// <param name="t_angle">angle rotated by in degrees</param>
/// <returns>rotation matrix in the y axis</returns>
Matrix3D Matrix3D::rotationY(double t_angle) const
{
	double radians = (acos(-1) / 180) * t_angle;  // converting to radians
	return Matrix3D(cos(radians), 0, -sin(radians),
					0, 1, 0,
					sin(radians), 0, cos(radians));
}

/// <summary>
/// @brief returns matrix to multiply by to rotate a vector
/// </summary>
/// <param name="t_angle">angle rotated by in degrees</param>
/// <returns>rotation matrix in the z axis</returns>
Matrix3D Matrix3D::rotationZ(double t_angle) const
{
	double radians = (acos(-1) / 180) * t_angle;  // converting to radians
	return Matrix3D(cos(radians), sin(radians), 0,
					-sin(radians), cos(radians), 0,
					0, 0, 1);
}

/// <summary>
/// @brief returns the matrix to multiply by to translate a vector
/// </summary>
/// <param name="t_dx">x value to translate by</param>
/// <param name="t_dy">y value to translate by</param>
/// <returns>translation matrix</returns>
Matrix3D Matrix3D::translate(double t_dx, double t_dy) const
{
	return Matrix3D(1,0, t_dx,
					0,1, t_dy,
					0, 0, 1);
}








/// <summary>
/// @brief returns the matrix to multiply by to scale a vector
/// </summary>
/// <param name="t_dx">x value to scale by</param>
/// <param name="t_dy">y value to scale by</param>
/// <returns>scale matrix</returns>
Matrix3D Matrix3D::scale(double t_dx, double t_dy) const
{
	return Matrix3D(static_cast<double>(t_dx /100), 0, 0,
					0, static_cast<double>(t_dy / 100),0,
					0, 0, 1);
}

/// <summary>
/// @brief returns the matrix to multiply by to scale a vector in 3D
/// </summary>
/// <param name="t_dx">value for the 3D scale</param>
/// <returns>scale matrix</returns>
Matrix3D Matrix3D::scale3D(double t_dx) const
{
	return Matrix3D(static_cast<double>(t_dx),0,0,
					0, static_cast<double>(t_dx),0,
					0,0, static_cast<double>(t_dx));
}

/// <summary>
/// @brief function that returns a matrix as a string
/// </summary>
/// <returns>matrix in string form</returns>
std::string Matrix3D::toString() const
{
	return std::string("| " + std::to_string(m_a11) + "  " + std::to_string(m_a12) + "  " + std::to_string(m_a13) + " |\n"
				  "| " + std::to_string(m_a21) + "  " + std::to_string(m_a22) + "  " + std::to_string(m_a23) + " |\n"
				  "| " + std::to_string(m_a31) + "  " + std::to_string(m_a32) + "  " + std::to_string(m_a33) + " |");
}

/// <summary>
/// @brief returns the value in row 1 , column 1 in the matrix
/// </summary>
/// <returns>value of a11</returns>
double Matrix3D::A11() const
{
	return m_a11;
}

/// <summary>
/// @brief returns the value in row 1 , column 2 in the matrix
/// </summary>
/// <returns>value of a12</returns>
double Matrix3D::A12() const
{
	return m_a12;
}

/// <summary>
/// @brief returns the value in row 1 , column 3 in the matrix
/// </summary>
/// <returns>value of a13</returns>
double Matrix3D::A13() const
{
	return m_a13;
}

/// <summary>
/// @brief returns the value in row 2 , column 1 in the matrix
/// </summary>
/// <returns>value of a21</returns>
double Matrix3D::A21() const
{
	return m_a21;
}

/// <summary>
/// @brief returns the value in row 2 , column 2 in the matrix
/// </summary>
/// <returns>value of a22</returns>
double Matrix3D::A22() const
{
	return m_a22;
}

/// <summary>
/// @brief returns the value in row 2 , column 3 in the matrix
/// </summary>
/// <returns>value of a23</returns>
double Matrix3D::A23() const
{
	return m_a23;
}

/// <summary>
/// @brief returns the value in row 3 , column 1 in the matrix
/// </summary>
/// <returns>value of a31</returns>
double Matrix3D::A31() const
{
	return m_a31;
}

/// <summary>
/// @brief returns the value in row 3 , column 2 in the matrix
/// </summary>
/// <returns>value of a32</returns>
double Matrix3D::A32() const
{
	return m_a32;
}

/// <summary>
/// @brief returns the value in row 3 , column 3 in the matrix
/// </summary>
/// <returns>value of a33</returns>
double Matrix3D::A33() const
{
	return m_a33;
}
