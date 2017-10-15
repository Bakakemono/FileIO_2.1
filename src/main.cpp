
#include <image_sfml.h>
#include <iostream>
#include "Shapes.h"

#define WINDOWS_SIZE 500


int main()
{
	float r = 50;//radius of circle
	float squartSize = 100;
	float squartPositionX = 200;
	float squartPositionY = 200;
	double circlePositionX = 0;
	double circlePositionY = 0;

	//créer une fenêtre
	sf::RenderWindow window(sf::VideoMode(WINDOWS_SIZE, WINDOWS_SIZE), "check Collision");
	window.setFramerateLimit(300);




	sf::CircleShape circle(r);
	circle.setFillColor(sf::Color::Green);
	circle.setPointCount(100);


	sf::RectangleShape squart(sf::Vector2f(squartSize, squartSize));
	squart.setFillColor(sf::Color::Blue);
	squart.setPosition(squartPositionX, squartPositionY);

	
	
	
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			
		}
		Shape* s1 = new Rectangle(squartPositionX, squartPositionY, squartSize, squartSize);
		Shape* s2 = new Circle(circlePositionX, circlePositionY, r);

		if (s2->isColliding(s1))
		{
			circle.setFillColor(sf::Color::Red);
			squart.setFillColor(sf::Color::Red);
		}


		sf::Vector2f delta_move;

		//manage input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			delta_move.x -= 1.0f;
			circlePositionX -= 1.0f;

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			delta_move.x += 1.0f;
			circlePositionX += 1.0f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			delta_move.y -= 1.0f;
			circlePositionY -= 1.0f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			delta_move.y += 1.0f;
			circlePositionY += 1.0f;
		}
		circle.setPosition(circle.getPosition() + delta_move);

		window.clear();
		window.draw(squart);
		window.draw(circle);

		window.display();

		squart.setFillColor(sf::Color::Blue);
		circle.setFillColor(sf::Color::Green);

	}

	return 0;
}
