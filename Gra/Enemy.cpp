#include "Enemy.h"
#include <iostream>
Enemy::Enemy(float p_X, float p_Y, int hp, int type)
{
	shape.setPosition(p_X, p_Y);
	shape.setSize(Vector2f(this->enemy_rozm, this->enemy_rozm));
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
		if (round(this->shape.getPosition().y) > b_y)
		{
			if (this->top() > 0) { shape.move(this->ruchW); updateSprite(3); }	
		}
		else if (round(this->shape.getPosition().x) > b_x || round(this->shape.getPosition().y) == b_y)
		{
			if (this->left() > 0) { shape.move(this->ruchA); updateSprite(1); }
		}
		else if (round(this->shape.getPosition().x) < b_x || round(this->shape.getPosition().y) == b_y)
		{
			if (this->right() < 800) { shape.move(this->ruchD);  updateSprite(2); }
		}
		else if (round(this->shape.getPosition().y) < b_y )
		{
			if (this->bottom() < 600) { shape.move(this->ruchS); updateSprite(4); }
		}
		
	}
	else
	{
		
		if (b_x > this->shape.getPosition().x - 100 && b_x <= this->shape.getPosition().x + 100 &&
			b_y > this->shape.getPosition().y - 100 && b_y <= this->shape.getPosition().y + 100)
		{
			if (b_x > this->shape.getPosition().x)
			{
				if (this->left() > 0) { shape.move(this->ruchA); updateSprite(1); }
				return;
			}

			if (b_x < this->shape.getPosition().x)
			{
				if (this->right() < 800) { shape.move(this->ruchD);  updateSprite(2); }
				return;
			}

			if (b_y > this->shape.getPosition().y)
			{
				if (this->top() > 0) { shape.move(this->ruchW); updateSprite(3); }
				return;
			}

			if (b_y < this->shape.getPosition().y)
			{
				if (this->bottom() < 600) { shape.move(this->ruchS); updateSprite(4); }
				return;
			}
		}
		else
		{
			if (this->shape.getPosition().y >= b_y)
			{
				if (this->top() > 0) { shape.move(this->ruchW); updateSprite(3); }
			}
			if (this->shape.getPosition().x >= b_x)
			{
				if (this->left() > 0) { shape.move(this->ruchA); updateSprite(1); }
			}
			if (this->shape.getPosition().y <= b_y)
			{
				if (this->bottom() < 600) { shape.move(this->ruchS); updateSprite(4); }
			}
			if (this->shape.getPosition().x <= b_x)
			{
				if (this->right() < 800) { shape.move(this->ruchD);  updateSprite(2); }
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

// set sprite
void Enemy::setSprite(Vector2i startSprite, Vector2i endSprite, int direction)
{
	string tileset;
	switch (type)
	{
	case 1: // - pinky
		switch (direction)
		{
		case 0:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_1/pinkyN.png";
			break;
		case 1:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_1/pinkyA.png";
			break;
		case 2:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_1/pinkyD.png";
			break;
		case 3:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_1/pinkyW.png";
			break;
		case 4:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_1/pinkyS.png";
			break;
		} 
		break;
	case 2: // - imp 
		switch (direction)
		{
		case 0:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_2/impN.png";
			break;
		case 1:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_2/impA.png";
			break;
		case 2:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_2/impD.png";
			break;
		case 3:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_2/impW.png";
			break;
		case 4:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_2/impS.png";
			break;
		}
		break;
	case 3: // - demonSoul
		switch (direction)
		{
		case 0:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_3/SoulN.png";
			break;
		case 1:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_3/SoulA.png";
			break;
		case 2:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_3/SoulD.png";
			break;
		case 3:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_3/SoulW.png";
			break;
		case 4:
			tileset = "DATA/TEXTURE/ENEMIES/TYPE_3/SoulS.png";
			break;
		}
		break;
	}

	if (!texture.loadFromFile(tileset));
	else
	{
		shape.setTexture(&texture);
		shape.setTextureRect(IntRect(startSprite.x, startSprite.y, endSprite.x, endSprite.y));
	}
}