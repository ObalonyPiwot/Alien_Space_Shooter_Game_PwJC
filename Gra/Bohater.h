#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

class Bohater : public Drawable
{
public:
	Bohater(float p_X, float p_Y);
	~Bohater() = default;
	//krawedzie bohatera
	float top();
	float bottom();
	float left();
	float right();
	void collision(int a);
	void ruch(int a);
	void predkosci(float a);
	void setWeapon(int a);
	float postac_predkosc = 1.0;
	Vector2f getPosition();
	void setPosition(float p_X, float p_Y);
	// - sprite'y 
	void updateSprite(int spriteType);
	void updateSpriteDiagonally(int spriteType);
	void setSprite(const string& tileset, Vector2i startSprite, Vector2i endSprite);

	// - shoot sound play
	void play_Shoot();

	int weapon = 0;
	int firingspeed = 10;
	int shotspeed = 3;
	int damage = 1;
	int hp = 5;
private:
	RectangleShape shape;
	const float postac_rozm = 30.0;


	//ruch bohatera
	Vector2f ruchW{ 0, -postac_predkosc };
	Vector2f ruchA{ -postac_predkosc, 0 };
	Vector2f ruchS{ 0, postac_predkosc };
	Vector2f ruchD{ postac_predkosc, 0 };

	//rysowanie postaci
	void draw(RenderTarget& target, RenderStates state) const override;

	// tekstura sprite'a 
	Texture texture;

	// odglosy strzalu
	SoundBuffer buffer;
	Sound sound;

	// - ruch sprite'a
	int sprW = 0, sprA = 0, sprS = 0, sprD = 0;
	int sprDiagWA = 0, sprDiagWD = 0, sprDiagSA = 0, sprDiagSD = 0;
	int timeSprite = 0, timeDiagSprite = 0;
};

