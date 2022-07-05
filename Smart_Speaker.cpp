#include <iostream>
#include <string>
#include "Media_Device.h"
#include "Smart_Speaker.h"
#include "Interactable.h"

Smart_Speaker::Smart_Speaker(){
    //default constructor for smart speaker
    type = "Smart_Speaker";                         //states the type of interactable object
    //state = false;                                  //states if the smart speaker is on or off (on is true)
    current_speaker_channel = "No_signal";          //states the current channel of the speaker
    smart_speaker_volume = 3;                       //the volume of the smart speaker
    current_audio = "nothing playing";              //states the current audio playing in this speaker
    std::cout << "This object is a " << type << std::endl;
    if (state == true){
        std::cout << "The speaker is on!" << std::endl;
    }
    else if(state == false){
        std::cout << "The speaker is off!" << std::endl;
    }
    std::cout << "The speaker is playing: " << current_speaker_channel << std::endl;
    std::cout << "The speaker volume: " << smart_speaker_volume << std::endl;
    std::cout << "The current audio is: " << current_audio << std::endl;
}

Smart_Speaker::Smart_Speaker(std::string current_speaker_audio){
    //constructor with user input
    type = "Smart_Speaker";
    std::cout << "This object is a " << type << std::endl;
    if (state == false){
        current_speaker_channel = "No_signal";
        smart_speaker_volume = 0;
        current_audio = "nothing playing";
    }
    else{
        current_speaker_channel = current_channel;

        //tv volume is between 0 and 100 inclusive
        if (the_media_volume_level >= 0 && the_media_volume_level <= 100){
            smart_speaker_volume = the_media_volume_level;
        }
        else{
            smart_speaker_volume = 0;
            std::cout << "The volume is not in an acceptable range (0 to 100)!" << std::endl;
        }
        current_audio = current_speaker_audio;
    }
    if (state == true){
        std::cout << "The speaker is on!" << std::endl;
    }
    else if(state == false){
        std::cout << "The speaker is off!" << std::endl;
    }
    std::cout << "The speaker is playing: " << current_speaker_channel << std::endl;
    std::cout << "The speaker volume: " << smart_speaker_volume << std::endl;
    std::cout << "The current audio is: " << current_audio << std::endl;
}

//inherited functions

void Smart_Speaker::set_media_volume(int media_volume_level){
    //setting the speaker volume, between 0-100 inclusive
    if ((media_volume_level >= 0 && media_volume_level <= 100) && (state == true)){
        smart_speaker_volume = media_volume_level;
    }
    else{
        smart_speaker_volume = 0;
        std::cout << "The volume is not in an acceptable range (0 to 100)!" << std::endl;
    }
    std::cout << "The speaker volume: " << smart_speaker_volume << std::endl;
}

int Smart_Speaker:: get_media_volume(){
    //getting the speaker volume
    return smart_speaker_volume;
}

void Smart_Speaker::set_current_channel(std::string new_channel){
    //changing the current channel
    if (state == true){
        current_speaker_channel = new_channel;
    }
    else{
        current_speaker_channel = "No_signal";
    }
    std::cout << "The speaker is playing: " << current_speaker_channel << std::endl;
}

std::string Smart_Speaker::get_current_channel(){
    //getting the current channel
    return current_speaker_channel;
}

//making the functions specific to this class

void Smart_Speaker::set_current_audio(std::string current_speaker_audio){
    //setting the current audio
    if (state == true){
        current_audio = current_speaker_audio;
    }
    else{
        current_audio = "Nothing playing";
    }
    std::cout << "The current audio is: " << current_audio << std::endl;
}

std::string Smart_Speaker::get_current_audio(){
    //getting the current audio
    return current_audio;
}

void Smart_Speaker::print(){
    //printing all current infomation of the smart speaker
    std::cout << "This object is a " << type << std::endl;
    if (state == true){
        std::cout << "The speaker is on!" << std::endl;
    }
    else if(state == false){
        std::cout << "The speaker is off!" << std::endl;
    }
    std::cout << "The speaker is playing: " << current_speaker_channel << std::endl;
    std::cout << "The speaker volume: " << smart_speaker_volume << std::endl;
    std::cout << "The current audio is: " << current_audio << std::endl;
}

Smart_Speaker::~Smart_Speaker(){
    //default destructor
}
