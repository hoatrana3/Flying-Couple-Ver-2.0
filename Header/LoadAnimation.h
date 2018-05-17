//
// Created by Hoa Tran
//

#ifndef SFML_LOADANIMATION_H
#define SFML_LOADANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
private:
    sf::RenderWindow*   window;
    sf::Sprite          sprite;

    float   speed;
    float   Frame;

    std::vector <sf::IntRect>   Frames;

public:

    void setInformation(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows,
                        int width, int height, float speed, int count_In_Rows, int count_Int_Cols,
                        int w_width, int w_height);

    void update(int numberFrameLoad);

    void draw();

    void setupSprite(float scale, float posW, float posH, float originW, float originH, float angleRotate);

    void setRotate(float angleRotate);

    int currentFrame();

    void setPos(int x, int y);

};

#endif //SFML_LOADANIMATION_H
