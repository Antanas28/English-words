#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>

using namespace sf;

class Button {
public:
	Vector2f bPosition;
	IntRect bSprite;
	Sprite sprite;
	std::function<void()> onClick;
	std::function<void()> onRelease;
	bool hasOnClick = false;
	bool hasOnRelease = false;


	Button(Texture& texture, Vector2f bPosition, IntRect bSprite) {
		sprite.setTexture(texture);
		this->bPosition = bPosition;
		this->bSprite = bSprite;
		sprite.setTextureRect(bSprite);
		sprite.setPosition(bPosition);
	}

};

std::vector<Button> gui;
Texture guiTexture;

void SetUpGUI() {
	guiTexture.loadFromFile("images/gui.png");

	Button temp(guiTexture, Vector2f(200, 200), IntRect(0, 0, 150, 75));
	temp.onClick = []() { std::cout << "Learn English!\n"; };
	temp.hasOnClick = true;
	temp.onRelease = []() { std::cout << "English Learn!\n"; };
	temp.hasOnRelease = true;
	gui.push_back(temp);

	temp = Button(guiTexture, Vector2f(400, 200), IntRect(0, 75, 150, 75));
	temp.onClick = []() { std::cout << "English\n"; };
	temp.hasOnClick = true;
	gui.push_back(temp);
}

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

	SetUpGUI();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					for (int i = 0; i < gui.size(); i++) {
						if (gui.at(i).hasOnClick) {
							if (gui.at(i).hasOnClick) {
								if (Mouse::getPosition(window).x > gui.at(i).bPosition.x &&
									Mouse::getPosition(window).x < gui.at(i).bPosition.x + gui.at(i).bSprite.width &&
									Mouse::getPosition(window).y > gui.at(i).bPosition.y &&
									Mouse::getPosition(window).y < gui.at(i).bPosition.y + gui.at(i).bSprite.width) {
									gui.at(i).onClick();
								}
							}

						}
					}
				}
			}
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Right) {
					for (int i = 0; i < gui.size(); i++) {
						if (gui.at(i).hasOnRelease) {
							if (gui.at(i).hasOnRelease) {
								if (Mouse::getPosition(window).x > gui.at(i).bPosition.x &&
									Mouse::getPosition(window).x < gui.at(i).bPosition.x + gui.at(i).bSprite.width &&
									Mouse::getPosition(window).y > gui.at(i).bPosition.y &&
									Mouse::getPosition(window).y < gui.at(i).bPosition.y + gui.at(i).bSprite.width) {
									gui.at(i).onRelease();
								}
							}

						}
					}
				}
			}
		}

		window.setTitle("English Word");
		window.clear(sf::Color(71,202,221));
		text.setString("English Words");
		window.draw(text);
		window.draw(FCloudSprite);
		window.draw(SCloudSprite);
		for (int i = 0; i < gui.size(); i++) {
			window.draw(gui.at(i).sprite);
		}
		window.display();
	}

	return 0;
}