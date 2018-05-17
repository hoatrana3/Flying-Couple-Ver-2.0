//
// Created by Hoa Tran on 18/04/2018.
//

#include "../Header/Audio.h"

//SET THE NAME OF SONGS INTO A LISTS AS A VECTOR
std::vector<std::string> set_Name_Of_Songs()
{
    std::vector<std::string>    Name_Of_Songs;

    for (int i = 0; i < 11; i++)
    {
        std::string     temp_Name = "Audio/";
        std::string     num_String = std::to_string(i);

        temp_Name += num_String + ".ogg";
        Name_Of_Songs.push_back(temp_Name);
    }
    return Name_Of_Songs;
}
