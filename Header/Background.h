//
// Created by Hoa Tran
//
#pragma once

#ifndef SFML_BACKGROUND_H
#define SFML_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <vector>

class BackGround
{
private:
    sf::RenderWindow*   window;

    struct Layer
    {
        sf::Sprite      sprite_array[2];

        float   speed;
        float   layer_pos_x[2];

    };

    std::vector<Layer>   Layers;

    int     width_layer;

public:

    void setupInformationForBackGround(sf::RenderWindow * window, std::vector<sf::Texture> &Textures,
                                       int width_layer, int w_width);

    void MoveAndDisplay();
};

/////////////////////////////////////////////////////////////////////

std::vector<sf::Texture> TextureLayers(int typeOfBg);


#endif //SFML_BACKGROUND_H
