/// <summary>
/// @author Cathal Redmond
/// </summary>
#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Matrix3D.h"
#include "Vector3D.h"


class Vector3D;
class Matrix3D;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;

	void cubeInitializePositions();


	Vector3D m_cubePositions[8];
	Matrix3D m_matrix;

	// bool for if the  cube should move
	bool transform{ false };


	float rotationAngle = 0.0f;

};

#endif //!GAME_H