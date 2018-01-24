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
					m_matrix = m_matrix.translate(0.1,0.0);
					transform = true;
					break;
				case sf::Keyboard::S:
					m_matrix = m_matrix.translate(0.0, 0.1);
					transform = true;
					break;
				case sf::Keyboard::A:
					m_matrix = m_matrix.translate(0.1, 0.0);
					transform = true;
					break;
				case sf::Keyboard::D:
					m_matrix = m_matrix.translate(-0.1, 0.0);
					transform = true;
					break;
				case sf::Keyboard::Z:
					m_matrix = m_matrix.rotation(1);
					transform = true;
					break;
				case sf::Keyboard::X:
					m_matrix = m_matrix.rotation(-1);
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
			
				case sf::Keyboard::Return:
					outputPoints();
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
	cubeInitPos();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(0, 0, 10, 0, 0, 0, 0, -1, 0);

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
			if (transform)
			{
				m_cubePositions[index] = m_cubePositions[index] * m_matrix;
			}
		}
		transform = false;
	}
	
}

void Game::draw()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);
	{//Front Face

		getNormalVectorsForFaces();

	//	if (normalVectors[0].Z() >= 0)
	//	{
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(m_cubePositions[0].Xf(), m_cubePositions[0].Yf(), m_cubePositions[0].Zf());
			glVertex3f(m_cubePositions[1].Xf(), m_cubePositions[1].Yf(), m_cubePositions[1].Zf());
			glVertex3f(m_cubePositions[2].Xf(), m_cubePositions[2].Yf(), m_cubePositions[2].Zf());
			glVertex3f(m_cubePositions[3].Xf(), m_cubePositions[3].Yf(), m_cubePositions[3].Zf());
			
			//Back Face
	//	}
	//	if (normalVectors[1].Z() >= 0)
	//	{
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(m_cubePositions[4].Xf(), m_cubePositions[4].Yf(), m_cubePositions[4].Zf());
			glVertex3f(m_cubePositions[5].Xf(), m_cubePositions[5].Yf(), m_cubePositions[5].Zf());
			glVertex3f(m_cubePositions[6].Xf(), m_cubePositions[6].Yf(), m_cubePositions[6].Zf());
			glVertex3f(m_cubePositions[7].Xf(), m_cubePositions[7].Yf(), m_cubePositions[7].Zf());
		//}

	//	if (normalVectors[2].Z() >= 0)
	//	{//top face
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(m_cubePositions[0].Xf(), m_cubePositions[0].Yf(), m_cubePositions[0].Zf());
			glVertex3f(m_cubePositions[1].Xf(), m_cubePositions[1].Yf(), m_cubePositions[1].Zf());
			glVertex3f(m_cubePositions[5].Xf(), m_cubePositions[5].Yf(), m_cubePositions[5].Zf());
			glVertex3f(m_cubePositions[4].Xf(), m_cubePositions[4].Yf(), m_cubePositions[4].Zf());
	//	}
	//	if (normalVectors[3].Z() >= 0)
	//	{
			// bottom face
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(m_cubePositions[2].Xf(), m_cubePositions[2].Yf(), m_cubePositions[2].Zf());
			glVertex3f(m_cubePositions[3].Xf(), m_cubePositions[3].Yf(), m_cubePositions[3].Zf());
			glVertex3f(m_cubePositions[7].Xf(), m_cubePositions[7].Yf(), m_cubePositions[7].Zf());
			glVertex3f(m_cubePositions[6].Xf(), m_cubePositions[6].Yf(), m_cubePositions[6].Zf());
		//}

	//	if (normalVectors[4].Z() >= 0)
	//	{
			//left face
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(m_cubePositions[1].Xf(), m_cubePositions[1].Yf(), m_cubePositions[1].Zf());
			glVertex3f(m_cubePositions[2].Xf(), m_cubePositions[2].Yf(), m_cubePositions[2].Zf());
			glVertex3f(m_cubePositions[6].Xf(), m_cubePositions[6].Yf(), m_cubePositions[6].Zf());
			glVertex3f(m_cubePositions[5].Xf(), m_cubePositions[5].Yf(), m_cubePositions[5].Zf());
		//}
		//if (normalVectors[5].Z() >= 0)
		//{
			// right face
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(m_cubePositions[0].Xf(), m_cubePositions[0].Yf(), m_cubePositions[0].Zf());
			glVertex3f(m_cubePositions[3].Xf(), m_cubePositions[3].Yf(), m_cubePositions[3].Zf());
			glVertex3f(m_cubePositions[7].Xf(), m_cubePositions[7].Yf(), m_cubePositions[7].Zf());
			glVertex3f(m_cubePositions[4].Xf(), m_cubePositions[4].Yf(), m_cubePositions[4].Zf());
		//}
		

		//Complete the faces of the Cube
	}
	glEnd();
	

	window.display();


}

void Game::unload()
{
}

void Game::cubeInitPos()
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

void Game::outputPoints()
{
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	for (int index = 0; index < 6; index++)
	{
		if (normalVectors[index].Z() >= 0)
		{
			switch (index)
			{
			case 0:
				std::cout << "BLUE" << std::endl;
				break;
			case 1:
				std::cout << "GREEN" << std::endl;
				break;
			case 2:
				std::cout << "RED" << std::endl;
				break;
			case 3:
				std::cout << "YELLOW" << std::endl;
				break;
			case 4:
				std::cout << "MAGNETA" << std::endl;
				break;
			case 5:
				std::cout << "CYAN" << std::endl;
				break;
			default:
				break;
			}
		}
	}
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;
}

void Game::getNormalVectorsForFaces()
{
	normalVectors[0] = ((m_cubePositions[1] - m_cubePositions[0]) ^ (m_cubePositions[3] - m_cubePositions[0]));

	normalVectors[1] = ((m_cubePositions[5] - m_cubePositions[4]) ^ (m_cubePositions[7] - m_cubePositions[4]));

	normalVectors[2] = ((m_cubePositions[0] - m_cubePositions[4]) ^ (m_cubePositions[5] - m_cubePositions[4]));

	normalVectors[3] = ((m_cubePositions[2] - m_cubePositions[3]) ^ (m_cubePositions[6] - m_cubePositions[3]));

	normalVectors[4] = ((m_cubePositions[1] - m_cubePositions[5]) ^ (m_cubePositions[6] - m_cubePositions[5]));

	normalVectors[5] = ((m_cubePositions[0] - m_cubePositions[3]) ^ (m_cubePositions[7] - m_cubePositions[3]));
}

