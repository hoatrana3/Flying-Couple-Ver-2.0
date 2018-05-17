//
// Created by Hoa Tran
//
#pragma once

#ifndef SFML_SCREEN_H
#define SFML_SCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "Character.h"
#include "Background.h"

float distance_X_to_Y(float x_1, float y_1, float x_2, float y_2);

int gameStarted(sf::RenderWindow* window, sf::Texture &texture_play_choosen, sf::Texture &texture_play_unchoose,
                sf::Event * event, sf::Texture &textureScreenBegin, sf::Music * music, sf::Texture &texture_music_on,
                sf::Texture &texture_music_off, sf::Texture &texture_exit_on, sf::Texture &texture_exit_off, bool &music_on);

int gameReplay(sf::RenderWindow* window, sf::Texture &texture_replay_choosen, sf::Texture &texture_replay_unchoose,
               sf::Event * event, sf::Texture &textureScreenEnd, int score, float text_Pos_X,
               float text_Pos_Y, sf::Font &font);

int Contents_And_Tutor(sf::RenderWindow * window, sf::Event * event, sf::Texture &texture_content,
                        sf::Texture &texture_tutor, MainBird * mainBird, SecondBird * secondBird,
                        BackGround * backGround, sf::Texture &texture_next_choosen, sf::Texture &texture_next_unchoose,
                       bool &at_contents, sf::Vector2f &pos_in);

#endif //SFML_SCREEN_H
