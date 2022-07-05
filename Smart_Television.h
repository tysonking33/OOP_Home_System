#ifndef SMART_TELEVISION_H
#define SMART_TELEVISION_H

#include <iostream>
#include <string>
#include "Media_Device.h"
#include "Interactable.h"

class Smart_Television: public Media_Device {
private:
    //inherited from the parent class (media device)
    int smart_television_volume;                //the volume of the television
    bool the_smart_television_state;            //states if the television is on or off (on is true)
    std::string current_television_channel;     //states the current channel of the television
    //specific to this class
    int brightness_level;                       //states the brightness level of the television

public:
    //default media constructor
    Smart_Television();

    //media device constructor with user input
    Smart_Television(int tv_brightness);

    //inherited functions
    //changing the televison volume, between 0-100 inclusive
    void set_media_volume(int media_volume_level);

    //getting the television volume
    int get_media_volume();

    //changing the current channel
    void set_current_channel(std::string new_channel);

    //getting the current channel
    std::string get_current_channel();

    //function specific to the smart television class

    //changing the brigthness of the televison
    void set_brightness_level(int tv_brightness);

    //getting the current channel brightness
    int get_brightness_level();

    //printing all current infomation of the smart television
    void print();

    //default Smart_Television destructor
    ~Smart_Television();
};

#endif
