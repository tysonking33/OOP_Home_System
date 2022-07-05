
#include <iostream>
#include <vector>
#include "Interactable.h"

//Default Constructor
Interactable::Interactable(){
    interactable_name = "N/A";
    state = 0;

};

//Variable Constructor
Interactable::Interactable(std::string new_name, bool new_state){
    interactable_name = new_name;
    state = new_state;

};

//set_name function will set the name of the device (interactable)
void Interactable::set_name(std::string new_name){
    interactable_name = new_name;

};

//set_name function will return the name of the interactable
std::string Interactable::get_name(){
    return interactable_name;

};

//set_state will set the state of an interactable given boolean parameter
void Interactable::set_state(bool new_state){
    state = new_state;

};

//get_state function will return the state of the interactable
bool Interactable::get_state(){
    return state;

};

//Default Destructor
Interactable::~Interactable(){

};

//print function is virtual
void Interactable::print() {}
