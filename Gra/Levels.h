#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
using namespace std;
using namespace sf;

vector<Enemy> level1_enemy(vector<Enemy> enemyVec)
{
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 500 * i, 100, 8, 1);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 500 * i, 500, 8, 2);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(150 + 500 * i, 500, 5, 3);
        enemyVec.push_back(newEnemy);
    }
    return enemyVec;
}
vector<Sciany> level1_wall(vector<Sciany> wallVec)
{
    Sciany newWall(400, 300, 20, 300, 1, 0);
    wallVec.push_back(newWall);
    Sciany newWall1(400, 300, 300, 20, 1, 0);
    wallVec.push_back(newWall1);
    Sciany newWall2(100, 300, 20, 300, 1, 0);
    wallVec.push_back(newWall2);
    Sciany newWall3(700, 300, 20, 300, 1, 0);
    wallVec.push_back(newWall3);
    return wallVec;
}
/////////////////////////////////////////////////////
vector<Enemy> level2_enemy(vector<Enemy> enemyVec)
{
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 150 * i, 100, 8, 1);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 100 * i, 500, 8, 2);
        enemyVec.push_back(newEnemy);
    }
    for (int i = 0; i < 3; i++)
    {
        Enemy newEnemy(150 + 200 * i, 200, 5, 3);
        enemyVec.push_back(newEnemy);
    }
    return enemyVec;
}
vector<Sciany> level2_wall(vector<Sciany> wallVec)
{
    Sciany newWall(400, 100, 20, 300, 1, 0);
    wallVec.push_back(newWall);
    Sciany newWall1(400, 500, 20, 300, 1, 0);
    wallVec.push_back(newWall1);
    Sciany newWall2(100, 300, 20, 300, 1, 0);
    wallVec.push_back(newWall2);
    Sciany newWall3(700, 300, 20, 300, 1, 0);
    wallVec.push_back(newWall3);
    return wallVec;
}
/////////////////////////////////////////////////////
vector<Enemy> level3_enemy(vector<Enemy> enemyVec)
{
    Enemy newEnemy(50, 150, 8, 1);
    Enemy newEnemy1(75, 100, 8, 1);
    Enemy newEnemy2(100, 150, 8, 1);
    Enemy newEnemy3(350, 25, 8, 1);
    Enemy newEnemy4(550, 75, 8, 1);
    enemyVec.push_back(newEnemy);
    enemyVec.push_back(newEnemy1);
    enemyVec.push_back(newEnemy2);
    enemyVec.push_back(newEnemy3);
    enemyVec.push_back(newEnemy4);
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(650 + 100 * i, 200, 8, 1);
        Enemy newEnemy1(650 + 100 * i, 300, 8, 1);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(350 + 100 * i, 200, 8, 1);
        Enemy newEnemy1(350 + 100 * i, 300, 8, 1);
        Enemy newEnemy2(350 + 100 * i, 500, 8, 1);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(200 + 50 * i, 150 + 250 * i, 8, 2);
        Enemy newEnemy1(250 + 50 * i, 250 + 250 * i, 8, 2);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 3; i++)
    {
        Enemy newEnemy(50, 575 - 50 * i, 8, 3);
        Enemy newEnemy1(100, 575 - 50 * i, 8, 3);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    return enemyVec;
}

vector<Sciany> level3_wall(vector<Sciany> wallVec)
{
    Sciany newWall(75, 450, 150, 20, 1, 0);
    wallVec.push_back(newWall);
    Sciany newWall1(150, 350, 20, 520, 1, 0);
    wallVec.push_back(newWall1);
    Sciany newWall2(375, 100, 450, 20, 1, 0);
    wallVec.push_back(newWall2);
    Sciany newWall3(300, 200, 20, 200, 1, 0);
    wallVec.push_back(newWall3);
    Sciany newWall4(400, 500, 20, 200, 1, 0);
    wallVec.push_back(newWall4);
    Sciany newWall5(600, 215, 20, 250, 1, 0);
    wallVec.push_back(newWall5);
    Sciany newWall6(600, 500, 20, 200, 1, 0);
    wallVec.push_back(newWall6);
    Sciany newWall7(300, 25, 20, 50, 1, 0);
    wallVec.push_back(newWall7);
    Sciany newWall8(500, 75, 20, 50, 1, 0);
    wallVec.push_back(newWall8);
    return wallVec;
}
/////////////////////////////////////////////////////
vector<Sciany> level4_wall(vector<Sciany> wallVec)
{
    Sciany newWall(125, 450, 250, 20, 1, 0);
    wallVec.push_back(newWall);
    Sciany newWall1(75, 200, 150, 20, 1, 0);
    wallVec.push_back(newWall1);
    Sciany newWall2(150, 100, 20, 220, 1, 0);
    wallVec.push_back(newWall2);
    Sciany newWall3(300, 125, 20, 250, 1, 0);
    wallVec.push_back(newWall3);
    Sciany newWall4(500, 200, 20, 400, 1, 0);
    wallVec.push_back(newWall4);
    Sciany newWall5(600, 250, 200, 20, 1, 0);
    wallVec.push_back(newWall5);
    return wallVec;
}

vector<Enemy> level4_enemy(vector<Enemy> enemyVec)
{
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(200 + 50 * i, 150, 8, 1);
        Enemy newEnemy1(200 + 50 * i, 50, 8, 2);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 3; i++)
    {
        Enemy newEnemy(350 + 50 * i, 150, 8, 1);
        Enemy newEnemy1(350 + 50 * i, 50, 8, 2);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(50 + 50 * i, 150, 8, 3);
        Enemy newEnemy1(100 + 50 * i, 50, 8, 3);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 3; i++)
    {
        Enemy newEnemy(550 + 50 * i, 100, 8, 1);
        Enemy newEnemy1(550 + 50 * i, 200, 8, 1);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100 + 100 * i, 550, 8, 2);
        enemyVec.push_back(newEnemy);
    }
    return enemyVec;
}
////////////////////////////////////////////////// 
vector<Sciany> level5_wall(vector<Sciany> wallVec)
{
    Sciany newWall(400, 300, 100, 100, 1, 0);
    wallVec.push_back(newWall);
    Sciany newWall1(150, 200, 300, 20, 1, 0);
    wallVec.push_back(newWall1);
    Sciany newWall2(650, 200, 300, 20, 1, 0);
    wallVec.push_back(newWall2);
    Sciany newWall3(150, 400, 300, 20, 1, 0);
    wallVec.push_back(newWall3);
    Sciany newWall4(650, 400, 300, 20, 1, 0);
    wallVec.push_back(newWall4);
    Sciany newWall5(300, 150, 20, 120, 1, 0);
    wallVec.push_back(newWall5);
    Sciany newWall6(500, 150, 20, 120, 1, 0);
    wallVec.push_back(newWall6);
    Sciany newWall7(300, 450, 20, 120, 1, 0);
    wallVec.push_back(newWall7);
    Sciany newWall8(500, 450, 20, 120, 1, 0);
    wallVec.push_back(newWall8);
    Sciany newWall9(200, 300, 50, 120, 1, 2);
    wallVec.push_back(newWall9);
    Sciany newWall10(400, 175, 100, 50, 1, 2);
    wallVec.push_back(newWall10);
    Sciany newWall11(400, 475, 100, 50, 1, 2);
    wallVec.push_back(newWall11);
    return wallVec;
}

vector<Enemy> level5_enemy(vector<Enemy> enemyVec)
{
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100, 50 + 50 * i, 8, 1);
        Enemy newEnemy1(50, 50 + 50 * i, 8, 2);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(100, 500 + 50 * i, 8, 1);
        Enemy newEnemy1(50, 500 + 50 * i, 8, 2);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(500, 50 + 50 * i, 8, 1);
        Enemy newEnemy1(550, 50 + 50 * i, 8, 2);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    for (int i = 0; i < 2; i++)
    {
        Enemy newEnemy(500, 500 + 50 * i, 8, 1);
        Enemy newEnemy1(550, 500 + 50 * i, 8, 2);
        enemyVec.push_back(newEnemy);
        enemyVec.push_back(newEnemy1);
    }
    return enemyVec;
}

////////////////////////////////////////////////// 
vector<Sciany> level6_wall(vector<Sciany> wallVec)
{
    Sciany newWall(150, 175, 20, 150, 1, 0);
    wallVec.push_back(newWall);
    Sciany newWall1(250, 250, 200, 20, 1, 0);
    wallVec.push_back(newWall1);
    Sciany newWall2(350, 350, 20, 200, 1, 0);
    wallVec.push_back(newWall2);
    Sciany newWall3(550, 325, 20, 250, 1, 0);
    wallVec.push_back(newWall3);
    Sciany newWall4(525, 450, 650, 20, 1, 0);
    wallVec.push_back(newWall4);
    for (int i = 0; i < 3; i++)
    {
        Sciany newWall(225 + 200 * i, 475, 30, 30, 2, 1);
        wallVec.push_back(newWall);
        Sciany newWall1(325 + 200 * i, 530, 30, 30, 2, 1);
        wallVec.push_back(newWall1);
        Sciany newWall2(225 + 200 * i, 585, 30, 30, 2, 1);
        wallVec.push_back(newWall2);
    }
    return wallVec;
}