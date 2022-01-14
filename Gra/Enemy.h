#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

#define NUMBER_OF_MOVE_SPRITE 10

class Enemy
{
public:
	Enemy(float p_X, float p_Y, int hp, int type);
	//krawedzie wroga
	float top();
	float bottom();
	float left();
	float right();
	void collision(int a);
	void ruch(int x, int y);
	Vector2f getPosition();
	void setType(int a);
	int HP = 0;
	void drawEnemy(RenderWindow& target);
	int type; //1 wojownik 2 strzelec 3 duch
	int canShot();
	void setBoss();
	void boss_ruch();
	int boss = 0;
	// - sprite'y 
	void updateSprite(int spriteType);
	void setSprite( Vector2i startSprite, Vector2i endSprite, int direction);
	
private:
	RectangleShape shape;
	float enemy_rozm = 30.0;
	float postac_predkosc = 0.55;
	unsigned int shot = 15;
	int boss_change_dir = 0;

	//ruch przeciwnika
	Vector2f ruchW{ 0, -postac_predkosc };
	Vector2f ruchA{ -postac_predkosc, 0 };
	Vector2f ruchS{ 0, postac_predkosc };
	Vector2f ruchD{ postac_predkosc, 0 };

	// tekstura sprite'a 
	Texture texture;

	// - ruch sprite'a
	int sprW = 0, sprA = 0, sprS = 0, sprD = 0;
	int sprDiagWA = 0, sprDiagWD = 0, sprDiagSA = 0, sprDiagSD = 0;
	int timeSprite = 0, timeDiagSprite = 0;
};


