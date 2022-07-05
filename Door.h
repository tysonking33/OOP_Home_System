#ifndef DOOR_H
#define DOOR_H

#include <iostream>
#include <string>
#include "Interactable.h"

class Door: public Interactable{
private:
    bool locked;            //states if the door is locked or unlocked (locked is true)
public:
    //default parameter
    Door();

    //Door constructor with user input
    Door(bool door_status);

    //setting the door status
    void set_state(bool door_status);

    //get door status
    bool get_door_state();

    //printing all current infomation of the door
    void print();

    ~Door();
};

#endif