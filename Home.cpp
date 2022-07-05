
#include <iostream>
#include <vector>
#include "Room.h"
#include "Home.h"

//Default Constructor
Home::Home(){
    home_name = "N/A";
    numRooms = 0;
    rooms = new std::vector<Room*>;
    rooms->clear();
};

//Variable Constructor
Home::Home(std::string new_name){
    home_name = new_name;
    numRooms = 0;
    rooms = new std::vector<Room*>;
    rooms->clear();

};

//get_name function will return the name of the home
std::string Home::get_name(){
    return home_name;
}

//set_name function will set the name of the home given a string
void Home::set_name(std::string name){
    home_name = name;
}

//add_room function will create a room and add it to the list of rooms inside the home
void Home::add_room(std::string room_name){

    Room* CreatedRoom = new Room();
    CreatedRoom->set_name(room_name);
    rooms->push_back(CreatedRoom);
    std::cout << "Room has been successfully created and added to Home." << std::endl;

};


//remove_room function will remove a room from a home
void Home::remove_room(Room* roomtoRemove){

    int position;
    for (int i = 0; i < rooms->size(); i++){
        if (rooms->at(i) == roomtoRemove){
            position = i;
        }
    };

    rooms->erase(rooms->begin()+position);
    std::cout << "Room has been successfully removed from Home." << std::endl;

};

//list_rooms function will print all the rooms inside a home
void Home::list(){

    std::cout << "Rooms:" << std::endl;
    for (int i = 0; i < rooms->size(); i++){
        std::cout << rooms->at(i)->get_name() << std::endl;
    };

    std::cout << std::endl;
    std::cout << "All rooms have been successfully printed." << std::endl;

};

//Default Destructor
Home::~Home(){
    delete [] rooms;
    std::cout << "Home has been destroyed." << std::endl;

}
