/// <summary>
/// @author Cathal Redmond
/// </summary>
#include "Game.h"

bool updatable = false;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning){


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
					m_matrix = m_matrix.translate(0.0,-0.01);
					transform = true;
					break;
				case sf::Keyboard::S:
					m_matrix = m_matrix.translate(0.0, 0.01);
					transform = true;
					break;
				case sf::Keyboard::A:
					m_matrix = m_matrix.translate(0.01, 0.0);
					transform = true;
					break;
				case sf::Keyboard::D:
					m_matrix = m_matrix.translate(-0.01, 0.0);
					transform = true;
					break;
				case sf::Keyboard::R:
					m_matrix = m_matrix.rotationZ(2);
					transform = true;
					break;
				case sf::Keyboard::T:
					m_matrix = m_matrix.rotationZ(-2);
					transform = true;
					break;
				case sf::Keyboard::Y:
					m_matrix = m_matrix.rotationY(2);
					transform = true;
					break;
				case sf::Keyboard::U:
					m_matrix = m_matrix.rotationY(-2);
					transform = true;
					break;
				case sf::Keyboard::I:
					m_matrix = m_matrix.rotationX(2);
					transform = true;
					break;
				case sf::Keyboard::O:
					m_matrix = m_matrix.rotationX(-2);
					transform = true;
					break;
				case sf::Keyboard::C:
					m_matrix = m_matrix.scale(110, 110);
					transform = true;
					break;
				case sf::Keyboard::V:
					m_matrix = m_matrix.scale(90, 90);
					transform = true;
					break;
				default:
					break;
				}
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	cubeInitializePositions();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -10);
}

void Game::update()
{

	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	if (transform)
	{
		for (int index = 0; index < 8; index++)
		{
			m_cubePositions[index] = m_cubePositions[index] * m_matrix;
		}
		transform = false;
	}
	
}

void Game::draw()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);
	{
		
		// Face

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(m_cubePositions[0].Xf(), m_cubePositions[0].Yf(), m_cubePositions[0].Zf());
		glVertex3f(m_cubePositions[1].Xf(), m_cubePositions[1].Yf(), m_cubePositions[1].Zf());
		glVertex3f(m_cubePositions[2].Xf(), m_cubePositions[2].Yf(), m_cubePositions[2].Zf());
		glVertex3f(m_cubePositions[3].Xf(), m_cubePositions[3].Yf(), m_cubePositions[3].Zf());
			
		// Face
	
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_cubePositions[4].Xf(), m_cubePositions[4].Yf(), m_cubePositions[4].Zf());
		glVertex3f(m_cubePositions[5].Xf(), m_cubePositions[5].Yf(), m_cubePositions[5].Zf());
		glVertex3f(m_cubePositions[6].Xf(), m_cubePositions[6].Yf(), m_cubePositions[6].Zf());
		glVertex3f(m_cubePositions[7].Xf(), m_cubePositions[7].Yf(), m_cubePositions[7].Zf());

		// face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(m_cubePositions[0].Xf(), m_cubePositions[0].Yf(), m_cubePositions[0].Zf());
		glVertex3f(m_cubePositions[1].Xf(), m_cubePositions[1].Yf(), m_cubePositions[1].Zf());
		glVertex3f(m_cubePositions[5].Xf(), m_cubePositions[5].Yf(), m_cubePositions[5].Zf());
		glVertex3f(m_cubePositions[4].Xf(), m_cubePositions[4].Yf(), m_cubePositions[4].Zf());
	
		//  face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(m_cubePositions[2].Xf(), m_cubePositions[2].Yf(), m_cubePositions[2].Zf());
		glVertex3f(m_cubePositions[3].Xf(), m_cubePositions[3].Yf(), m_cubePositions[3].Zf());
		glVertex3f(m_cubePositions[7].Xf(), m_cubePositions[7].Yf(), m_cubePositions[7].Zf());
		glVertex3f(m_cubePositions[6].Xf(), m_cubePositions[6].Yf(), m_cubePositions[6].Zf());
	
		// face
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(m_cubePositions[1].Xf(), m_cubePositions[1].Yf(), m_cubePositions[1].Zf());
		glVertex3f(m_cubePositions[2].Xf(), m_cubePositions[2].Yf(), m_cubePositions[2].Zf());
		glVertex3f(m_cubePositions[6].Xf(), m_cubePositions[6].Yf(), m_cubePositions[6].Zf());
		glVertex3f(m_cubePositions[5].Xf(), m_cubePositions[5].Yf(), m_cubePositions[5].Zf());
		
		//  face
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(m_cubePositions[0].Xf(), m_cubePositions[0].Yf(), m_cubePositions[0].Zf());
		glVertex3f(m_cubePositions[3].Xf(), m_cubePositions[3].Yf(), m_cubePositions[3].Zf());
		glVertex3f(m_cubePositions[7].Xf(), m_cubePositions[7].Yf(), m_cubePositions[7].Zf());
		glVertex3f(m_cubePositions[4].Xf(), m_cubePositions[4].Yf(), m_cubePositions[4].Zf());
		

	}
	glEnd();
	

	window.display();


}

void Game::unload()
{
}

void Game::cubeInitializePositions()
{
	m_cubePositions[0] = Vector3D(1.0, 1.0, -1.0);
	m_cubePositions[1] = Vector3D(-1.0, 1.0, -1.0);
	m_cubePositions[2] = Vector3D(-1.0, -1.0, -1.0);
	m_cubePositions[3] = Vector3D(1.0, -1.0, -1.0);
	m_cubePositions[4] = Vector3D(1.0, 1.0, 1.0);
	m_cubePositions[5] = Vector3D(-1.0, 1.0, 1.0);
	m_cubePositions[6] = Vector3D(-1.0, -1.0, 1.0);
	m_cubePositions[7] = Vector3D(1.0, -1.0, 1.0);

	

}



