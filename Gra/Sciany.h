#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Sciany : public Drawable
{
public:
	Sciany(float p_x, float p_y, float a, float b, int type, int lava);
	~Sciany() = default;
	//krawedzie sciany
	float top();
	float bottom();
	float left();
	float right();
	Vector2f getPosition();
	void setTexture();
	void setLava();
	int lava; // - 1 gdy sciana jest lava
protected:
	RectangleShape shape;
	int wType; // - typ sciany, sluzy do wybrania teksury
	Texture wTexture; // - tekstura sciany
	void draw(RenderTarget& target, RenderStates state) const override;
};

