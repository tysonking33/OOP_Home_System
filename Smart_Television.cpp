#include <iostream>
#include <string>
#include "Media_Device.h"
#include "Smart_Television.h"
#include "Interactable.h"


Smart_Television::Smart_Television(){
    //default media constructor
    type = "Smart_Television";                          //states the type of interactable object
    state = false;                                      //the volume of the television
    current_television_channel = "No_signal";           //states the current channel of the television
    smart_television_volume = 3;                        //states if the television is on or off (on is true)
    brightness_level = 0;                               //states the brightness level of the television
    std::cout << "This object is a " << type << std::endl;
    if (state == true){
        std::cout << "The smart television is on!" << std::endl;
    }
    else if(state == false){
        std::cout << "The smart television is off!" << std::endl;
    }
    std::cout << "The current television channel is: " << current_television_channel << std::endl;
    std::cout << "The television is playing at volume " << smart_television_volume << std::endl;
    std::cout << "The brightness of the television is: " << brightness_level << std::endl;
}

Smart_Television::Smart_Television(int tv_brightness){
    //media device constructor with user input
    type = "Smart_Television";
    std::cout << "This object is a " << type << std::endl;
    if (state == false){
        current_television_channel = "No_signal";
        smart_television_volume = 0;
        brightness_level = 0;
    }
    else{
        current_television_channel = current_channel;

        //tv volume is between 0 and 100 inclusive
        if (the_media_volume_level >= 0 && the_media_volume_level <= 100){
            smart_television_volume = the_media_volume_level;
        }
        else{
            smart_television_volume = 0;
        }
        //tv brightness between 0 and 5 inclusive
        if (tv_brightness >= 0 && tv_brightness <= 5){
            brightness_level = tv_brightness;
        }
        else {
            brightness_level = 0;
        }
    }
    if (state == true){
        std::cout << "The smart television is on!" << std::endl;
    }
    else if(state == false){
        std::cout << "The smart television is off!" << std::endl;
    }
    std::cout << "The current television channel is: " << current_television_channel << std::endl;
    std::cout << "The television is playing at volume " << smart_television_volume << std::endl;
    std::cout << "The brightness of the television is: " << brightness_level << std::endl;
}

//inherited functions
void Smart_Television::set_media_volume(int media_volume_level){
    //changing the televison volume, between 0-100 inclusive
    if ((media_volume_level >= 0 && media_volume_level <= 100) && (state == true)){
        smart_television_volume = media_volume_level;
    }
    else{
        smart_television_volume = 0;
        std::cout << "The volume input is out of range (0-100)!" << std::endl;
    }
    std::cout << "The television is playing at volume " << smart_television_volume << std::endl;
}

int Smart_Television::get_media_volume(){
    //getting the television volume
    return smart_television_volume;
}

//probably can take it from the media device
void Smart_Television::set_current_channel(std::string new_channel){
    //changing the current channel
    if (state == true){
        current_television_channel = new_channel;
    }
    else{
        current_television_channel = "No_signal";
    }
    std::cout << "The current television channel is: " << current_television_channel << std::endl;
}

std::string Smart_Television::get_current_channel(){
    //getting the current channel
    return current_television_channel;
}


//function specific to the smart television class

void Smart_Television::set_brightness_level(int tv_brightness){
    //changing the brigthness of the televison
    if ((state == true) && (tv_brightness >= 0 && tv_brightness <= 5)){
        brightness_level = tv_brightness;
    }
    else{
        std::cout << "Brightness level outside of 0 to 5 range." << std::endl;
    }
    std::cout << "The brightness of the television is: " << brightness_level << std::endl;
}

int Smart_Television::get_brightness_level(){
    //getting the current channel brightness
    return brightness_level;
}

void Smart_Television::print(){
    //printing all current infomation of the smart television
    std::cout << "This object is a " << type << std::endl;
    if (state == true){
        std::cout << "The smart television is on!" << std::endl;
    }
    else if(state == false){
        std::cout << "The smart television is off!" << std::endl;
    }
    std::cout << "The current television channel is: " << current_television_channel << std::endl;
    std::cout << "The television is playing at volume " << smart_television_volume << std::endl;
    std::cout << "The brightness of the television is: " << brightness_level << std::endl;
}

Smart_Television::~Smart_Television(){
    //default Smart_Television destructor
}
