#include "Bohater.h"
#include <iostream>
// - move sprite
void Bohater::updateSprite(int spriteType)
{
	switch (spriteType)
	{
	case 0:
		sprW = sprA = sprS = sprD = timeSprite = 0;
		setSprite("DATA/TEXTURE/PLAYER/stand.png", Vector2i(0, 0), Vector2i(36, 56));
		break;
	case 1: // -- A
		if (Keyboard::isKeyPressed(Keyboard::W)) { Bohater::updateSpriteDiagonally(1); return; }
		else if (Keyboard::isKeyPressed(Keyboard::S)) { Bohater::updateSpriteDiagonally(3); return; }
		sprW = sprS = sprD = 0;
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprA)
			{
			case 0:
				setSprite("DATA/TEXTURE/PLAYER/marine.png", Vector2i(0, 0), Vector2i(34, 55));
				sprA++;
				break;
			case 1:
				setSprite("DATA/TEXTURE/PLAYER/marine.png", Vector2i(34, 0), Vector2i(36, 55));
				sprA++;
				break;
			case 2:
				setSprite("DATA/TEXTURE/PLAYER/marine.png", Vector2i(70, 0), Vector2i(38, 55));
				sprA++;
				break;
			case 3:
				setSprite("DATA/TEXTURE/PLAYER/marine.png", Vector2i(108, 0), Vector2i(42, 55));
				sprA = 0;
				break;
			}
		}
		else
		{
			timeSprite++;
			if (timeSprite == 5)
				timeSprite = 0;
		}


		break;
	case 2: // -- D
		if (Keyboard::isKeyPressed(Keyboard::W)) { Bohater::updateSpriteDiagonally(2); return; }
		else if(Keyboard::isKeyPressed(Keyboard::S)) { Bohater::updateSpriteDiagonally(4); return; }
		sprW = sprS = sprA = 0;
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprD)
			{
			case 0:
				setSprite("DATA/TEXTURE/PLAYER/marine_reverse.png", Vector2i(0, 0), Vector2i(34, 55));
				sprD++;
				break;
			case 1:
				setSprite("DATA/TEXTURE/PLAYER/marine_reverse.png", Vector2i(34, 0), Vector2i(36, 55));
				sprD++;
				break;
			case 2:
				setSprite("DATA/TEXTURE/PLAYER/marine_reverse.png", Vector2i(70, 0), Vector2i(38, 55));
				sprD++;
				break;
			case 3:
				setSprite("DATA/TEXTURE/PLAYER/marine_reverse.png", Vector2i(108, 0), Vector2i(42, 55));
				sprD = 0;
				break;
			}
		}
		else
		{
			timeSprite++;
			if (timeSprite == 5)
				timeSprite = 0;
		}
		break;
	case 3: // - W
		if (Keyboard::isKeyPressed(Keyboard::A)) { Bohater::updateSpriteDiagonally(1); return; }
		else if(Keyboard::isKeyPressed(Keyboard::D)) { Bohater::updateSpriteDiagonally(2); return; }
		sprD = sprS = sprA = 0;
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprW)
			{
			case 0:
				setSprite("DATA/TEXTURE/PLAYER/marine_up.png", Vector2i(0, 0), Vector2i(34, 54));
				sprW++;
				break;
			case 1:
				setSprite("DATA/TEXTURE/PLAYER/marine_up.png", Vector2i(34, 0), Vector2i(35, 54));
				sprW++;
				break;
			case 2:
				setSprite("DATA/TEXTURE/PLAYER/marine_up.png", Vector2i(69, 0), Vector2i(35, 54));
				sprW++;
				break;
			case 3:
				setSprite("DATA/TEXTURE/PLAYER/marine_up.png", Vector2i(104, 4), Vector2i(36, 50));
				sprW = 0;
				break;
			}
		}
		else
		{
			timeSprite++;
			if (timeSprite == 5)
				timeSprite = 0;
		}
		break;
	case 4: // - S
		if (Keyboard::isKeyPressed(Keyboard::A)) { Bohater::updateSpriteDiagonally(3); return; }
		else if (Keyboard::isKeyPressed(Keyboard::D)) { Bohater::updateSpriteDiagonally(4); return; }
		sprD = sprW = sprA = 0;
		if (!timeSprite)
		{
			timeSprite++;
			switch (sprS)
			{
			case 0:
				setSprite("DATA/TEXTURE/PLAYER/marine_down.png", Vector2i(0, 0), Vector2i(41, 56));
				sprS++;
				break;
			case 1:
				setSprite("DATA/TEXTURE/PLAYER/marine_down.png", Vector2i(41, 0), Vector2i(37, 56));
				sprS++;
				break;
			case 2:
				setSprite("DATA/TEXTURE/PLAYER/marine_down.png", Vector2i(78, 0), Vector2i(38, 56));
				sprS++;
				break;
			case 3:
				setSprite("DATA/TEXTURE/PLAYER/marine_down.png", Vector2i(116, 0), Vector2i(40, 56));
				sprS = 0;
				break;
			}
		}
		else
		{
			timeSprite++;
			if (timeSprite == 5)
				timeSprite = 0;
		}
		break;
	default:
		break;
	}

}


// - move sprite diagonally
void Bohater::updateSpriteDiagonally(int spriteType)
{

	switch (spriteType)
	{
	case 1: // -- A + W
		sprDiagWD = sprDiagSA = sprDiagSD;
		if (!timeDiagSprite)
		{
			timeDiagSprite++;
			switch (sprDiagWA)
			{
			case 0:
				setSprite("DATA/TEXTURE/PLAYER/marine_W_A.png", Vector2i(0, 0), Vector2i(41, 55));
				sprDiagWA++;
				break;
			case 1:
				setSprite("DATA/TEXTURE/PLAYER/marine_W_A.png", Vector2i(42, 0), Vector2i(40, 54));
				sprDiagWA++;
				break;
			case 2:
				setSprite("DATA/TEXTURE/PLAYER/marine_W_A.png", Vector2i(82, 0), Vector2i(41, 54));
				sprDiagWA++;
				break;
			case 3:
				setSprite("DATA/TEXTURE/PLAYER/marine_W_A.png", Vector2i(123, 0), Vector2i(45, 51));
				sprDiagWA = 0;
				break;
			}
		}
		else
		{
			timeDiagSprite++;
			if (timeDiagSprite == 7)
				timeDiagSprite = 0;
		}


		break;
	case 2: // -- D + W
		sprDiagWA = sprDiagSA = sprDiagSD;
		if (!timeDiagSprite)
		{
			timeDiagSprite++;
			switch (sprDiagWD)
			{
			case 0:
				setSprite("DATA/TEXTURE/PLAYER/marine_W_D.png", Vector2i(0, 0), Vector2i(41, 55));
				sprDiagWD++;
				break;
			case 1:
				setSprite("DATA/TEXTURE/PLAYER/marine_W_D.png", Vector2i(41, 0), Vector2i(41, 54));
				sprDiagWD++;
				break;
			case 2:
				setSprite("DATA/TEXTURE/PLAYER/marine_W_D.png", Vector2i(82, 0), Vector2i(41, 54));
				sprDiagWD++;
				break;
			case 3:
				setSprite("DATA/TEXTURE/PLAYER/marine_W_D.png", Vector2i(123, 0), Vector2i(45, 51));
				sprDiagWD = 0;
				break;
			}
		}
		else
		{
			timeDiagSprite++;
			if (timeDiagSprite == 7)
				timeDiagSprite = 0;
		}
		break;
	case 3: // A + S
		sprDiagWA = sprDiagWD = sprDiagSD;
		if (!timeDiagSprite)
		{
			timeDiagSprite++;
			switch (sprDiagSA)
			{
			case 0:
				setSprite("DATA/TEXTURE/PLAYER/marine_S_A.png", Vector2i(0, 0), Vector2i(35, 54));
				sprDiagSA++;
				break;
			case 1:
				setSprite("DATA/TEXTURE/PLAYER/marine_S_A.png", Vector2i(35, 0), Vector2i(35, 54));
				sprDiagSA++;
				break;
			case 2:
				setSprite("DATA/TEXTURE/PLAYER/marine_S_A.png", Vector2i(70, 0), Vector2i(37, 55));
				sprDiagSA++;
				break;
			case 3:
				setSprite("DATA/TEXTURE/PLAYER/marine_S_A.png", Vector2i(107, 4), Vector2i(34, 55));
				sprDiagSA = 0;
				break;
			}
		}
		else
		{
			timeDiagSprite++;
			if (timeDiagSprite == 7)
				timeDiagSprite = 0;
		}
		break;
	case 4: // - D + S
		sprDiagWA = sprDiagWD = sprDiagSA;
		if (!timeDiagSprite)
		{
			timeDiagSprite++;
			switch (sprDiagSD)
			{
			case 0:
				setSprite("DATA/TEXTURE/PLAYER/marine_S_D.png", Vector2i(0, 0), Vector2i(35, 54));
				sprDiagSD++;
				break;
			case 1:
				setSprite("DATA/TEXTURE/PLAYER/marine_S_D.png", Vector2i(35, 0), Vector2i(35, 54));
				sprDiagSD++;
				break;
			case 2:
				setSprite("DATA/TEXTURE/PLAYER/marine_S_D.png", Vector2i(70, 0), Vector2i(37, 55));
				sprDiagSD++;
				break;
			case 3:
				setSprite("DATA/TEXTURE/PLAYER/marine_S_D.png", Vector2i(107, 4), Vector2i(34, 55));
				sprDiagSD = 0;
				break;
			}
		}
		else
		{
			timeDiagSprite++;
			if (timeDiagSprite == 7)
				timeDiagSprite = 0;
		}
		break;
	default:
		break;
	}

}