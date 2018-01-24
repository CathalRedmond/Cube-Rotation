/// <summary>
/// @author Cathal Redmond
/// </summary>
#include "Vector3D.h"


/// <summary>
/// @brief basic constructor for a vector
/// </summary>
Vector3D::Vector3D()
{
	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;
}




/// <summary>
/// @brief overload constructor for the vector
/// allows specific values for x , y and z to be declared
/// </summary>
/// <param name="t_x">value for the x component</param>
/// <param name="t_y">value for the y component</param>
/// <param name="t_z">value for the z component</param>
Vector3D::Vector3D(double t_x, double t_y, double t_z)
{
	m_x = t_x;
	m_y = t_y;
	m_z = t_z;
}

/// <summary>
/// @brief overload constructor for the vector
/// Allows for a 2D vector values to be inputted and then creates a 3D version with z set to zero
/// </summary>
/// <param name="t_x"></param>
/// <param name="t_y"></param>
Vector3D::Vector3D(double t_x, double t_y)
{
	m_x = t_x;
	m_y = t_y;
	m_z = 1.0;
}

/// <summary>
/// @brief returns value for X
/// </summary>
/// <returns>x component of the vector</returns>
double Vector3D::X() const
{
	return m_x;
}

/// <summary>
/// @brief returns value for y
/// </summary>
/// <returns>y component of the vector</returns>
double Vector3D::Y() const
{
	return m_y;
}

/// <summary>
/// @brief returns value for z
/// </summary>
/// <returns>z component of the vector</returns>
double Vector3D::Z() const
{
	return m_z;
}

float Vector3D::Xf() const
{
	return static_cast<float>(m_x);
}

float Vector3D::Yf() const
{
	return static_cast<float>(m_y);
}

float Vector3D::Zf() const
{
	return static_cast<float>(m_z);
}

/// <summary>
/// @brief returns the length of the vector
/// </summary>
/// <returns>length of the vector</returns>
double Vector3D::length() const
{
	return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

/// <summary>
/// @brief returns the length squared of the vector
/// </summary>
/// <returns></returns>
double Vector3D::lengthSquared() const
{
	return (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
}

/// <summary>
/// @brief function that changes the length of the vector to 1.0
/// </summary>
void Vector3D::normalise() 
{
	// prevents division by zero
	if (length() > 0.0)	
	{
		m_x = m_x / length();
		m_y = m_y / length();
		m_z = m_z / length();
	}
}



/// <summary>
/// @brief an overloaded operator + to return the sum of 2 vectors
/// </summary>
/// <param name="t_vector3D">second vector</param>
/// <returns>sum of the two vectors</returns>
Vector3D Vector3D::operator+(Vector3D t_vector3D) const
{
	return Vector3D(m_x + t_vector3D.m_x, 
					m_y + t_vector3D.m_y,
					m_z + t_vector3D.m_z);
}

/// <summary>
/// @brief overloaded operator - to return the difference of 2 vectors
/// </summary>
/// <param name="t_vector3D">second vector</param>
/// <returns>difference of two vectors</returns>
Vector3D Vector3D::operator-(Vector3D t_vector3D) const
{
	return Vector3D(m_x - t_vector3D.m_x,
					m_y - t_vector3D.m_y,
					m_z - t_vector3D.m_z);
}

/// <summary>
/// @brief operator - that returns the negative value of a vector
/// multiplies current vector by -1
/// </summary>
/// <returns>negated vector</returns>
Vector3D Vector3D::operator-() const
{
	return Vector3D(-m_x,-m_y,-m_z);
}


/// <summary>
/// @brief overloaded operator * that returns the scalar product of two vectors
/// </summary>
/// <param name="t_vector3D">second vector</param>
/// <returns>scalar product of two vectors</returns>
double Vector3D::operator*(Vector3D t_vector3D) const
{
	return double((m_x * t_vector3D.m_x) + (m_y * t_vector3D.m_y) + (m_z * t_vector3D.m_z));
}


/// <summary>
/// @brief overloaded operator * that returns the product of a vector by a double
/// </summary>
/// <param name="t_scalar">double value to multiply vector by</param>
/// <returns>multiplied vector</returns>
Vector3D Vector3D::operator*(double t_scalar) const
{
	return Vector3D(m_x * t_scalar, m_y * t_scalar, m_z * t_scalar);
}

/// <summary>
/// @brief overloaded operator * that returns the product of a vector by a float
/// </summary>
/// <param name="t_scalar">float value to multiply vector by</param>
/// <returns>multiplied vector</returns>
Vector3D Vector3D::operator*(float t_scalar) const
{
	return Vector3D( m_x * t_scalar, m_y * t_scalar, m_z * t_scalar);
}

/// <summary>
/// @brief overloaded operator * that returns the product of a vector by a int
/// </summary>
/// <param name="t_scalar">int value to multiply vector by</param>
/// <returns>multiplied vector</returns>
Vector3D Vector3D::operator*(int t_scalar) const
{
	return Vector3D(m_x * t_scalar, m_y * t_scalar, m_z * t_scalar);
}

/// <summary>
/// @brief overloaded operator ^ that returns the vector product of two vectors
/// </summary>
/// <param name="t_vector">second vector</param>
/// <returns>vector product of two vectors</returns>
Vector3D Vector3D::operator^(Vector3D t_vector) const
{
	return Vector3D((m_y * t_vector.m_z) - (m_z * t_vector.m_y), (m_z * t_vector.m_x) - (m_x * t_vector.m_z), (m_x * t_vector.m_y) - (m_y * t_vector.m_x));
}

/// <summary>
/// @brief overloaded operator == that checks if two vectors are equal to each other
/// </summary>
/// <param name="t_vector">second vector</param>
/// <returns>true if equal , false if not equal</returns>
bool Vector3D::operator==(Vector3D t_vector) const
{
	if (m_x == t_vector.m_x && m_y == t_vector.m_y && m_z == t_vector.m_z)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/// <summary>
/// @breif overloaded operator != that checks if two vectors are not equal
/// </summary>
/// <param name="t_vector">second vector</param>
/// <returns>true if not equal, false if equal</returns>
bool Vector3D::operator!=(Vector3D t_vector) const
{
	if (m_x != t_vector.m_x || m_y != t_vector.m_y || m_z != t_vector.m_z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// @brief function that returns vector as a std::string
/// </summary>
std::string Vector3D::toString() const
{
	return std::string("( " + std::to_string(m_x) + " , " + std::to_string(m_y) + " , " + std::to_string(m_z) + " )");
}



/// <summary>
/// @brief an overloaded operator * to return the product of a vector by a matrix (vector * matrix)
/// </summary>
/// <param name="t_matrix3D">the matrix</param>
/// <returns>product of the vector by the matrix</returns>
Vector3D Vector3D::operator*(Matrix3D t_matrix3D) const
{
	return Vector3D((t_matrix3D.A11() * m_x) + (t_matrix3D.A12() * m_y) + (t_matrix3D.A13() * m_z),
					(t_matrix3D.A21() * m_x) + (t_matrix3D.A22() * m_y) + (t_matrix3D.A23() * m_z),
					(t_matrix3D.A31() * m_x) + (t_matrix3D.A32() * m_y) + (t_matrix3D.A33() * m_z));
}



// constructor for a vector2i function
Vector3D::Vector3D(sf::Vector2i vector) :

	m_x(static_cast<double>(vector.x)),
	m_y(static_cast<double>(vector.y)),
	m_z(0.0)

{
}


// constructor for a vector2f function
Vector3D::Vector3D(sf::Vector2f vector) :

	m_x(static_cast<double>(vector.x)),
	m_y(static_cast<double>(vector.y)),
	m_z(0.0)

{
}

// constructor for a vector2u function
Vector3D::Vector3D(sf::Vector2u vector) :

	m_x(static_cast<double>(vector.x)),
	m_y(static_cast<double>(vector.y)),
	m_z(0.0)

{
}

// constructor for a vector3f function
Vector3D::Vector3D(sf::Vector3f vector) :

	m_x(static_cast<double>(vector.x)),
	m_y(static_cast<double>(vector.y)),
	m_z(static_cast<double>(vector.z))
{
}


// constructor for a vector3i function
Vector3D::Vector3D(sf::Vector3i vector) :

	m_x(static_cast<double>(vector.x)),
	m_y(static_cast<double>(vector.y)),
	m_z(static_cast<double>(vector.z))

{
}