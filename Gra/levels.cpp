#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
using namespace std;
using namespace sf;

vector<Enemy> level1_enemy(vector<Enemy> enemyVec)
{
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 500 * i, 100, 8);
        newEnemy.setType(1);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 500 * i, 500, 8);
        newEnemy.setType(2);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(150 + 500 * i, 500, 5);
        newEnemy.setType(3);
        enemyVec.push_back(newEnemy);
    }
    return enemyVec;
}
vector<Sciany> level1_wall(vector<Sciany> wallVec)
{
    Sciany newWall(400, 300, 20, 300, 1);
    wallVec.push_back(newWall);
    Sciany newWall1(400, 300, 300, 20, 1);
    wallVec.push_back(newWall1);
    Sciany newWall2(100, 300, 20, 300, 2);
    wallVec.push_back(newWall2);
    Sciany newWall3(700, 300, 20, 300, 1);
    wallVec.push_back(newWall3);
    return wallVec;
}

vector<Enemy> level2_enemy(vector<Enemy> enemyVec)
{
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 150 * i, 100, 8);
        newEnemy.setType(1);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 100 * i, 500, 8);
        newEnemy.setType(2);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 3; i++)
    {
        Enemy newEnemy(150 + 200 * i, 200, 5);
        newEnemy.setType(3);
        enemyVec.push_back(newEnemy);
    }
    return enemyVec;
}
vector<Sciany> level2_wall(vector<Sciany> wallVec)
{
    Sciany newWall(400, 100, 20, 300, 1);
    wallVec.push_back(newWall);
    Sciany newWall1(400, 500, 20, 300, 1);
    wallVec.push_back(newWall1);
    Sciany newWall2(100, 300, 20, 300, 1);
    wallVec.push_back(newWall2);
    Sciany newWall3(700, 300, 20, 300, 1);
    wallVec.push_back(newWall3);
    return wallVec;
}

vector<Enemy> level3_enemy(vector<Enemy> enemyVec)
{
    for (int i = 0; i < 5; i++)
    {
        Enemy newEnemy(50 * rand() % 10, 100, 8);
        newEnemy.setType(1);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 5; i++)
    {
        Enemy newEnemy(100 + 100 * i, 500, 8);
        newEnemy.setType(2);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 5; i++)
    {
        Enemy newEnemy(150 + 200 * i, 200, 5);
        newEnemy.setType(3);
        enemyVec.push_back(newEnemy);
    }
    return enemyVec;
}
vector<Sciany> level3_wall(vector<Sciany> wallVec)
{
    Sciany newWall(100, 50, 20, 100, 1);
    newWall.setLava();
    wallVec.push_back(newWall);
    Sciany newWall1(400, 50, 20, 100, 1);
    wallVec.push_back(newWall1);
    Sciany newWall2(150, 100, 100, 20, 1);
    wallVec.push_back(newWall2);
    return wallVec;
}
