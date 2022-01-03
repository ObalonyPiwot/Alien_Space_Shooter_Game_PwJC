#include <iostream>
#include "sciany.h"

Sciany::Sciany(float x, float y, float a, float b, int type, int lava)
{
	shape.setPosition(x, y);
	shape.setSize(Vector2f(a, b));
	shape.setFillColor(Color(0, 255, 0));
	shape.setOrigin(a / 2, b / 2);
	this->wType = type;
	this->lava = lava;
	if (lava == 1)
		shape.setFillColor(Color(254, 144, 120));
}

void Sciany::setLava()
{
	this->lava = 1;
	shape.setFillColor(Color(254, 144, 120));
}

void Sciany::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float Sciany::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2;
}
float Sciany::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2;
}
float Sciany::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2;
}
float Sciany::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2;
}
Vector2f Sciany::getPosition()
{
	return shape.getPosition();
}

void Sciany::setTexture()
{
	switch(this->wType)
	{
	case 1:
		if(!wTexture.loadFromFile("DATA/TEXTURE/WALL/wall_1.png"))
			cout << "Nie wczytano_1 \n";
		shape.setTexture(&wTexture);
		break;
	case 2:
		if (!wTexture.loadFromFile("DATA/TEXTURE/WALL/wall_2.png"))
			cout << "Nie wczytano_2";
		shape.setTexture(&wTexture);
		break;
	}
}