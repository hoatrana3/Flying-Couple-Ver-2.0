//
// Created by Hoa Tran
//

#include "../Header/Gameproject.h"

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//Enemy Functions
void Gameproject::createNewCollapsion()
{
    for (int i = 0; i < Enemys.size(); i++)
        if (collapsion(Mainbird.posMainBirdX, Mainbird.posMainBirdY, 0.2, 300, 400, Enemys[i].posEnemyX,
                       Enemys[i].posEnemyY, 0.3, 300, 400))
        {
            Collapsion tempCollapsion(&window, textureCollapsion, 0, 0, 224, 224, animationSpeedLoad, 8, 1, WINDOW_WIDTH, WINDOW_HEIGHT,
                                      &animatedCollapsion, Enemys[i].posEnemyX, Enemys[i].posEnemyY);
            collapsions.push_back(tempCollapsion);
        }
}

void Gameproject::createNewEnemy()
{
    if (rand() % 55 == 0)
    {
        Enemy Enemy_Temp;
        Enemy_Temp.setupEnemy(&window, textureEnemy, 0, 0, width_Enemy, height_Enemy, animationSpeedLoad, 8, 1,
                              WINDOW_WIDTH, WINDOW_HEIGHT, &animatedEnemy);
        Enemys.push_back(Enemy_Temp);
    }
}

void Gameproject::moveEnemy()
{
    for (int i = 0; i < Enemys.size(); i++)
    {
        Enemys[i].EnemyMove();
        if (Enemys[i].posEnemyX < -20)
        {
            Enemys.erase(Enemys.begin() + i);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//Diamond Functions
void Gameproject::createNewCollapsionDiamond()
{
    for (int i = 0; i < Diamonds.size(); i++)
        if (collapsion(Secondbird.posSecondBirdX, Secondbird.posSecondBirdY, 0.15, 200, 300, Diamonds[i].posDiamondX,
                       Diamonds[i].posDiamondY, 0.10, 300, 400))
        {
            Collapsion tempCollapsion(&window, textureEatDiamond, 0, 0, 180, 180, animationSpeedLoad * 2, 16, 1, WINDOW_WIDTH,
                                      WINDOW_HEIGHT, &animatedCollapsionDiamond, Diamonds[i].posDiamondX, Diamonds[i].posDiamondY);
            diamondcollapsions.push_back(tempCollapsion);
        }
}

void Gameproject::createNewDiamond()
{
    if (rand() % 45 == 0)
    {
        Diamond Diamond_Temp;
        Diamond_Temp.setupDiamond(&window, textureDiamond, 0, 0, 739, 512, animationSpeedLoad, 8, 1, WINDOW_WIDTH,
                                  WINDOW_HEIGHT, &animatedDiamond);
        Diamonds.push_back(Diamond_Temp);
    }
}

void Gameproject::moveDiamond()
{
    for (int i = 0; i < Diamonds.size(); i++)
    {
        Diamonds[i].DiamondMove();
        if (Diamonds[i].posDiamondX < -20)
        {
            Diamonds.erase(Diamonds.begin() + i);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//Rocket Function
void Gameproject::createNewCollapsionRocket()
{
    for (int i = 0; i < Rockets.size(); i++)
    {
        if (collapsion(Secondbird.posSecondBirdX, Secondbird.posSecondBirdY, 0.15, 300, 400, Rockets[i].posRocketX,
                       Rockets[i].posRocketY, 0.20, 1000, 800))
        {
            Collapsion tempCollapsion(&window, textureEatRocket, 0, 0, 180, 180, animationSpeedLoad * 2, 18, 1, WINDOW_WIDTH, WINDOW_HEIGHT,
                                      &animatedCollapsionRocket, Rockets[i].posRocketX, Rockets[i].posRocketY);
            Rocketcollapsions.push_back(tempCollapsion);
        }
        if (Mainbird.alive)
            if (collapsion(Mainbird.posMainBirdX, Mainbird.posMainBirdY, 0.15, 300, 400, Rockets[i].posRocketX,
                           Rockets[i].posRocketY, 0.20, 1000, 800))
            {
                Collapsion tempCollapsion(&window, textureEatRocket, 0, 0, 180, 180, animationSpeedLoad * 2, 18, 1, WINDOW_WIDTH, WINDOW_HEIGHT,
                                          &animatedCollapsionRocket, Rockets[i].posRocketX, Rockets[i].posRocketY);
                Rocketcollapsions.push_back(tempCollapsion);
            }
    }
}

void Gameproject::createNewRocket()
{
    if (rand() % 300 == 0)
    {
        Rocket Rocket_Temp;
        Rocket_Temp.setupRocket(&window, textureRocket, 0, 0, 1280, 512, animationSpeedLoad / 4, 4, 1, WINDOW_WIDTH,
        WINDOW_HEIGHT, &animatedRocket);
        Rockets.push_back(Rocket_Temp);
    }
}

void Gameproject::moveRocket()
{
    for (int i = 0; i < Rockets.size(); i++)
    {
        Rockets[i].RocketMove(Secondbird.posSecondBirdX, Secondbird.posSecondBirdY, Secondbird.speedMove, Secondbird.alive);
        if (Rockets[i].posRocketX < -20)
        {
            Rockets.erase(Rockets.begin() + i);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//Game Loops While Playing
void Gameproject::updateEverythingWhilePlaying()
{
    //Bird controler
    if (Mainbird.alive) Mainbird.controlMainBird();
    Secondbird.controlSecondBird();

    //Enemy Work
    createNewEnemy();
    moveEnemy();

    //Diamond Work
    createNewDiamond();
    moveDiamond();

    //Rocket Work
    createNewRocket();
    moveRocket();

    //Collapsion Work
    if (Mainbird.alive) createNewCollapsion();
    createNewCollapsionDiamond();
    createNewCollapsionRocket();

    //Clear and display the game
    window.clear(sf::Color(255, 255, 255, 255));
    background.MoveAndDisplay();
    if (Mainbird.alive) Mainbird.displayMainBird();
    Secondbird.displaySecondBird();

    //Enemy Display and collapsion
    for (int i = 0; i < Enemys.size(); i++) Enemys[i].displayEnemy();

    for (int i = 0; i < collapsions.size(); i++)
        if (collapsions[i].displayCollapsion(8, 1)) collapsions.erase(collapsions.begin() + i);

    if (Mainbird.alive)
        for (int i = 0; i < Enemys.size(); i++)
            if (CheckCollapsionEnemyWithMain(Mainbird, Enemys[i], 0.2, 300, 400, 0.3, 300, 400))
            {
                Enemys.erase(Enemys.begin() + i);
                Mainbird.health -= CHANGE_HEALTH_TOUCH_ENEMY;
            }

    //Diamond Display and collapsion
    for (int i = 0; i < Diamonds.size(); i++) Diamonds[i].displayDiamond();

    for (int i = 0; i < diamondcollapsions.size(); i++)
        if (diamondcollapsions[i].displayCollapsion(16, 1)) diamondcollapsions.erase(diamondcollapsions.begin() + i);

    for (int i = 0; i < Diamonds.size(); i++)
        if (CheckCollapsionDiamondWithSecond(Secondbird, Diamonds[i], 0.15, 200, 300, 0.10, 300, 400))
        {
            Diamonds.erase(Diamonds.begin() + i);
            score++;
            respawn++;
            if (Mainbird.alive) Mainbird.health += CHANGE_HEALTH_TOUCH_DIAMOND;
        }

    //Rocket Display and collapsion
    for (int i = 0; i < Rockets.size(); i++) Rockets[i].displayRocket();
    for (int i = 0; i < Rocketcollapsions.size(); i++)
        if (Rocketcollapsions[i].displayCollapsion(18, 1)) Rocketcollapsions.erase(Rocketcollapsions.begin() + i);

    for (int i = 0; i < Rockets.size(); i++)
        if (CheckCollapsionRocketWithSecond(Secondbird, Rockets[i], 0.15, 300, 400, 0.20, 1000, 800)) Secondbird.alive = false;

    if (Mainbird.alive)
        for (int i = 0; i < Rockets.size(); i++)
            if (CheckCollapsionRocketWithMain(Mainbird, Rockets[i], 0.15, 300, 400, 0.20, 1000, 800) || Rockets[i].posRocketX < -30)
            {
                Rockets.erase(Rockets.begin() + i);
                Mainbird.health -= CHANGE_HEALTH_TOUCH_ROCKET;
            }

    //Check Second Bird alive
    if ((CheckCollapsionWithEnemySecond(Secondbird, Enemys, 0.15, 300, 400, 0.3, 225, 300))) Secondbird.alive = false;

    //Respawn Counting And Health Logic
    if (Mainbird.health <= 0)
    {
        Mainbird.alive = false;
        Mainbird.health = 0;
    }

    if (!Mainbird.alive) {
        if (respawn >= 5)
        {
            Mainbird.alive = true;
            Mainbird.health = 100;
        }
    } else respawn = 0;

    //Display score and health
    DisplayScore(&window, score, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 10, font);
    DisplayHealth(&window, Mainbird.health, WINDOW_WIDTH / 12, WINDOW_HEIGHT - WINDOW_HEIGHT / 8, font);
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//Main Game Loop Everything
bool Gameproject::setTheGame()
{
    SetupGame();
    while (window.isOpen())
    {
        window.setFramerateLimit(FRAMES); //Frames Limit

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        while (gameStarted(&window, texture_play_choosen, texture_play_unchoose, &getEvent, textureScreenBegin,
                           &Music, texture_music_on, texture_music_off ,texture_exit_on, texture_exit_off, Music_On) == 0)
        {
            window.setFramerateLimit(FRAMES); //Frames Limit
        }

        if (gameStarted(&window, texture_play_choosen, texture_play_unchoose, &getEvent, textureScreenBegin,
                        &Music, texture_music_on, texture_music_off ,texture_exit_on, texture_exit_off, Music_On) == 2) return false;

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        while (Contents_And_Tutor(&window, &getEvent, texture_contents, texture_tutor, &Mainbird, &Secondbird,
                                  &background, texture_next_choosen, texture_next_unchoose, at_content, pos_in) == 0)
        {
            window.setFramerateLimit(FRAMES); // Frames Limit
        }

        if (Contents_And_Tutor(&window, &getEvent, texture_contents, texture_tutor, &Mainbird, &Secondbird,
                               &background, texture_next_choosen, texture_next_unchoose, at_content, pos_in) == 2) return false;

        while (Secondbird.alive)
        {
            window.setFramerateLimit(FRAMES); //Frames Limit

            //Event's loop
            window.pollEvent(getEvent);
            if (getEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
                return false;
            }

            //check in Game Screen
            if (getEvent.type == sf::Event::LostFocus) inScreen = false;
            else if (getEvent.type == sf::Event::GainedFocus) inScreen = true;

            //Loop In Game Screen
            if (inScreen) updateEverythingWhilePlaying();

            if (!inScreen) window.draw(sprite_pausing_screen);

            window.display();
        }

        std::string str_scr = std::to_string(score);
        int text_offset = - 60 - 60 * (str_scr.length() - 1);

        while (gameReplay(&window, texture_replay_choosen, texture_replay_unchoose, &getEvent, textureScreenEnd, score,
                          WINDOW_WIDTH / 2 + text_offset, WINDOW_HEIGHT / 2 - 165, font) == 0)
        {
            window.setFramerateLimit(FRAMES); //Frames Limit
        }

        if (gameReplay(&window, texture_replay_choosen, texture_replay_unchoose, &getEvent, textureScreenEnd, score,
                       WINDOW_WIDTH / 2 + text_offset, WINDOW_HEIGHT / 2 - 165, font) == 1) resetEverything();

        if (gameReplay(&window, texture_replay_choosen, texture_replay_unchoose, &getEvent, textureScreenEnd, score,
                        WINDOW_WIDTH / 2 + text_offset, WINDOW_HEIGHT / 2 - 165, font) == 2) return false;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//Run the game
void Gameproject::SetupGame()
{
    //Load Font Text
    font.loadFromFile("Font/OCRAEXT.ttf");

    //Random Type Of BackGround And Music
    typeOfBg = rand() % 4;
    typeOfMusic = rand() % 10;

    //Music Setup
    Name_Of_Songs = set_Name_Of_Songs();
    Music.openFromFile(Name_Of_Songs[typeOfMusic]);
    Music.setLoop(true);
    Music.play();
    Music_On = true;

    //Setup somethings
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "F L Y I N G   C O U P L E", sf::Style::None);

    //Declare Background
    Texture_Layers = TextureLayers(typeOfBg);
    background.setupInformationForBackGround(&window, Texture_Layers, 1919, 2000);

    //Declare Screen
    textureScreenBegin.loadFromFile("Image/Screen/screen_begin.png");
    textureScreenEnd.loadFromFile("Image/Screen/screen_end.png");
    texture_play_choosen.loadFromFile("Image/Screen/play_choosen.png");
    texture_play_unchoose.loadFromFile("Image/Screen/play_unchoose.png");
    texture_replay_choosen.loadFromFile("Image/Screen/replay_choosen.png");
    texture_replay_unchoose.loadFromFile("Image/Screen/replay_unchoose.png");
    texture_music_on.loadFromFile("Image/Screen/music_on.png");
    texture_music_off.loadFromFile("Image/Screen/music_off.png");
    texture_exit_on.loadFromFile("Image/Screen/exit_on.png");
    texture_exit_off.loadFromFile("Image/Screen/exit_off.png");
    texture_contents.loadFromFile("Image/Screen/Contents.png");
    texture_tutor.loadFromFile("Image/Screen/Tutor.png");
    texture_next_choosen.loadFromFile("Image/Screen/next_choosen.png");
    texture_next_unchoose.loadFromFile("Image/Screen/next_unchoose.png");
    texture_pausing_screen.loadFromFile("Image/Screen/pausing_screen.png");

    sprite_pausing_screen.setTexture(texture_pausing_screen);

    //Declare Mainbird
    setupUpToBackground(typeOfBg, textureMainBird, width_MainBird, height_MainBird,
                        "Image/Character/chicken.png", "Image/Character/eagle.png", 688, 508, 708, 512);
    Mainbird.setupInformationForMainBird(&window, textureMainBird, 0, 0, width_MainBird, height_MainBird,
                                         animationSpeedLoad, 1, 16, WINDOW_WIDTH, WINDOW_HEIGHT, &animatedMainBird);

    //Declare Secondbird
    setupUpToBackground(typeOfBg, textureSecondBird, width_SecondBird, height_SecondBird,
                        "Image/Character/unicornbird.png", "Image/Character/eggbird.png", 1120, 717, 1361, 512);
    Secondbird.setupInformationForSecondBird(&window, textureSecondBird, 0, 0, width_SecondBird, height_SecondBird,
                                             animationSpeedLoad, 8, 1, WINDOW_WIDTH, WINDOW_HEIGHT, &animatedSecondBird);

    //Declare Enemy
    setupUpToBackground(typeOfBg, textureEnemy, width_Enemy, height_Enemy, "Image/Character/evil1.png",
                        "Image/Character/evil.png", 780, 499, 600, 512);

    //Declare Diamond
    textureDiamond.loadFromFile("Image/Character/diamond.png");

    //Declare Rocket
    textureRocket.loadFromFile("Image/Character/Rocket.png");

    //Declare Collapsion
    if (typeOfBg == 0 || typeOfBg == 3) textureCollapsion.loadFromFile("Image/Character/explosion_chick.png");
    else textureCollapsion.loadFromFile("Image/Character/explosion_eagle.png");

    //Declare Collapsion Diamond
    textureEatDiamond.loadFromFile("Image/Character/diamondcollapsion.png");

    //Declare Collapsion Rocket
    textureEatRocket.loadFromFile("Image/Character/Rocketcollapsion.png");

    //Pos In
    pos_in = sf::Vector2f(100, 1000 - 1000 / 6);
}

void Gameproject::resetEverything()
{
    Secondbird.alive    = true;
    Mainbird.alive      = true;
    Mainbird.angleMainBird = Secondbird.angleSecondBird = 0;
    Mainbird.health     = 100;

    score               = 0;
    pos_in              = sf::Vector2f(100, 1000 - 1000 / 6);;
    at_content          = true;


    //Clear Vector
    Texture_Layers.clear();
    diamondcollapsions.clear();
    Rocketcollapsions.clear();
    Enemys.clear();
    Rockets.clear();
    Diamonds.clear();

    SetupGame();
}

bool Gameproject::run()
{
    // window.setFramerateLimit(60);
    if (!setTheGame())
    {
        Music.stop();
        return EXIT_SUCCESS;
    }
    window.close();
    return EXIT_SUCCESS;
}

Gameproject::Gameproject()
{
    this->run();
}