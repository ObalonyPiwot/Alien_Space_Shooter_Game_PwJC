#include "Enemy.h"
#include <iostream>
// - move sprite
void Enemy::updateSprite(int spriteType)
{
	switch (spriteType)
	{
	case 0:
		sprW = sprA = sprS = sprD = timeSprite = 0;
		if (type == 1) setSprite( Vector2i(0, 0), Vector2i(43, 54), 0);
		else if (type == 2) setSprite( Vector2i(0, 0), Vector2i(63, 66), 0);
		else if (type == 3) setSprite(Vector2i(0, 0), Vector2i(44, 47), 0);
		break;
	case 1: // -- A
		sprW = sprS = sprD = 0;
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprA)
			{
			case 0:
				if(type == 1)setSprite(Vector2i(0, 0), Vector2i(60, 53), 1);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if( type == 3) setSprite(Vector2i(0, 0), Vector2i(68, 33), 1);
				
				sprA++;
				break;
			case 1:
				if (type == 1) setSprite( Vector2i(61, 0), Vector2i(58, 56), 1);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(69, 0), Vector2i(63, 33), 1);
				sprA++;
				break;
			case 2:
				if (type == 1)setSprite( Vector2i(119, 0), Vector2i(60, 53), 1);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(0, 0), Vector2i(68, 33), 1);
				sprA++;
				break;
			case 3:
				if (type == 1)setSprite( Vector2i(179, 0), Vector2i(59, 56), 1);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(69, 0), Vector2i(63, 33), 1);
				sprA = 0;
				break;
			}
		}
		else
		{
			timeSprite++;
			if (timeSprite == NUMBER_OF_MOVE_SPRITE)
				timeSprite = 0;
		}


		break;
	case 2: // -- D
		sprW = sprS = sprA = 0;
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprD)
			{
			case 0:
				if (type == 1)setSprite( Vector2i(0, 0), Vector2i(60, 52), 2);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(0, 0), Vector2i(67, 33), 2);
				sprD++;
				break;
			case 1:
				if (type == 1)setSprite( Vector2i(60, 0), Vector2i(58, 56), 2);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3)	setSprite(Vector2i(67, 0), Vector2i(67, 33), 2);
				sprD++;
				break;
			case 2:
				if (type == 1)setSprite( Vector2i(118, 0), Vector2i(60, 53), 2);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3)	setSprite(Vector2i(0, 0), Vector2i(67, 33), 2);
				sprD++;
				break;
			case 3:
				if (type == 1)setSprite( Vector2i(178, 0), Vector2i(59, 56), 2);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(67, 0), Vector2i(67, 33), 2);
				sprD = 0;
				break;
			}
		}
		else
		{
			timeSprite++;
			if (timeSprite == NUMBER_OF_MOVE_SPRITE)
				timeSprite = 0;
		}
		break;
	case 3: // - W
		sprD = sprS = sprA = 0;
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprW)
			{
			case 0:
				if (type == 1)setSprite( Vector2i(0, 0), Vector2i(35, 54), 3);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(0, 0), Vector2i(43, 26), 3);
				sprW++;
				break;
			case 1:
				if (type == 1)setSprite( Vector2i(35, 0), Vector2i(39, 53), 3);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(43, 0), Vector2i(45, 26), 3);
				sprW++;
				break;
			case 2:
				if (type == 1)setSprite( Vector2i(74, 0), Vector2i(35, 54), 3);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(0, 0), Vector2i(43, 26), 3);
				sprW++;
				break;
			case 3:
				if (type == 1)setSprite( Vector2i(109, 0), Vector2i(39, 53), 3);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3) setSprite(Vector2i(43, 0), Vector2i(45, 26), 3);
				sprW = 0;
				break;
			}
		}
		else
		{
			timeSprite++;
			if (timeSprite == NUMBER_OF_MOVE_SPRITE)
				timeSprite = 0;
		}
		break;
	case 4: // - S
		sprD = sprW = sprA = 0;
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprS)
			{
			case 0:
				if (type == 1)setSprite( Vector2i(0, 0), Vector2i(39, 56), 4);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3)	setSprite(Vector2i(43, 0), Vector2i(45, 47), 4);
				sprS++;
				break;
			case 1:
				if (type == 1)setSprite( Vector2i(39, 0), Vector2i(45, 58), 4);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3)	setSprite(Vector2i(45, 0), Vector2i(44, 46), 4);
				sprS++;
				break;
			case 2:
				if (type == 1)setSprite( Vector2i(84, 0), Vector2i(39, 55), 4);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3)	setSprite(Vector2i(43, 0), Vector2i(45, 47), 4);
				sprS++;
				break;
			case 3:
				if (type == 1)setSprite( Vector2i(123, 0), Vector2i(43, 58), 4);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 66), 0);
				else if (type == 3)	setSprite(Vector2i(45, 0), Vector2i(44, 46), 4);
				sprS = 0;
				break;
			}
		}
		else
		{
			timeSprite++;
			if (timeSprite == NUMBER_OF_MOVE_SPRITE)
				timeSprite = 0;
		}
		break;
	default:
		break;
	}

}