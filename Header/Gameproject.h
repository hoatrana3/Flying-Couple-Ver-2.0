//
// Created by Hoa Tran
//
#pragma once

#ifndef SFML_GAMEPROJECT_H
#define SFML_GAMEPROJECT_H

#include <SFML/Graphics.hpp>
#include "ControlGame.h"

//WINDOW'S WIDTH AND HEIGHT
#define WINDOW_WIDTH			1920
#define WINDOW_HEIGHT			1000
#define FRAMES                  60
#define CHANGE_HEALTH_TOUCH_ENEMY   3
#define CHANGE_HEALTH_TOUCH_ROCKET  30
#define CHANGE_HEALTH_TOUCH_DIAMOND 5

class Gameproject
{
private:

    sf::RenderWindow    window;
    sf::Event           getEvent;

    sf::Texture         textureMainBird;
    sf::Texture         textureSecondBird;
    sf::Texture         textureEnemy;
    sf::Texture         textureDiamond;
    sf::Texture         textureRocket;
    sf::Texture         textureCollapsion;
    sf::Texture         textureEatDiamond;
    sf::Texture         textureEatRocket;
    sf::Texture         textureScreenBegin;
    sf::Texture         textureScreenEnd;
    sf::Texture         texture_play_unchoose;
    sf::Texture         texture_play_choosen;
    sf::Texture         texture_replay_unchoose;
    sf::Texture         texture_replay_choosen;
    sf::Texture         texture_music_on;
    sf::Texture         texture_music_off;
    sf::Texture         texture_exit_on;
    sf::Texture         texture_exit_off;
    sf::Texture         texture_contents;
    sf::Texture         texture_next_choosen;
    sf::Texture         texture_next_unchoose;
    sf::Texture         texture_tutor;
    sf::Texture         texture_pausing_screen;

    sf::Sprite          sprite_pausing_screen;

    sf::Font            font;
    sf::Music           Music;

    sf::Vector2f        pos_in;

    MainBird        Mainbird;
    SecondBird      Secondbird;
    BackGround      background;

    Animation animatedMainBird;
    Animation animatedSecondBird;
    Animation animatedCollapsionDiamond;
    Animation animatedCollapsionRocket;
    Animation animatedCollapsion;
    Animation animatedRocket;
    Animation animatedDiamond;
    Animation animatedEnemy;

    std::vector<sf::Texture>    Texture_Layers;
    std::vector<std::string>    Name_Of_Songs;
    std::vector<Collapsion>     diamondcollapsions;
    std::vector<Collapsion>     Rocketcollapsions;
    std::vector<Collapsion>     collapsions;
    std::vector<Enemy>          Enemys;
    std::vector<Rocket>         Rockets;
    std::vector<Diamond>        Diamonds;

    int     score           = 0;
    int     typeOfBg;
    int     typeOfMusic;
    int     width_MainBird, height_MainBird, width_SecondBird, height_SecondBird, width_Enemy, height_Enemy;
    bool    inScreen        = true;
    int     respawn         = 0;
    float   animationSpeedLoad = 0.35;
    bool    Music_On        = true;
    bool    at_content      = true;

public:

    void createNewCollapsion();

    void createNewEnemy();

    void moveEnemy();

    void createNewCollapsionDiamond();

    void createNewDiamond();

    void moveDiamond();

    void createNewCollapsionRocket();

    void createNewRocket();

    void moveRocket();

    void updateEverythingWhilePlaying();

    bool setTheGame();

    bool run();

    void resetEverything();

    void SetupGame();

    Gameproject();
};

#endif //SFML_GAMEPROJECT_H
