//
// Created by Hoa Tran
//
#pragma once

#ifndef SFML_CHARACTER_H
#define SFML_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "LoadAnimation.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

#define PI 3.14159265

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN BIRD

class MainBird
{
private:
    sf::Texture     texttureTemp;

    Animation       animated;

    int             w_widthTemp;			//WINDOW_WIDTH
    int             w_heightTemp;		    //WINDOW_HEIGHT
    int             middle_Y;

public:
    //MainBird's status
    bool            alive = true;
    float           angleMainBird = 0;
    const double    angleSpeed = 9;
    const double    angleMax = 60;
    float           posMainBirdX;
    float           posMainBirdY;
    float           speedMove = 9;
    int             health = 100;

    /////////////////////////// FUNCTION ///////////////////////////

    void setupInformationForMainBird(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows,
                                     int width, int height, float speed, int count_In_Rows, int count_In_Cols,
                                     int w_width, int w_height, Animation * animated);

    void displayMainBird();

    void controlMainBird();

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SECOND BIRD

class SecondBird
{
private:
    sf::Texture     texttureTemp;

    Animation       animated;

    int             w_widthTemp;			//WINDOW_WIDTH
    int             w_heightTemp;		    //WINDOW_HEIGHT
    int             middle_Y;

public:
    //SecondBird's status
    bool            alive = true;
    float           angleSecondBird = 0;
    const double    angleSpeed = 9;
    const double    angleMax = 60;
    float           posSecondBirdX;
    float           posSecondBirdY;
    float           speedMove = 13;

    /////////////////////////// FUNCTION ///////////////////////////

    void setupInformationForSecondBird(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows,
                                       int width, int height, float speed, int count_In_Rows, int count_In_Cols,
                                       int w_width, int w_height, Animation * animated);

    void displaySecondBird();

    void controlSecondBird();

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ENEMY

class Enemy
{
private:
    sf::Texture texttureTemp;

    Animation   animated;

    int         w_widthTemp;			//WINDOW_WIDTH
    int         w_heightTemp;		    //WINDOW_HEIGHT
    int         middle_Y;
    int         width;

public:
    //Enemy's status
    float       angleEnemy = 0;
    float       posEnemyX;
    float       posEnemyY;
    float       speedMove;

    /////////////////////////// FUNCTION ///////////////////////////

    void setupEnemy(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows, int width, int height,
                    float speed, int count_In_Rows, int count_In_Cols, int w_width, int w_height, Animation * animated);

    void displayEnemy();

    void EnemyMove();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DIAMOND

class Diamond
{
private:

    Animation   animated;

    int         w_widthTemp;			//WINDOW_WIDTH
    int         w_heightTemp;		    //WINDOW_HEIGHT
    int         middle_Y;
    int         width;

public:
    //Diamond's status
    float       angleDiamond = 0;
    float       posDiamondX;
    float       posDiamondY;
    float       speedMove;

    /////////////////////////// FUNCTION ///////////////////////////

    void setupDiamond(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows, int width,
                      int height, float speed, int count_In_Rows, int count_In_Cols, int w_width, int w_height,
                      Animation * animated);

    void displayDiamond();

    void DiamondMove();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ROCKET

class Rocket
{
private:
    sf::Texture texttureTemp;

    Animation   animated;

    int         w_widthTemp;			//WINDOW_WIDTH
    int         w_heightTemp;		    //WINDOW_HEIGHT
    int         middle_Y;
    int         width;

public:
    //Rocket's status
    float       angleRocket = 0;
    float       angleSpeed = 3;
    float       posRocketX;
    float       posRocketY;
    float       speedMove = 30;

    /////////////////////////// FUNCTION ///////////////////////////

    void setupRocket(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows, int width, int height,
                     float speed, int count_In_Rows, int count_In_Cols, int w_width, int w_height, Animation * animated);

    void displayRocket();

    void RocketCatchSecond(float second_X, float second_Y, float second_Speed, bool second_Alive);

    void RocketMove(float main_X, float main_Y, float main_Speed, bool main_Alive);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//COLLAPSION

class Collapsion
{
private:
    sf::Texture         textureCollapsion;
    sf::Texture         textureEatDiamond;

    Animation   animated;

    float       pos_X_Collapsion;
    float       pos_Y_Collapsion;

    bool        checkDraw = false;

public:
    //Constructor
    Collapsion(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows, int width, int height,
               float speed, int count_In_Rows, int count_In_Cols, int w_width, int w_height, Animation * animated,
               float pos_X, float pos_Y);

    bool displayCollapsion(int count_In_Rows, int count_In_Cols);

};

/////////////////////////////////// OUTSIDE CLASS FUNCTION ///////////////////////////////

bool collapsion(float pos_First_X, float pos_First_Y, float scale_First, float width_First, float height_First,
                float pos_Second_X, float pos_Second_Y, float scale_Second, float width_Second, float height_Second);

bool CheckCollapsionWithEnemySecond(SecondBird SecondBird, std::vector<Enemy> Enemys, float scale_First,
                                    float width_First, float height_First, float scale_Second, float width_Second,
                                    float height_Second);

bool CheckCollapsionEnemyWithMain(MainBird MainBird, Enemy enemy, float scale_First, float width_First,
                                  float height_First, float scale_Second, float width_Second, float height_Second);

bool CheckCollapsionDiamondWithSecond(SecondBird SecondBird, Diamond Diamond, float scale_First, float width_First,
                                      float height_First, float scale_Second, float width_Second, float height_Second);

bool CheckCollapsionRocketWithSecond(SecondBird SecondBird, Rocket Rocket, float scale_First, float width_First,
                                     float height_First, float scale_Second, float width_Second, float height_Second);

bool CheckCollapsionRocketWithMain(MainBird MainBird, Rocket Rocket, float scale_First, float width_First,
                                   float height_First, float scale_Second, float width_Second, float height_Second);

#endif //SFML_CHARACTER_H
