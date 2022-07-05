#include <iostream>
#include <string>
#include "Media_Device.h"

Media_Device::Media_Device(){
    //default media device constructor
    state = false;        //states if the media device is on or off (on is true)
    the_media_volume_level = 0;     //current volume of media device
    current_channel = "ABC3";       //current channel of media device
}

Media_Device::Media_Device(bool media_state, int media_volume_level, std::string new_channel){
    //media device with user input
    //media state level
    state = media_state;
    if (media_state == true){
        std::cout << "The media device is on" << std::endl;
    }
    else if(media_state == false){
        std::cout << "The media device is off" << std::endl;
    }
    //media volume level
    if ((media_volume_level >= 0 && media_volume_level <= 100) || (state == true)){
        the_media_volume_level = media_volume_level;
    }
    else{
        the_media_volume_level = 0;
    }
    std::cout << "The device's volume is: " << the_media_volume_level << std::endl;
    //media channel
    if (state == true){
        current_channel = new_channel;
    }
    std::cout << "The current channel is " << current_channel << std::endl;
}

void Media_Device::set_state(bool new_state){
    //setting media state
    state = new_state;
    if (new_state == true){
        std::cout << "The media device is on!" << std::endl;
    }
    else if(new_state == false){
        std::cout << "The media device is off!" << std::endl;
    }
}

bool Media_Device::get_state(){
    //getting media state
    return state;
}


void Media_Device::set_media_volume(int media_volume_level){
    //setting media volume level
    //volume is 0-100
    if ((media_volume_level >= 0 && media_volume_level <= 100) && (state == true)){
        the_media_volume_level = media_volume_level;
    }
    else{
        the_media_volume_level = 0;
    }
    std::cout << "The device's volume is: " << the_media_volume_level << std::endl;
}

int Media_Device::get_media_volume(){
    //getting media volume level
    return the_media_volume_level;
}

void Media_Device::set_current_channel(std::string new_channel){
    if (state == true){
        current_channel = new_channel;
    }
    std::cout << "You are on " << current_channel << std::endl;
}

std::string Media_Device::get_current_channel(){
    return current_channel;
}

void Media_Device::print(){
    //printing all current infomation of the media device
    if (state == true){
        std::cout << "The media device is on" << std::endl;
    }
    else if(state == false){
        std::cout << "The media device is off" << std::endl;
    }
    std::cout << "The device's volume is: " << the_media_volume_level << std::endl;
    std::cout << "The current channel is " << current_channel << std::endl;
}

Media_Device::~Media_Device(){
    //default destructor
}
