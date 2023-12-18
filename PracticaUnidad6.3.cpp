// Practica Unidad 6 - Bounce - MAVI - Fabrizio Aguilar
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Space");

	sf::Vector2f position(400.0f, 100.0f);
	sf::Vector2f velocity(0.0f, 30.0f);

	const float gravity = 0.00098f;
	float acceleration = 1000.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float deltaTime = 0.1f / 60.0f;
		velocity.y += gravity *  acceleration * deltaTime;
		position += velocity * deltaTime;

		// Para verificar velocidad Y -> cout << velocity.y << endl;

		if (position.y > 600-40) {
			position.y = 600-40;
			velocity.y = -velocity.y * 0.65;	
		}

		window.clear();
		
		sf::CircleShape ball(20.0f);
		ball.setFillColor(sf::Color::Cyan);
		ball.setPosition(position);
		window.draw(ball);
		
		window.display();
	}

	return 0;
}
