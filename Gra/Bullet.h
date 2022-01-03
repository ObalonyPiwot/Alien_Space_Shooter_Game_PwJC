#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Bullet
{
public:
    int mybullet = 0;
    Bullet(int size, char dir)
    {
        bullet.setSize(Vector2f(size,size));
        bullet.setOrigin(size / 2, size / 2);
        bullet.setFillColor(Color::White);
        direction[0] = dir;
    }
    void fire(Vector2f speed)
    {
        bullet.move(Vector2f(speed));
    }
    int right()
    {
        return bullet.getPosition().x + bullet.getSize().x / 2;
    }

    int left()
    {
        return bullet.getPosition().x - bullet.getSize().x / 2;
    }

    int top()
    {
        return bullet.getPosition().y - bullet.getSize().y / 2;
    }

    int bottom()
    {
        return bullet.getPosition().y + bullet.getSize().y / 2;
    }

    void draw(RenderWindow& window)
    {
        if (bullet.getPosition().x > 0 or bullet.getPosition().x < 800 or bullet.getPosition().y > 0 or bullet.getPosition().x < 600)
            window.draw(bullet);
    }

    float pos_x()
    {
        return bullet.getPosition().x;
    }

    float pos_y()
    {
        return bullet.getPosition().y;
    }

    void setPos(Vector2f newPos)
    {
        bullet.setPosition(newPos);
    }
    char getDir()
    {
        return direction[0];
    }
private:
    // - wielkosc pocisku
    RectangleShape bullet;

    // - kierunek pocisku
    char direction[1];
};

