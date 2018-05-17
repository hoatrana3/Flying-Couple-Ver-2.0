//
// Created by Hoa Tran
//
#pragma once

#ifndef SFML_CONTROLGAME_H
#define SFML_CONTROLGAME_H

#include "Screen.h"
#include "Audio.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// FUNCTION TO CONTROL THE GAME ////////////// BELOW /////////////////////////////////

void DisplayScore(sf::RenderWindow * window, int &score, float text_Pos_X, float text_Pos_Y, sf::Font &font);

void DisplayHealth(sf::RenderWindow * window, int &health_MainBird, float text_Pos_X, float text_Pos_Y, sf::Font &font);

void setupUpToBackground(int &typeOfBg, sf::Texture &textureRes, int &w_res, int &h_res,
                         std::string link_s1, std::string link_s2, int para_w_s1, int para_h_s1,
                         int para_w_s2, int para_h_s2);

#endif //SFML_CONTROLGAME_H
