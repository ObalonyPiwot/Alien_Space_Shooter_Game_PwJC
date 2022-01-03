#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
using namespace sf;

class Item : public Drawable
{
public:
	Item(float p_X, float p_Y);
	~Item() = default;

	void setPosition(float p_X, float p_Y);
	Vector2f getPosition();

	float damage = 1;
	float shot_speed = 3;
	float fire_rate = 10;
	int luck = 1;

	int grab();
	void processFile(ifstream& inFile);
	void openFile(ifstream& inFile, string fname);

	void wepon1();
	void wepon2();
	void wepon3();

	//getter
	inline const float& getdamage() { return this->damage; }
	inline const float& getshot() { return this->shot_speed; }
	inline const float& getfire() { return this->fire_rate; }
	inline const int& getluck() { return this->luck; }
	//setter
	inline void setdamage(float damage) { this->damage = damage; }
	inline void setshot(float shot) { this->shot_speed = shot; }
	inline void setfire(float fire) { this->fire_rate = fire; }
	inline void setluck(int luck) { this->luck = luck; }
	//addter
	inline void adddamage(float damage) { this->damage += damage; }
	inline void addshot(float shot) { this->shot_speed += shot; if (shot_speed > 20) { shot_speed = 20; }; }
	inline void addfire(float fire) { this->fire_rate -= fire; if (fire_rate < 1) { fire_rate = 1; }; }
	inline void addluck(int luck) { this->luck += luck; if (luck > 10) { luck = 10; }; }

private:
	RectangleShape shape;
	const float item_rozm = 10.0;
	void drawItem(RenderWindow& target);
	void draw(RenderTarget& target, RenderStates state) const override;
};
