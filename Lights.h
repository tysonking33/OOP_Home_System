#ifndef LIGHTS_H
#define LIGHTS_H

#include <iostream>
#include <string>
#include "Interactable.h"

class Lights: public Interactable{
private:
    std::string the_light_colour;       //the colour of the light
    bool light_on_state;                //shows whether or not the light is on (on is true)
public:
    //creating a default light object with a light name, light colour and status of the light
    Lights();

    //making a light variable will the light name, light colour and on off state
    Lights(std::string light_colour, bool state_of_light);

    //change the state of the light (i.e. on or off)
    void set_state(bool light_state);

    //return the state of the light
    bool get_state();

    //change the colour of the light
    void set_colour(std::string colour);

    //get the colour of the light
    std::string get_colour();

    //printing all current infomation of the light
    void print();
    
    //destructor
    ~Lights();
};

#endif