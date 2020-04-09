#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>
#include "Menu.h"

using namespace sf;

void Second(RenderWindow& window)
{

	Image BackGr;
	BackGr.loadFromFile("images/backgr1.png");
	Texture BackGrTexture;
	BackGrTexture.loadFromImage(BackGr);
	Sprite BackGrSprite;
	BackGrSprite.setTexture(BackGrTexture);
	BackGrSprite.setPosition(0, 0);


	Font font;
	font.loadFromFile("Winter Snow.ttf");
	Text text("", font, 30);
	text.setStyle(Text::Bold);
	text.setPosition(255, 120);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		text.setString("");
		window.setTitle("English Word");
		window.clear(sf::Color(226, 221, 84));
		window.draw(text);
		window.draw(BackGrSprite);

		window.display();
	}
}