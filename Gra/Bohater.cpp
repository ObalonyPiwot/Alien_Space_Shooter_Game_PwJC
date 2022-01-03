#include "Bohater.h"
#include <iostream>

Bohater::Bohater(float p_X, float p_Y)
{
	shape.setPosition(p_X, p_Y);
	shape.setSize(Vector2f(this->postac_rozm, this->postac_rozm));
	shape.setOrigin(this->postac_rozm / 2, this->postac_rozm / 2);


	// - shoot sound
	if (!buffer.loadFromFile("DATA/SOUND/SAMPLES/playershoot.wav"))
		cout << "samples error ";
}
void Bohater::setWeapon(int a)
{
	if (a == 1)
	{
		this->weapon = 1;
		this->firingspeed = 10;
		this->shotspeed = 10;
		this->damage = 2;
	}
	if (a == 2)
	{
		this->weapon = 2;
		this->firingspeed = 40;
		this->shotspeed = 30;
		this->damage = 4;
	}
	if (a == 3)
	{
		this->weapon = 3;
		this->firingspeed = 4;
		this->shotspeed = 10;
		this->damage = 1;
	}
}
void Bohater::setPosition(float p_X, float p_Y)
{
	shape.setPosition(p_X, p_Y);
}
void Bohater::predkosci(float a)
{
	postac_predkosc = a;
}
void Bohater::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Bohater::ruch(int a)
{
	if (a == 1)
	{
		if (this->top() > 0)
			shape.move(this->ruchW);
	}
	if (a == 2)
	{
		if (this->left() > 0)
			shape.move(this->ruchA);
	}
	if (a == 3)
	{
		if (this->bottom() < 600)
			shape.move(this->ruchS);
	}
	if (a == 4)
	{
		if (this->right() < 800)
			shape.move(this->ruchD);
	}
}

float Bohater::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2;
}
float Bohater::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2;
}
float Bohater::left()
{
	return this->shape.getPosition().x - shape.getSize().y / 2;
}
float Bohater::right()
{
	return this->shape.getPosition().x + shape.getSize().y / 2;
}
void Bohater::collision(int a)
{
	if (a == 1)
		shape.move(this->ruchW);
	if (a == 2)
		shape.move(this->ruchA);
	if (a == 3)
		shape.move(this->ruchS);
	if (a == 4)
		shape.move(this->ruchD);
}

Vector2f Bohater::getPosition()
{
	return shape.getPosition();
}


void Bohater::setSprite(const string& tileset, Vector2i startSprite, Vector2i endSprite)
{
	if (!texture.loadFromFile(tileset));
	else
	{
		shape.setTexture(&texture);
		shape.setTextureRect(IntRect(startSprite.x, startSprite.y, endSprite.x, endSprite.y));
	}
}


// - shoot sound play
void Bohater::play_Shoot()
{
	sound.setBuffer(buffer);
	sound.play();
}