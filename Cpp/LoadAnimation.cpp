//
// Created by Hoa Tran
//


//////////////////////////////////////////
/////// LOAD ANIMATION PART //////////////

#include "../Header/LoadAnimation.h"

void Animation::setInformation(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows,
                               int width, int height, float speed, int count_In_Rows, int count_In_Cols,
                               int w_width, int w_height)
{
    this->window = window;
    this->speed = speed;
    this->Frame = 0;

    for (int j = 0; j < count_In_Rows; j++)
    {
        for (int i = 0; i < count_In_Cols; i++) this->Frames.push_back(sf::IntRect(cols + width * j, rows + height * i,
                                                                                   width, height));
    }

    this->sprite.setTexture(textureAnimation);
    this->sprite.setTextureRect(this->Frames[0]);
    this->sprite.setOrigin(width / 2, height / 2);
}

void Animation::update(int numberFrameLoad)
{
    this->Frame += this->speed;
    if (this->Frame > numberFrameLoad) this->Frame -= numberFrameLoad;
    this->sprite.setTextureRect(this->Frames[int(this->Frame)]);
}

void Animation::draw()
{
    this->window->draw(this->sprite);
}

void Animation::setupSprite(float scale, float posW, float posH, float originW, float originH, float angleRotate)
{
    this->sprite.setOrigin(originW, originH);
    this->sprite.setScale(scale, scale);
    this->sprite.setPosition(posW, posH);
    this->sprite.setRotation(angleRotate);
}

void Animation::setRotate(float angleRotate)
{
    this->sprite.setRotation(angleRotate);
}

void Animation::setPos(int x, int y)
{
    this->sprite.setPosition(x, y);
}

int Animation::currentFrame()
{
    return this->Frame;
}
