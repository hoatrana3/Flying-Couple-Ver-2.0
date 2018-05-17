//
// Created by Hoa Tran
//
#include "../Header/Character.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN BIRD

void MainBird::setupInformationForMainBird(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows,
                                           int width, int height, float speed, int count_In_Rows, int count_In_Cols,
                                           int w_width, int w_height, Animation * animated)
{
    this->animated = *animated;
    this->animated.setInformation(window, textureAnimation, cols, rows, width, height, speed, count_In_Rows,
                                  count_In_Cols, w_width, w_height);
    posMainBirdX = w_width / 4;
    posMainBirdY = w_height / 3;
    this->animated.setupSprite(0.2, posMainBirdX, posMainBirdY, width / 2, height / 2, angleMainBird);
    this->middle_Y = w_height / 2;
    this->w_heightTemp = w_height;
    this->w_widthTemp = w_width;
}

void MainBird::displayMainBird()
{
    this->animated.setPos(posMainBirdX, posMainBirdY);
    this->animated.setRotate(angleMainBird);
    this->animated.update(16);
    this->animated.draw();
}

void MainBird::controlMainBird()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (angleMainBird > -angleMax) angleMainBird -= angleSpeed;
        posMainBirdY -= speedMove;
        if (posMainBirdY < 50) posMainBirdY = 50;
    }
    else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (angleMainBird < angleMax) angleMainBird += angleSpeed;
            posMainBirdY += speedMove;
            if (posMainBirdY > this->w_heightTemp - 20) posMainBirdY = this->w_heightTemp - 20;
        }
        else
        {
            if (angleMainBird > 0) angleMainBird -= angleSpeed;
            if (angleMainBird < 0) angleMainBird += angleSpeed;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SECOND BIRD

void SecondBird::setupInformationForSecondBird(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols,
                                               int rows, int width, int height, float speed, int count_In_Rows,
                                               int count_In_Cols, int w_width, int w_height, Animation * animated)
{
    this->animated = *animated;
    this->animated.setInformation(window, textureAnimation, cols, rows, width, height, speed, count_In_Rows,
                                  count_In_Cols, w_width, w_height);
    posSecondBirdX = w_width / 8;
    posSecondBirdY = w_height / 2;
    this->animated.setupSprite(0.15, posSecondBirdX, posSecondBirdY, width / 2, height / 2, angleSecondBird);
    this->middle_Y = w_height / 2;
    this->w_heightTemp = w_height;
    this->w_widthTemp = w_width;
}

void SecondBird::displaySecondBird()
{
    this->animated.setPos(posSecondBirdX, posSecondBirdY);
    this->animated.setRotate(angleSecondBird);
    this->animated.update(8);
    this->animated.draw();
}

void SecondBird::controlSecondBird()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (angleSecondBird > -angleMax) angleSecondBird -= angleSpeed;
        posSecondBirdY -= speedMove;
        if (posSecondBirdY < 20) posSecondBirdY = 20;
    }
    else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (angleSecondBird < angleMax) angleSecondBird += angleSpeed;
            posSecondBirdY += speedMove;
            if (posSecondBirdY > this->w_heightTemp - 20) posSecondBirdY = this->w_heightTemp - 20;
        }
        else
        {
            if (angleSecondBird > 0) angleSecondBird -= angleSpeed;
            if (angleSecondBird < 0) angleSecondBird += angleSpeed;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ENEMY

void Enemy::setupEnemy(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows, int width,
                       int height, float speed, int count_In_Rows, int count_In_Cols, int w_width, int w_height,
                       Animation * animated)
{
    this->animated = *animated;
    this->animated.setInformation(window, textureAnimation, cols, rows, width, height, speed, count_In_Rows,
                                  count_In_Cols, w_width, w_height);
    angleEnemy = 180;
    this->animated.setupSprite(0.3, posEnemyX, posEnemyY, width / 2, height / 2, angleEnemy);
    this->middle_Y = w_height / 2;
    this->w_heightTemp = w_height;
    this->w_widthTemp = w_width;
    posEnemyX = this->w_widthTemp + (rand() % 1000) + 100;
    posEnemyY = rand() % w_height;
    this->width = width;
    speedMove = rand() % 10 + 3;
}

void Enemy::displayEnemy()
{
    this->animated.setPos(posEnemyX, posEnemyY);
    this->animated.update(8);
    this->animated.draw();
}

void Enemy::EnemyMove()
{
    posEnemyX -= speedMove;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DIAMOND

void Diamond::setupDiamond(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows, int width,
                           int height, float speed, int count_In_Rows, int count_In_Cols, int w_width, int w_height,
                           Animation * animated)
{
    this->animated = *animated;
    this->animated.setInformation(window, textureAnimation, cols, rows, width, height, speed, count_In_Rows,
                                  count_In_Cols, w_width, w_height);
    angleDiamond = 0;
    this->animated.setupSprite(0.10, posDiamondX, posDiamondY, width / 2, height / 2, angleDiamond);
    this->middle_Y = w_height / 2;
    this->w_heightTemp = w_height;
    this->w_widthTemp = w_width;
    posDiamondX = this->w_widthTemp + (rand() % 1000);
    posDiamondY = rand() % w_height;
    this->width = width;
    speedMove = rand() % 8 + 5;
}

void Diamond::displayDiamond()
{
    this->animated.setPos(posDiamondX, posDiamondY);
    this->animated.update(8);
    this->animated.draw();
}

void Diamond::DiamondMove()
{
    posDiamondX -= speedMove;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ROCKET

void Rocket::setupRocket(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows, int width,
                         int height, float speed, int count_In_Rows, int count_In_Cols, int w_width, int w_height,
                         Animation * animated)
{
    this->animated = *animated;
    this->animated.setInformation(window, textureAnimation, cols, rows, width, height, speed, count_In_Rows,
                                  count_In_Cols, w_width, w_height);
    angleRocket = 0;
    this->animated.setupSprite(0.2, posRocketX, posRocketY, width / 2, height / 2, angleRocket);
    this->middle_Y = w_height / 2;
    this->w_heightTemp = w_height;
    this->w_widthTemp = w_width;
    posRocketX = this->w_widthTemp + (rand() % 2000 + 500);
    posRocketY = rand() % w_height;
    this->width = width;
}
void Rocket::displayRocket()
{
    this->animated.setPos(posRocketX, posRocketY);
    this->animated.setRotate(this->angleRocket);
    this->animated.update(4);
    this->animated.draw();
}

void Rocket::RocketCatchSecond(float second_X, float second_Y, float second_Speed, bool second_Alive)
{
    int angle_Second_Rocket = atan(abs(this->posRocketY - second_Y) / abs(this->posRocketX - second_X)) * 180 / PI;

    if (abs(second_Y - this->posRocketY) > 10 && second_Y > this->posRocketY && second_Alive && second_X <= this->posRocketX)
    {
        angle_Second_Rocket = -(angle_Second_Rocket);
        this->posRocketY += second_Speed / ((rand() % 5) + 5);
        if (this->angleRocket > angle_Second_Rocket) this->angleRocket -= this->angleSpeed;
        else if (this->angleRocket < angle_Second_Rocket) this->angleRocket += this->angleSpeed;
    }
    else {
        if (abs(second_Y - this->posRocketY) > 10 && second_Y < this->posRocketY && second_Alive &&
            second_X <= this->posRocketX) {
            this->posRocketY -= second_Speed / ((rand() % 5) + 5);
            if (this->angleRocket > angle_Second_Rocket) this->angleRocket -= this->angleSpeed;
            else if (this->angleRocket < angle_Second_Rocket) this->angleRocket += this->angleSpeed;
        } else if ((second_Y == this->posRocketY || second_X > this->posRocketX) &&
                   abs(second_Y - this->posRocketY) <= 10)
        {
            if (static_cast<int>(this->angleRocket) > 0) angleRocket -= angleSpeed;
            else if (static_cast<int>(this->angleRocket) < 0) angleRocket += angleSpeed;
        }
    }
}

void Rocket::RocketMove(float second_X, float second_Y, float second_Speed, bool second_Alive)
{
    RocketCatchSecond(second_X, second_Y, second_Speed, second_Alive);
    posRocketX -= speedMove;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//COLLAPSION

Collapsion::Collapsion(sf::RenderWindow * window, sf::Texture &textureAnimation, int cols, int rows, int width,
                       int height, float speed, int count_In_Rows, int count_In_Cols, int w_width, int w_height,
                       Animation * animated, float pos_X, float pos_Y)
{
    this->animated = *animated;
    this->animated.setInformation(window, textureAnimation, cols, rows, width, height, speed, count_In_Rows,
                                  count_In_Cols, w_width, w_height);
    this->animated.setupSprite(1, pos_X, pos_Y, width / 2, height / 2, 0);
    this->textureCollapsion = textureAnimation;
    this->pos_X_Collapsion = pos_X;
    this->pos_Y_Collapsion = pos_Y;
}

bool Collapsion::displayCollapsion(int count_In_Rows, int count_In_Cols)
{
    this->animated.setPos(this->pos_X_Collapsion, this->pos_Y_Collapsion);
    this->animated.update(count_In_Cols * count_In_Rows);
    this->animated.draw();
    if (this->animated.currentFrame() == count_In_Cols * count_In_Rows - 1) return true;
    return false;
}

bool collapsion(float pos_First_X, float pos_First_Y, float scale_First, float width_First, float height_First,
                float pos_Second_X, float pos_Second_Y, float scale_Second, float width_Second, float height_Second)
{
    sf::Vector2f _First_tl = sf::Vector2f(pos_First_X - (width_First / 2) * scale_First, pos_First_Y - (height_First / 2) * scale_First), 
                 _First_br = sf::Vector2f(pos_First_X + (width_First / 2) * scale_First, pos_First_Y + (height_First / 2) * scale_First);

    sf::Vector2f _Second_tl = sf::Vector2f(pos_Second_X - (width_Second / 2) * scale_Second, pos_Second_Y - (height_Second / 2) * scale_Second),
                 _Second_br = sf::Vector2f(pos_Second_X + (width_Second / 2) * scale_Second, pos_Second_Y + (height_Second / 2) * scale_Second);

    if (_First_br.x < _Second_tl.x || _First_tl.x > _Second_br.x) return false;
    if (_First_br.y < _Second_tl.y || _First_tl.y > _Second_br.y) return false;

    return true;
}

bool CheckCollapsionWithEnemySecond(SecondBird SecondBird, std::vector<Enemy> Enemys, float scale_First,
                                    float width_First, float height_First, float scale_Second, float width_Second,
                                    float height_Second)
{
    for (int i = 0; i < Enemys.size(); i++)
        if (collapsion(SecondBird.posSecondBirdX, SecondBird.posSecondBirdY, scale_First, width_First, height_First,
                       Enemys[i].posEnemyX, Enemys[i].posEnemyY, scale_Second, width_Second, height_Second)) return true;
    return false;
}

bool CheckCollapsionEnemyWithMain(MainBird MainBird, Enemy enemy, float scale_First, float width_First,
                                  float height_First, float scale_Second, float width_Second, float height_Second)
{
    if (collapsion(MainBird.posMainBirdX, MainBird.posMainBirdY, scale_First, width_First, height_First,
                   enemy.posEnemyX, enemy.posEnemyY, scale_Second, width_Second, height_Second)) return true;
    return false;
}

bool CheckCollapsionDiamondWithSecond(SecondBird SecondBird, Diamond Diamond, float scale_First, float width_First,
                                      float height_First, float scale_Second, float width_Second, float height_Second)
{
    if (collapsion(SecondBird.posSecondBirdX, SecondBird.posSecondBirdY, scale_First, width_First, height_First,
                   Diamond.posDiamondX, Diamond.posDiamondY, scale_Second, width_Second, height_Second)) return true;
    return false;
}

bool CheckCollapsionRocketWithSecond(SecondBird SecondBird, Rocket Rocket, float scale_First, float width_First,
                                     float height_First, float scale_Second, float width_Second, float height_Second)
{
    if (collapsion(SecondBird.posSecondBirdX, SecondBird.posSecondBirdY, scale_First, width_First, height_First,
                   Rocket.posRocketX, Rocket.posRocketY, scale_Second, width_Second, height_Second)) return true;
    return false;
}

bool CheckCollapsionRocketWithMain(MainBird MainBird, Rocket Rocket, float scale_First, float width_First,
                                   float height_First, float scale_Second, float width_Second, float height_Second)
{
    if (collapsion(MainBird.posMainBirdX, MainBird.posMainBirdY, scale_First, width_First, height_First,
                   Rocket.posRocketX, Rocket.posRocketY, scale_Second, width_Second, height_Second)) return true;
    return false;
}
