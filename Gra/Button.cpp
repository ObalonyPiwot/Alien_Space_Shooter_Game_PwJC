#include <iostream>
#include "button.h"

void Button::draw(RenderWindow& window)
{
	window.draw(Sciany::shape);
	window.draw(bText);
}
void Button::setFont()
{
	if (!bFont.loadFromFile("DATA/FONT/Painkiller Demo.ttf"))
		cout << "error font";
	bText.setCharacterSize(20);
	bText.setFillColor(Color(211,211,211,255));
	bText.setFont(bFont);
}
void Button::setTexture()
{
	switch (Sciany::wType)
	{
	case 1:
		if (!Sciany::wTexture.loadFromFile("DATA/TEXTURE/BUTTON/disable.png"))
			cout << "Nie wczytano_1 \n";
		shape.setTexture(&wTexture);
		break;
	}
}

