#include <iostream>
#include <string>
#include "AC_Unit.h"
#include "Interactable.h"


AC_Unit::AC_Unit(){
    //default AC_Unit constructor
    type = "AC_Unit";               //interactable type
    AC_temperature = 26.0;          //current temperature of AC unit
    current_fan_speed = 0;          //current fan speed of AC unit
    AC_on_or_off = false;           //states if the AC unit is on or off (on is true)
    std::cout << "This object is an: " << type << std::endl;
    std::cout << "The temperature is: " << AC_temperature << std::endl;
    std::cout << "The current fan speed is: " << current_fan_speed << std::endl;
    if (AC_on_or_off == true){
        std::cout << "The AC is now on!" << std::endl;
    }
    else {
        std::cout << "The AC is now off!" <<  std::endl;
    }
}

AC_Unit::AC_Unit(float original_temp, int AC_fan_speed, bool AC_on){
    type = "AC_Unit";
    std::cout << "This object is an: " << type << std::endl;
    //AC temp has to be above 0, less than 100
    if (original_temp > 0 && original_temp < 100){
        AC_temperature = original_temp;
    }
    else{
        std::cout << "The temperature is invalid." << std::endl;
        std::cout << "Temperature has been set to 26.0 degrees Celcius." << std::endl;
        AC_temperature = 26.0;
    }
    std::cout << "The temperature is: " << AC_temperature << std::endl;
    //current fan speed has to be between 1 and 5, both inclusive
    if ((AC_fan_speed >= 1 && AC_fan_speed <= 5) || (AC_on_or_off == true)){
        current_fan_speed = AC_fan_speed;
        std::cout << "The current fan speed is: " << current_fan_speed << std::endl;
    }
    else{
        std::cout << "The speed is invalid." << std::endl;
        std::cout << "The speed has been set to 0." << std::endl;
        current_fan_speed = 0;
    }
    AC_on_or_off = AC_on;
    if (AC_on == true){
        std::cout << "The AC is now on!" << std::endl;
    }
    else {
        std::cout << "The AC is now off!" <<  std::endl;
    }
}


void AC_Unit::set_state(bool AC_on){
    //setting AC state
    AC_on_or_off = AC_on;
    if (AC_on == true){
        std::cout << "The AC is now on!" << std::endl;
    }
    else {
        std::cout << "The AC is now off!" <<  std::endl;
    }
}

bool AC_Unit::get_state(){
    //getting AC state
    return AC_on_or_off;
}

void AC_Unit::set_AC_temp(float original_temp){
    //setting AC temperature
    //AC temp has to be above 0, less than 100
    if (original_temp > 0 && original_temp < 100){
        AC_temperature = original_temp;
        std::cout << "The temperature is: " << AC_temperature << std::endl;
    }
    else{
        std::cout << "The temperature is invalid." << std::endl;
        std::cout << "Temperature has been set to 26.0 degrees Celcius." << std::endl;
        AC_temperature = 26.0;
    }
}

float AC_Unit::get_AC_temp(){
    //getting AC temperature
    return AC_temperature;
}

void AC_Unit::set_AC_speed(int AC_fan_speed){
    //setting AC fan speed
    //current fan speed has to be between 1 and 5, both inclusive
    if ((AC_fan_speed >= 1 && AC_fan_speed <= 5) || (AC_on_or_off == true)){
        std::cout << "The speed has been set to " << AC_fan_speed << "." << std::endl;
        current_fan_speed = AC_fan_speed;
    }
    else{
        std::cout << "The speed is invalid." << std::endl;
        std::cout << "The speed has been set to 0." << std::endl;
        current_fan_speed = 0;
    }
}

float AC_Unit::get_AC_speed(){
    //getting AC Name
    return current_fan_speed;
}

void AC_Unit::print(){
    //printing all current infomation of the AC_Unit
    std::cout << "This object is an: " << type << std::endl;
    std::cout << "The temperature is: " << AC_temperature << std::endl;
    std::cout << "The current fan speed is: " << current_fan_speed << std::endl;
    if (AC_on_or_off == true){
        std::cout << "The AC is now on!" << std::endl;
    }
    else {
        std::cout << "The AC is now off!" <<  std::endl;
    }
}

AC_Unit::~AC_Unit(){
    //destructor
}
