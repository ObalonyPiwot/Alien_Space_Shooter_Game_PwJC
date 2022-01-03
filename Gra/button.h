#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Sciany.h"
#include "run_game.h"
using namespace std;
using namespace sf;


class Button: public Sciany
{
public:
	Button(float p_x, float p_y, float a, float b, int type, string tekst) :Sciany(p_x, p_y, a, b, type, lava)
	{
		setFont();
		bText.setString(tekst);
		//getShape();
		bText.setPosition(Vector2f(shape.getPosition().x-50, (shape.getPosition().y-20)));
		shape.setFillColor(Color::Red);
	};
	void draw(RenderWindow& window);
	void setFont();
	void setTexture();
	int checkMouse(Vector2i posMouse)
	{
		if ((posMouse.x >= Sciany::left()) && (posMouse.x <= Sciany::right()) && (posMouse.y >= Sciany::top()) && (posMouse.y <= Sciany::bottom()))
		{
			if (!Sciany::wTexture.loadFromFile("DATA/TEXTURE/BUTTON/active.png"))
				cout << "Nie wczytano_1 \n";
			shape.setTexture(&wTexture);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (!buffer.loadFromFile("DATA/SOUND/SAMPLES/click.wav"))
					cout << "samples error ";
				sound.setBuffer(buffer);
				sound.play();
				switch (wType)
				{
				case 1:
					return 1;
					break;
				case 2:
					return 2;
					break;
				}
			}
		}
		else
		{
			if (!Sciany::wTexture.loadFromFile("DATA/TEXTURE/BUTTON/disable.png"))
				cout << "Nie wczytano_1 \n";
			shape.setTexture(&wTexture);
			return 0;
		}
			
	}
private:
	//RectangleShape bShape;
	SoundBuffer buffer;
	Sound sound;
	Font bFont;
	Text bText;
};