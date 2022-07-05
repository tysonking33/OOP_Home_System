
#ifndef INTERACTABLE_H_
#define INTERACTABLE_H_

#include <iostream>
#include <vector>

class Interactable {

    protected:
        std::string interactable_name;      //Name of the interactable device
        bool state;                         //State of the interactable (i.e. on/off)

    public:
    //A string to let the program know what type of interactable each object is
    std::string type;
    //Default constructor will initialise name to be blank, and state to be 0 (representing off)
        Interactable();

    //Variable constructor will initialise variables through user input
        Interactable(std::string new_name, bool new_state);

    //set_name will set the name of the interactable device
        void set_name(std::string new_name);

    //get_name will return the name of the interactable device
        std::string get_name();

    //set_state will set the state of the interactable device
        virtual void set_state(bool new_state);

    //get_state will return the current state of the interactable device
        virtual bool get_state();

    //toggle_state will toggle the state of the interactable object.
        //virtual void toggle_state();

    //get_room will return the room that interactable is in
        //void get_room();

    //virtual print function
        virtual void print();

    //Default destructor
        ~Interactable();

};

#endif
