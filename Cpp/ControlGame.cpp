//
// Created by Hoa Tran
//

#include "../Header/ControlGame.h"
#include <iostream>

//Score Game
void DisplayScore(sf::RenderWindow * window, int &score, float text_Pos_X, float text_Pos_Y, sf::Font &font)
{
    std::string score_String = std::to_string(score);
    sf::Text    text;

    text_Pos_X -= 20 * (score_String.length() - 1);

    text.setFont(font);
    text.setString(score_String);
    text.setCharacterSize(130);
    text.setPosition(text_Pos_X, text_Pos_Y);
    text.setStyle(sf::Text::Bold);
    window->draw(text);
}

//Health Of Bird
void DisplayHealth(sf::RenderWindow * window, int &health_MainBird, float text_Pos_X, float text_Pos_Y, sf::Font &font)
{
    std::string health_MainBird_str = std::to_string(health_MainBird);
    
    sf::Text    text_health_MainBird;
    
    health_MainBird_str     = "BIG BIRD HEALTH: " + health_MainBird_str;

    if (health_MainBird <= 20) text_health_MainBird.setFillColor(sf::Color(253,88,88,255));
    else text_health_MainBird.setFillColor(sf::Color::White);
    
    text_health_MainBird.setFont(font);
    text_health_MainBird.setString(health_MainBird_str);
    text_health_MainBird.setCharacterSize(45);
    text_health_MainBird.setPosition(text_Pos_X, text_Pos_Y);
    text_health_MainBird.setStyle(sf::Text::Bold);

    window->draw(text_health_MainBird);
}

//Setup the background
void setupUpToBackground(int &typeOfBg, sf::Texture &textureRes, int &w_res, int &h_res,
                         std::string link_s1, std::string link_s2, int para_w_s1,
                         int para_h_s1, int para_w_s2, int para_h_s2)
{
    if (typeOfBg == 0 || typeOfBg == 3) {
        textureRes.loadFromFile(link_s1);
        w_res = para_w_s1;
        h_res = para_h_s1;
    } else {
        textureRes.loadFromFile(link_s2);
        w_res = para_w_s2;
        h_res = para_h_s2;
    }
}

