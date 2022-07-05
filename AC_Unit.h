#ifndef AC_UNIT_H
#define AC_UNIT_H

#include <iostream>
#include <string>
#include "Interactable.h"

class AC_Unit: public Interactable{
private:
    float AC_temperature;           //current temperature of AC unit
    int current_fan_speed;          //current fan speed of AC unit
    bool AC_on_or_off;              //states if the AC unit is on or off (on is true)
public:
    //default AC_Unit constructor
    AC_Unit();

    //AC_Unit constructor with user input
    AC_Unit(float original_temp, int AC_fan_speed, bool AC_on);

    //setting AC state
    void set_state(bool AC_on);

    //getting AC temperature
    bool get_state();

    //setting AC temperature
    void set_AC_temp(float original_temp);

    //getting AC temperature
    float get_AC_temp();

    //setting AC fan speed
    void set_AC_speed(int AC_fan_speed);

    //getting AC Name
    float get_AC_speed();

    //printing all current infomation of the AC_Unit
    void print();

    //destructor
    ~AC_Unit();
};

#endif
