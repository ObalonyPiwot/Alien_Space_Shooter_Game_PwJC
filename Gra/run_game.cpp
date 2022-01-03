#include "run_game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bohater.h"
#include "sciany.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Levels.h"
#include "map.h"

using namespace std;
using namespace sf;

template <class T1, class T2> bool Overdrawing(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

template <class T1, class T2> bool Collision(T1& A, T2& bohater)
{
    if (!Overdrawing(A, bohater))
        return false;
    if (bohater.getPosition().y < A.top())
        bohater.collision(1);
    if (bohater.getPosition().x < A.left())
        bohater.collision(2);
    if (bohater.getPosition().y > A.bottom())
        bohater.collision(3);
    if (bohater.getPosition().x > A.right())
        bohater.collision(4);
    return true;
}

void death()
{
    SoundBuffer buffer;
    Sound sound;
    if (!buffer.loadFromFile("DATA/SOUND/SAMPLES/click.wav"))
        cout << "samples error ";
    sound.setBuffer(buffer);
    sound.play();
}

vector<Bullet> enemyShot(Bohater bohater, Enemy enemy, vector<Bullet> bulletVec)
{
    if (enemy.getPosition().y >= bohater.getPosition().y - 10 && enemy.getPosition().y <= bohater.getPosition().y + 10)
    {
        if (enemy.getPosition().x < bohater.getPosition().x)
        {
            Bullet newBullet(2, 'D');
            newBullet.setPos(Vector2f(enemy.getPosition().x + 5, enemy.getPosition().y));
            bulletVec.push_back(newBullet);
            return bulletVec;
        }
        if (enemy.getPosition().x > bohater.getPosition().x)
        {
            Bullet newBullet(2, 'A');
            newBullet.setPos(Vector2f(enemy.getPosition().x - 5, enemy.getPosition().y));
            bulletVec.push_back(newBullet);
            return bulletVec;
        }
    }
    if ((enemy.getPosition().x >= bohater.getPosition().x - 10 && enemy.getPosition().x <= bohater.getPosition().x + 10))
    {
        if (enemy.getPosition().y < bohater.getPosition().y)
        {
            Bullet newBullet(2, 'S');
            newBullet.setPos(Vector2f(enemy.getPosition().x, enemy.getPosition().y + 5));
            bulletVec.push_back(newBullet);
            return bulletVec;
        }
        if (enemy.getPosition().y > bohater.getPosition().y)
        {
            Bullet newBullet(2, 'W');
            newBullet.setPos(Vector2f(enemy.getPosition().x, enemy.getPosition().y - 5));
            bulletVec.push_back(newBullet);
            return bulletVec;
        }
    }
    return bulletVec;
}

void runGame()
{
    int level[] =
    {
        0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0
    };

    TileMap map;
    if (!map.load("DATA/TEXTURE/FLOOR/floorLvl1.png", Vector2u(80, 60), level, 10, 10))
        cout << "nie wczytano";

    // - bohater

    Bohater bohater(15, 300);
    RectangleShape exit;
    exit.setPosition(350, 550);
    exit.setSize(Vector2f(100, 50));
    exit.setFillColor(Color(128, 128, 128));
    RenderWindow window(VideoMode(800, 600), "Gra");
    window.setFramerateLimit(60);
    Event event;
    vector<Bullet> bulletVec;
    vector<Enemy> enemyVec;
    vector<Sciany> wallVec;
    Font font;
    if (!font.loadFromFile("DATA/FONT/arial.ttf"))
        printf("Blad");
    Text text;
    text.setFont(font);
    text.setString("PAUZA");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(335, 270);
    enemyVec = level1_enemy(enemyVec);
    wallVec = level1_wall(wallVec);
    // - texturowanie scian
    for (int i = 0; i < wallVec.size(); i++)
        wallVec[i].setTexture();

    int curLevel = 0;
    bool isFiring = false;
    char direction[1];
    int shot = 0;
    int pauza = 0, pauseTime = 10;
    bohater.predkosci(10);
    //bohater.postac_predkosc = 10.0;


    // - petla gry 

    while (window.isOpen())
    {
        if (pauseTime)
            pauseTime--;
        window.clear();
        window.draw(map);
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                break;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && pauseTime == 0)
        {
            if (pauza == 0)
                pauza = 1;
            else
                pauza = 0;
            pauseTime = 10;
        }
        if (!pauza)
        {
            if (enemyVec.size() == 0)
            {
                window.draw(exit);
                if (bohater.getPosition().x >= exit.getPosition().x && bohater.getPosition().x <= exit.getPosition().x + exit.getSize().x &&
                    bohater.getPosition().y >= exit.getPosition().y && bohater.getPosition().x <= exit.getPosition().y + exit.getSize().y /*&& bohater.weapon != 0*/)
                {
                    while (wallVec.size() > 0)
                        wallVec.erase(wallVec.begin());
                    curLevel++;
                    if (curLevel == 1)
                    {
                        enemyVec = level1_enemy(enemyVec);
                        wallVec = level1_wall(wallVec);
                        bohater.setPosition(15, 300);
                    }
                    if (curLevel == 2)
                    {
                        enemyVec = level2_enemy(enemyVec);
                        wallVec = level2_wall(wallVec);
                        bohater.setPosition(15, 300);
                    }
                    if (curLevel == 3)
                    {
                        enemyVec = level3_enemy(enemyVec);
                        wallVec = level3_wall(wallVec);
                        bohater.setPosition(15, 300);
                    }
                    if (curLevel == 4)
                    {
                        enemyVec = level4_enemy(enemyVec);
                        wallVec = level4_wall(wallVec);
                        bohater.setPosition(15, 300);
                    }
                    if (curLevel == 5)
                    {
                        //enemyVec = level5_enemy(enemyVec);
                        wallVec = level5_wall(wallVec);
                        bohater.setPosition(15, 300);
                    }
                }
            }

            // - ruch  pocisku
            if (shot == 0)
            {
                if (Keyboard::isKeyPressed(Keyboard::Left)) { isFiring = true; direction[0] = 'A'; }
                if (Keyboard::isKeyPressed(Keyboard::Right)) { isFiring = true; direction[0] = 'D'; }
                if (Keyboard::isKeyPressed(Keyboard::Up)) { isFiring = true; direction[0] = 'W'; }
                if (Keyboard::isKeyPressed(Keyboard::Down)) { isFiring = true; direction[0] = 'S'; }
            }
            // - ruch bohatera
            if (!(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::A)
                || Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::D))) {
                bohater.updateSprite(0);
            }
            if (Keyboard::isKeyPressed(Keyboard::W)) { bohater.ruch(1); } //bohater.updateSprite(1);  }
            if (Keyboard::isKeyPressed(Keyboard::A)) { bohater.ruch(2);  bohater.updateSprite(1); }
            if (Keyboard::isKeyPressed(Keyboard::S)) { bohater.ruch(3); }// bohater.updateSprite(3); }
            if (Keyboard::isKeyPressed(Keyboard::D)) { bohater.ruch(4);  bohater.updateSprite(2); }

            for (int i = 0; i < wallVec.size(); i++)
                Collision(wallVec[i], bohater);
            for (int i = 0; i < bulletVec.size(); i++)
                for (int j = 0; j < wallVec.size(); j++)
                    if (Overdrawing(bulletVec.at(i), wallVec[j]))
                    {
                        bulletVec.erase(bulletVec.begin() + i);
                        j = 100;
                    }
            for (int i = 0; i < bulletVec.size(); i++)
                for (int x = 0; x < enemyVec.size(); x++)
                    if (Overdrawing(bulletVec.at(i), enemyVec.at(x)))
                    {
                        enemyVec[x].HP = enemyVec[x].HP - bohater.damage;
                        bulletVec.erase(bulletVec.begin() + i);
                        x = 100;
                    }

            window.draw(bohater);
            for (int i = 0; i < (int)enemyVec.size(); i++)
                if (enemyVec[i].HP <= 0)
                {
                    enemyVec.erase(enemyVec.begin() + i);
                }

            for (int i = 0; i < enemyVec.size(); i++)
            {
                enemyVec[i].ruch(bohater.getPosition().x, bohater.getPosition().y);
                for (int j = 0; j < wallVec.size(); j++)
                    if (enemyVec[i].type != 3 && wallVec[j].lava == 0)
                        Collision(wallVec[j], enemyVec[i]);
                if (enemyVec[i].type == 2 && enemyVec[i].canShot())
                    bulletVec = enemyShot(bohater, enemyVec[i], bulletVec);
            }

            if (isFiring == true && shot == 0) {
                Bullet newBullet(2, direction[0]);
                newBullet.setPos(Vector2f(bohater.getPosition().x, bohater.getPosition().y));
                bulletVec.push_back(newBullet);
                isFiring = false;
                shot = bohater.firingspeed;//firing speeed
                bohater.play_Shoot();
            }
            if (shot > 0)
                shot--;
            for (int i = 0; i < (int)bulletVec.size(); i++) {
                for (int j = 0; j < bohater.shotspeed; j++)
                {
                    switch (bulletVec[i].getDir())
                    {
                    case 'A':
                        bulletVec[i].fire(Vector2f(-1, 0));
                        break;
                    case 'D':
                        bulletVec[i].fire(Vector2f(1, 0));
                        break;
                    case 'W':
                        bulletVec[i].fire(Vector2f(0, -1));
                        break;
                    case 'S':
                        bulletVec[i].fire(Vector2f(0, 1));
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < wallVec.size(); i++)
            window.draw(wallVec[i]);
        for (int i = 0; i < (int)bulletVec.size(); i++)
            bulletVec[i].draw(window);
        for (int i = 0; i < enemyVec.size(); i++)
            enemyVec[i].drawEnemy(window);
        window.draw(bohater);
        if (pauza)
            window.draw(text);
        window.display();
    }
}