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
	case 5: // - shoot
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprShoot)
			{
			case 0:
				setSprite(Vector2i(0, 0), Vector2i(63, 65), 1);
				sprShoot++;
				break;
			case 1:
				setSprite(Vector2i(63, 0), Vector2i(63, 69), 1);
				sprShoot++;
				break;
			case 2:
				setSprite(Vector2i(126, 0), Vector2i(63, 70), 1);
				setShoot(false);
				sprShoot = 0;
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
	case 6: // - death
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprDeath)
			{
			case 0:
				if (type == 1) setSprite(Vector2i(0, 0), Vector2i(54, 56), 5);
				else if (type == 2) setSprite(Vector2i(0, 0), Vector2i(63, 67), 2);
				else if (type == 3) setSprite(Vector2i(0, 0), Vector2i(34, 51), 5);
				sprDeath++;
				break;
			case 1:
				if (type == 1) setSprite(Vector2i(54, 0), Vector2i(60, 57), 5);
				else if (type == 2) setSprite(Vector2i(63, 0), Vector2i(63, 67), 2);
				else if (type == 3) setSprite(Vector2i(34, 0), Vector2i(36, 53), 5);
				sprDeath++;
				break;
			case 2:
				if (type == 1) setSprite(Vector2i(114, 0), Vector2i(52, 54), 5);
				else if (type == 2) setSprite(Vector2i(126, 0), Vector2i(63, 67), 2);
				else if (type == 3) setSprite(Vector2i(70, 0), Vector2i(45, 48), 5);
				sprDeath++;
				break;
			case 3:
				if (type == 1) setSprite(Vector2i(166, 0), Vector2i(62, 58), 5);
				else if (type == 2) setSprite(Vector2i(189, 0), Vector2i(67, 77), 2);
				else if (type == 3) setSprite(Vector2i(115, 0), Vector2i(68, 60), 5);
				sprDeath++;
				break;
			case 4:
				if (type == 1) setSprite(Vector2i(228, 0), Vector2i(64, 47), 5);
				else if (type == 2) setSprite(Vector2i(256, 0), Vector2i(69, 66), 2);
				else if (type == 3) setSprite(Vector2i(183, 0), Vector2i(88, 72), 5);
				sprDeath++;
				break;
			case 5:
				if (type == 1) setSprite(Vector2i(292, 0), Vector2i(64, 33), 5);
				else if (type == 2) setSprite(Vector2i(325, 0), Vector2i(75, 49), 2);
				else if (type == 3) setSprite(Vector2i(271, 0), Vector2i(103, 90), 5);
				canDeath = true;
				sprDeath = 0;
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
	}

}