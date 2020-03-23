#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(720, 480), "SFMLworks");
	Image FirstCloud;
	FirstCloud.loadFromFile("images/Cloud.png");

	Texture FCloudTexture;
	FCloudTexture.loadFromImage(FirstCloud);

	Sprite FCloudSprite;
	FCloudSprite.setTexture(FCloudTexture);
	FCloudSprite.setPosition(-65, 35);

	Image SecondCloud;
	SecondCloud.loadFromFile("images/SCloud.png");

	Texture SCloudTexture;
	SCloudTexture.loadFromImage(SecondCloud);

	Sprite SCloudSprite;
	SCloudSprite.setTexture(SCloudTexture);
	SCloudSprite.setPosition(550, 200);

	Font font;
	font.loadFromFile("Winter Snow.ttf");
	Text text("", font, 30);
	//text.setColor(Color::White);
	text.setStyle(Text::Bold);
	text.setPosition(255, 120);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Cyan);
		text.setString("English Words");
		window.draw(text);
		window.draw(FCloudSprite);
		window.draw(SCloudSprite);
		window.display();
	}

	return 0;
}