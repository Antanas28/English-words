#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>
#include "Menu.h"
#include "EnglishWord.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(720, 480), "English Word");
	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		menu(window);
	}

	return 0;
}