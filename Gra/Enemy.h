#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

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
private:
	RectangleShape shape;
	float enemy_rozm = 10.0;
	float postac_predkosc = 0.75;
	unsigned int shot = 15;

	//ruch bohatera
	Vector2f ruchW{ 0, -postac_predkosc };
	Vector2f ruchA{ -postac_predkosc, 0 };
	Vector2f ruchS{ 0, postac_predkosc };
	Vector2f ruchD{ postac_predkosc, 0 };
};


