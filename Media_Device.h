#ifndef MEDIA_DEVICE_H
#define MEDIA_DEVICE_H

#include <iostream>
#include <string>
#include "Interactable.h"

class Media_Device: public Interactable {
protected:
    bool state;                         //states if the media device is on or off (on is true)
    int the_media_volume_level;         //current volume of media device
    std::string current_channel;        //current channel of media device

public:
    //default media device constructor
    Media_Device();

    //media device with user input
    Media_Device(bool media_state, int media_volume_level, std::string new_channel);

    //settin media state
    void set_state(bool new_state);

    //getting media state
    bool get_state();

    //setting media volume level
    //volume is 0-100
    virtual void set_media_volume(int media_volume_level);

    //getting media volume level
    virtual int get_media_volume();

    //changing the channel
    virtual void set_current_channel(std::string new_channel);

    //getting the current channel
    virtual std::string get_current_channel();

    //printing all current infomation of the media device
    void print();

    //default destructor
    ~Media_Device();
};

#endif
