#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(720, 480), "SFMLworks");
	Image Cloud;
	Cloud.loadFromFile("images/Cloud.png");

	Texture CloudTexture;
	CloudTexture.loadFromImage(Cloud);

	Sprite CloudSprite;
	CloudSprite.setTexture(CloudTexture);
	CloudSprite.setPosition(50, 20);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Cyan);
		window.draw(CloudSprite);
		window.display();
	}

	return 0;
}