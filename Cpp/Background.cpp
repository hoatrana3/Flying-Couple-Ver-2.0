//
// Created by Hoa Tran
//

#include "../Header/Background.h"

///// SETUP INFORMATION FOR THE BACKGROUND
void BackGround::setupInformationForBackGround(sf::RenderWindow * window, std::vector<sf::Texture> &Textures, int width_layer, int w_width)
{
    this->window = window;
    this->width_layer = width_layer;

    for (int i = 0; i < Textures.size(); i++)
    {
        Layer temp_Layer;
        sf::Sprite temp_sprite(Textures[i]);
        this->window->draw(temp_sprite);
        temp_Layer.speed = i * 0.4f;        //Set background speed move
        temp_Layer.layer_pos_x[0] = 0;
        temp_Layer.layer_pos_x[1] = this->width_layer;
        temp_Layer.sprite_array[0] = temp_Layer.sprite_array[1] = temp_sprite;
        this->Layers.push_back(temp_Layer);
    }
}

///// MOVE LAYERS OF BACKGROUND
void BackGround::MoveAndDisplay()
{
    for (int i = 0; i < Layers.size(); i++)
    {
        this->Layers[i].layer_pos_x[0] -= this->Layers[i].speed;
        this->Layers[i].layer_pos_x[1] -= this->Layers[i].speed;
        if (this->Layers[i].layer_pos_x[0] <= -this->width_layer) this->Layers[i].layer_pos_x[0] = this->width_layer;
        if (this->Layers[i].layer_pos_x[1] <= -this->width_layer) this->Layers[i].layer_pos_x[1] = this->width_layer;
        this->Layers[i].sprite_array[0].setPosition(Layers[i].layer_pos_x[0], 0);
        this->Layers[i].sprite_array[1].setPosition(Layers[i].layer_pos_x[1], 0);
        this->window->draw(Layers[i].sprite_array[0]);
        this->window->draw(Layers[i].sprite_array[1]);
    }
}


///// SET TEXTURE LAYERS BACKGROUND INTO LISTS AS AN VECTOR
std::vector<sf::Texture> TextureLayers(int typeOfBg)
{
    std::vector<sf::Texture>    temp_Vector;
    sf::Texture                 temp_Vector_;

    if (typeOfBg == 0)
    {
        temp_Vector_.loadFromFile("Image/LayerBackground/0.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/1.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/2.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/3.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/4.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/5.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/6.png"); temp_Vector.push_back(temp_Vector_);
    }

    if (typeOfBg == 1)
    {
        temp_Vector_.loadFromFile("Image/LayerBackground/7.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/8.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/9.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/10.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/11.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/12.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/13.png"); temp_Vector.push_back(temp_Vector_);
    }

    if (typeOfBg == 2)
    {
        temp_Vector_.loadFromFile("Image/LayerBackground/14.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/15.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/16.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/17.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/18.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/19.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/20.png"); temp_Vector.push_back(temp_Vector_);
    }

    if (typeOfBg == 3)
    {
        temp_Vector_.loadFromFile("Image/LayerBackground/21.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/22.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/23.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/24.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/25.png"); temp_Vector.push_back(temp_Vector_);
        temp_Vector_.loadFromFile("Image/LayerBackground/26.png"); temp_Vector.push_back(temp_Vector_);
    }

    return temp_Vector;
}



