
#ifndef ROOM_H_
#define ROOM_H_

#include "Interactable.h"

#include <iostream>
#include <vector>
#include "Home.h"
#include "Listable.h"

class Home;

class Room : public Listable{

    public:
        std::string room_name;                      //Name of the Room
        Interactable* devices;                      //Devices inside of the room
        int num_devices;                            //Total number of interactables currently inside the room;
        int capacity;                               //Total number of interactables that can occupy one room
        std::vector<Interactable*> *interactables;  //List of interactables inside room

    public:
    //Default Constructor
        Room();

    //Variable Constructor that takes name and total number of interactables that can occupy the room;
        Room(std::string name, int capacity);

    //get_name will return the name of the room;
        std::string get_name();

    //get_name will return the name of the room;
        void set_name(std::string name);

    //add_interactable will create an interactable with given type and name, and then add it to the current room.
        void add_interactable(std::string interactable_type, std::string interactable_name);

    //remove_interactable will remove and interactable in the current room given the type and name.
        void remove_interactable(Interactable * interactableToRemove);

    //list_interactables will return the list of interactables in a current room
        void list();

    //print_interactables will print the list of interactables in a current room
        //void print();

    //Default Destructor
        ~Room();


};


#endif //ROOM_H_
