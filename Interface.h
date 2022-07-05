#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <any>
#include <utility>
#include <fstream>


#include "Room.h"
#include "Interactable.h"

#include "AC_Unit.h"
#include "Door.h"
#include "Lights.h"
#include "Media_Device.h"
#include "Smart_Television.h"
#include "Smart_Speaker.h"

using namespace std;

class Interface
{
  private:
      Home * home;

  public:
      //Constructor takes in a pointer to the home with whcih we will operate on
      Interface(Home * home);
      ~Interface();
      //Clears the screen and produces the header for the screen
      void header();

      //Initiates the console loop
      void console();

      //reads in the input from the user and changes it into a vector of strings
      vector<string> getCommand();

      //figures out what kind of command it is and runs the corresponding function
      bool runCommand(vector<string> command);

      //prints the synta guide from a file
      void helpScreen();

      //is used for the "set" command, changing the values of the objects
      int set(vector<string> command);

      //adding rooms to the house opr interactables to the room
      //validates input and figures out whether to add room or interactable
      int add(vector<string> command);

      //for removing rooms from the home or interactables from the rooms
      int remove(vector<string> command);

      //returns a pointer the room with name roomName
      Room * findRoom(string roomName);

      //returns pointer to interactable with name deviceName in the room roomToLookIn
      Interactable * findInteractable(string deviceName, Room * roomToLookIn);

      //lists the rooms in the house or interactables in a room
      int list(vector<string> command);

      void read(string savename);
      void write(string savename);

      //Checks if input is of deisred data type
      bool isInt(string input);
      bool isFloat(string input);



};

#endif
