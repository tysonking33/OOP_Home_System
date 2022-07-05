
#ifndef HOME_H_
#define HOME_H_

#include <iostream>
#include <vector>
#include "Room.h"
#include "Listable.h"

class Room;

class Home : public Listable{

    protected:
        std::string home_name;      //Home name
        int numRooms;               //Current number of rooms

    public:
        std::vector<Room*> *rooms;  //List of rooms

        //Default Constructor
        Home();

        //Variable Constructor
        Home(std::string new_name);

        //get_name function will return name of the home
        std::string get_name();

        //set_name function will set name of home
        void set_name(std::string name);

        //add_room Function will add a room to the house
        void add_room(std::string interactable_name);

        //remove_room Function will remove a room from the house
        void remove_room(Room* roomtoRemove);

        //list_rooms Function will return the list of rooms in the house
        void list();

        //Default Destructor
        ~Home();

};

#endif //HOME_H_
