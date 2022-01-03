#include "Enemy.h"
Enemy::Enemy(float p_X, float p_Y, int hp, int type)
{
	shape.setPosition(p_X, p_Y);
	shape.setSize(Vector2f(this->enemy_rozm, this->enemy_rozm));
	shape.setFillColor(Color::Red);
	shape.setOrigin(this->enemy_rozm / 2, this->enemy_rozm / 2);
	this->HP = hp;
	this->type = type;
}

void Enemy::drawEnemy(RenderWindow& target)
{
	if (shape.getPosition().x > 0 or shape.getPosition().x < 800 or shape.getPosition().y > 0 or shape.getPosition().x < 600)
		target.draw(shape);
}

int Enemy::canShot()
{
	if (this->shot == 0)
	{
		this->shot = 30;
		return 1;
	}
	this->shot--;
	return 0;
}

void Enemy::ruch(int b_x, int b_y)
{
	if (type != 2)
	{
		if (this->shape.getPosition().y >= b_y)
		{
			if (this->top() > 0)
				shape.move(this->ruchW);
		}
		if (this->shape.getPosition().x >= b_x)
		{
			if (this->left() > 0)
				shape.move(this->ruchA);
		}
		if (this->shape.getPosition().y <= b_y)
		{
			if (this->bottom() < 600)
				shape.move(this->ruchS);
		}
		if (this->shape.getPosition().x <= b_x)
		{
			if (this->right() < 800)
				shape.move(this->ruchD);
		}
	}
	else
	{
		if (b_x > this->shape.getPosition().x - 100 && b_x <= this->shape.getPosition().x + 100 &&
			b_y > this->shape.getPosition().y - 100 && b_y <= this->shape.getPosition().y + 100)
		{
			if (b_x > this->shape.getPosition().x)
			{
				if (this->left() > 0)
					shape.move(this->ruchA);
				return;
			}

			if (b_x < this->shape.getPosition().x)
			{
				if (this->right() < 800)
					shape.move(this->ruchD);
				return;
			}

			if (b_y > this->shape.getPosition().y)
			{
				if (this->top() > 0)
					shape.move(this->ruchW);
				return;
			}

			if (b_y < this->shape.getPosition().y)
			{
				if (this->bottom() < 600)
					shape.move(this->ruchS);
				return;
			}
		}
		else
		{
			if (this->shape.getPosition().y >= b_y)
			{
				if (this->top() > 0)
					shape.move(this->ruchW);
			}
			if (this->shape.getPosition().x >= b_x)
			{
				if (this->left() > 0)
					shape.move(this->ruchA);
			}
			if (this->shape.getPosition().y <= b_y)
			{
				if (this->bottom() < 600)
					shape.move(this->ruchS);
			}
			if (this->shape.getPosition().x <= b_x)
			{
				if (this->right() < 800)
					shape.move(this->ruchD);
			}
		}
	}
}

float Enemy::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2;
}
float Enemy::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2;
}
float Enemy::left()
{
	return this->shape.getPosition().x - shape.getSize().y / 2;
}
float Enemy::right()
{
	return this->shape.getPosition().x + shape.getSize().y / 2;
}
void Enemy::collision(int a)
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
void Enemy::setType(int a)
{
	type = a;
}

Vector2f Enemy::getPosition()
{
	return shape.getPosition();
}