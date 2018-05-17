//
// Created by Hoa Tran
//

////////////////////////////////////////
//////// START SCREEN AND END SCREEN ///
#include "../Header/Screen.h"

float distance_X_to_Y(float x_1, float y_1, float x_2, float y_2)
{
    return sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
}

int gameStarted(sf::RenderWindow* window, sf::Texture &texture_play_choosen, sf::Texture &texture_play_unchoose,
                 sf::Event * event, sf::Texture &textureScreenBegin, sf::Music * music, sf::Texture &texture_music_on,
                sf::Texture &texture_music_off, sf::Texture &texture_exit_on, sf::Texture &texture_exit_off, bool &music_on)
{
    sf::Sprite  play_button(texture_play_unchoose);
    sf::Sprite  screenBegin(textureScreenBegin);
    sf::Sprite  exit_button(texture_exit_off);
    sf::Sprite  music_button(texture_music_on);

    sf::Vector2f button_pos         = sf::Vector2f(1920 / 2 - 100, 1000 / 2 - 150);
    sf::Vector2f music_button_pos   = sf::Vector2f(button_pos.x - 175, button_pos.y + 50);
    sf::Vector2f exit_button_pos    = sf::Vector2f(button_pos.x + 225, button_pos.y + 56);

    sf::Vector2i mouse_pos          = sf::Mouse::getPosition(*window);

    float       Button_Radius                       = 100;
    float       Music_Button_Radius                 = 60;
    float       Exit_Button_Radius                  = 65;
    float       distance_mouse_pos_to_origin_button         = distance_X_to_Y(button_pos.x + 100, button_pos.y + 100, mouse_pos.x, mouse_pos.y);
    float       distance_mouse_pos_to_origin_music_button   = distance_X_to_Y(music_button_pos.x + 85, music_button_pos.y + 65, mouse_pos.x, mouse_pos.y);
    float       distance_mouse_pos_to_origin_exit_button    = distance_X_to_Y(exit_button_pos.x + 60, exit_button_pos.y + 60, mouse_pos.x, mouse_pos.y);

    ////////////////////////////

    screenBegin.setScale(1.005, 0.929);

    play_button.setOrigin(0, 0);
    play_button.setScale(2, 2);
    play_button.setPosition(button_pos);

    music_button.setOrigin(0, 0);
    music_button.setScale(0.5, 0.5);
    music_button.setPosition(music_button_pos);

    exit_button.setOrigin(0, 0);
    exit_button.setScale(1.25, 1.25);
    exit_button.setPosition(exit_button_pos);

    ////////////////////////////

    while (window->pollEvent(*event))
        if (event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return 2;

    ////////////////////////////

    if (distance_mouse_pos_to_origin_button <= Button_Radius)
    {
        play_button.setTexture(texture_play_choosen);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return 1;
        }
    }

    if (music_on == true) music_button.setTexture(texture_music_on);
    else music_button.setTexture(texture_music_off);
    if (distance_mouse_pos_to_origin_music_button <= Music_Button_Radius)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (!music_on)
            {
                music_on = true;
                music->play();
            }
            else
            {
                music_on = false;
                music->pause();
            }
        }
    }

    if (distance_mouse_pos_to_origin_exit_button <= Exit_Button_Radius)
    {
        exit_button.setTexture(texture_exit_on);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) return 2;

    }

    window->clear();
    window->draw(screenBegin);
    window->draw(play_button);
    window->draw(exit_button);
    window->draw(music_button);
    window->display();
    return 0;
}

int gameReplay(sf::RenderWindow* window, sf::Texture &texture_replay_choosen, sf::Texture &texture_replay_unchoose,
                sf::Event * event, sf::Texture &textureScreenEnd, int score, float text_Pos_X,
                float text_Pos_Y, sf::Font &font)
{
    sf::Sprite      replay_button(texture_replay_unchoose);
    sf::Sprite      screenEnd(textureScreenEnd);
    sf::Text        text;

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
    sf::Vector2f button_pos = sf::Vector2f(1920 / 2 - 100, 1000 / 2 + 100);

    std::string     score_String = std::to_string(score);

    float Button_Radius = 100;
    float distance_mouse_pos_to_origin_button = distance_X_to_Y(button_pos.x + 100, button_pos.y + 100, mouse_pos.x, mouse_pos.y);

    screenEnd.setScale(1, 0.929);

    replay_button.setOrigin(0, 0);
    replay_button.setScale(2, 2);
    replay_button.setPosition(button_pos);

    text.setFont(font);
    text.setString(score_String);
    text.setCharacterSize(200);
    text.setFillColor(sf::Color::Black);
    text.setPosition(text_Pos_X, text_Pos_Y);
    text.setStyle(sf::Text::Bold);

    if (distance_mouse_pos_to_origin_button <= Button_Radius)
    {
        replay_button.setTexture(texture_replay_choosen);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return 1;
        }
    }

    while (window->pollEvent(*event))
        if (event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window->close();
            return 2;
        }

    window->clear();
    window->draw(screenEnd);
    window->draw(text);
    window->draw(replay_button);
    window->display();
    return 0;
}

int Contents_And_Tutor(sf::RenderWindow * window, sf::Event * event, sf::Texture &texture_content,
                        sf::Texture &texture_tutor, MainBird * mainBird, SecondBird * secondBird,
                        BackGround * backGround, sf::Texture &texture_next_choosen, sf::Texture &texture_next_unchoose,
                       bool &at_contents, sf::Vector2f &pos_in) {
    sf::Sprite sprite;
    sf::Sprite next_button(texture_next_unchoose);

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
    sf::Vector2f next_button_pos = pos_in;

    if (at_contents) sprite.setTexture(texture_content);
    else sprite.setTexture(texture_tutor);

    sprite.setScale(1, 0.926);

    while (window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return 2;
    }

    next_button.setOrigin(0, 0);
    next_button.setPosition(next_button_pos);

    float next_button_radius = 50;
    float distance_mouse_pos_to_origin_next_button = distance_X_to_Y(next_button_pos.x + 50, next_button_pos.y + 50, mouse_pos.x, mouse_pos.y);

    if (distance_mouse_pos_to_origin_next_button <= next_button_radius)
    {
        next_button.setTexture(texture_next_choosen);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (at_contents)
            {
                at_contents = false;
                pos_in = sf::Vector2f(1720, 1000 - 1000 / 6);
            }
            else return 1;
        }
    }

    backGround->MoveAndDisplay();
    mainBird->displayMainBird();
    secondBird->displaySecondBird();
    window->draw(sprite);
    window->draw(next_button);
    window->display();

    return 0;
}

