#include "Interface.h"



Interface::Interface(Home * home) :home(home)
{
    //clears the screen and resets the cursor
    cout << "\033[2J \033[H";
}

Interface::~Interface()
{

}


void Interface::header()
{
    cout << "\u001b[32;1m";
    cout << R"(___   _ . ____    _  _ _ ____ ___ _  _ ____ _       ____ _  _ ____ ____ ___    _  _ ____ _  _ ____    ____ _   _ ____ ___ ____ _  _ )" << endl;
    cout << R"(|  \  | ' [__     |  | | |__/  |  |  | |__| |       [__  |\/| |__| |__/  |     |__| |  | |\/| |___    [__   \_/  [__   |  |___ |\/| )" << endl;
    cout << R"(|__/ _|   ___]     \/  | |  \  |  |__| |  | |___    ___] |  | |  | |  \  |     |  | |__| |  | |___    ___]   |   ___]  |  |___ |  | )" << endl;
    cout << "Enter commands below" << endl;
    cout << "Type \"help\" for command line help" << endl;
    cout << "Type \"exit\" to exit application" << endl;
}

void Interface::console()
{
    vector<string> command;
    do
    {
        cout << "\u001b[36;1m";
        cout << ">>> ";
        //sets the input colour to white
        cout << "\u001b[0m";
        command = getCommand();

        //Interpret commands
        //If exit command leave this loop

    } while(runCommand(command));

};

vector<string> Interface::getCommand()
{
    //The actual command line that is input,
    string input;
    //a vector of strings, where each word is an individual element
    vector<string> command;

    //Gets line entire line from cin and stores it in input
    getline(cin,input);
    //some magic
    istringstream ss(input);

    //the string that will store the individual pieces and push them into the vector
    string del;

    //reads each word of the input in and spilts it at the delimiter ' '
    while(getline(ss, del, ' '))
    {
      command.push_back(del);
    }


    //returns the vector of strings
    return command;
};

bool Interface::runCommand(vector<string> command)
{
    //setup the maximum and minimun size for maxCommandSize
    const int minCommandSize = 0;
    const int maxCommandSize = 5;

    //Check that the command is not empty, if it is, just reset the console
    if(command.size() == minCommandSize) {return 1;}


    if(command.at(0) == "help") {helpScreen(); return 1;}
    if(command.at(0) == "exit") {return 0;}

    if(command.at(0) == "add")  {add(command); return 1;}
    if(command.at(0) == "remove") {remove(command); return 1;}
    if(command.at(0) == "set") {set(command); return 1;}
    if(command.at(0) == "list") {list(command); return 1;}
    if(command.at(0) == "write")
    {
        if(command.size() == 2){write(command.at(1));}
        else{
            cout << "\u001b[31;1m" << endl;
            cout << "Follow the write command sytax:" << endl;
            cout << endl;
            cout << "write [save_name]" << endl;
            cout << endl;
        }
        return 1;
    }
    if(command.at(0) == "read")
    {
        if(command.size() == 2){read(command.at(1));}
        else{
            cout << "\u001b[31;1m" << endl;
            cout << "Follow the read command sytax:" << endl;
            cout << endl;
            cout << "read [save_name]" << endl;
            cout << endl;
        }
        return 1;
    }

    //If all opptions exhausted, must not be valid
    else {cout << "\u001b[31;1m"  << "command \"" << command.at(0) << "\" not recognised" << endl; return 1;}
}

void Interface::helpScreen()
{
    cout << "\u001b[33;1m" << endl;
    cout << "*************************************************************************************************************" << endl;

    //reads in the file Syntax_Guide.txt
    //this keeps the boring text out of the contesnts of the program itself
    ifstream f("Syntax_Guide.txt");
    if (f.is_open())
        std::cout << f.rdbuf();

    cout << "*************************************************************************************************************" << endl;
    cout << endl;
}

Room * Interface::findRoom(string roomName)
{
    //Checks through the list of rooms
    for (size_t i = 0; i < home->rooms->size(); i++)
    {
        //the iterator is a pointer to the ith room in the list
        Room * iterator = (home->rooms->at(i));
        //check what the name of this room is and if it is the wanted one
        //return a pointer to this room
        if (iterator->room_name == roomName) {return iterator;}
    }

    return nullptr;
}

Interactable * Interface::findInteractable(string deviceName, Room * roomToLookIn)
{
    for (size_t i = 0; i < roomToLookIn->interactables->size(); i++)
    {
        //the iterator is a pointer to the ith room in the list
        Interactable * iterator = (roomToLookIn->interactables->at(i));
        //check what the name of this room is and if it is the wanted one
        //return a pointer to this room
        if (iterator->get_name() == deviceName) {return iterator;}
    }

    return nullptr;
}


int Interface::add(vector<string> command)
{
    if(command.size() < 3)
    {
        cout << "\u001b[31;1m" << endl;
        cout << "Cannot process \"add\" command" << endl;
    }

    //Add Room
    if(command.at(1) == "Room")
    {
        //create a room in the house object with a name input from the command
        //command.at(2) is a string and a room will be created with that name
        home->add_room(command.at(2));
        return 1;
        //exit this function as the command has been completed
    }

    //now need to change the command check length as all other commands are bigger
    if(command.size() < 4)
    {
        cout << "\u001b[31;1m" << endl;
        cout << "No type to add: \"" << command.at(1) << "\" OR insufficient Command Length to add Interactable device of type: " << command.at(1) << endl;
    }
    else
    {
        //Add Device
        //gets a pointer to the rooms we want to operate in
        Room * deviceRoom = findRoom(command.at(3));
        //If this pointer is null we've got an error
        if(deviceRoom == nullptr)
        {
            cout << "\u001b[31;1m" << endl;
            cout << "No rooms of name: " << command.at(3) << endl;
        }
        else
        {
            //Pass first of all a string dictating the type of object
            //Pass second the name of the device to create
            //This will be used to create a device of the required type in the correct room
            deviceRoom->add_interactable(command.at(1), command.at(2));
            return 1;
        }
    }



    cout << endl;
    cout << "Follow \"add\" command syntax:" << endl;
    cout << endl;
    cout << "add Room [room_name]" << endl;
    cout << "or" << endl;
    cout << "add [interactable_type] [interactable_name] [room_name]" << endl;
    cout << endl;

    return 0;
}


int Interface::remove(vector<string> command)
{

    if(command.size() < 2)
    {
        cout << "\u001b[31;1m" << endl;
        cout << "Incorrect argument count for \"remove\"" << endl;
    }

    //If the command only has one argument, it must be to remove a room
    if(command.size() == 2)
    {
        //makes handling this string easier
        const string room = command.at(1);
        //get the room with this name
        Room * roomToRemove = findRoom(room);
        //check its a real room, if not, let them know and exit
        if (roomToRemove == nullptr) {cout << "\u001b[31;1m"  << "No room of name " << room << endl; return 0;}
        //must be a real room, get rid of it
        home->remove_room(roomToRemove);
        return 1;
    }

    //If the command has 2 arguments, it must be to remove an interactable
    else if(command.size() == 3)
    {
        //the device and the room
        const string device = command.at(1);
        const string room = command.at(2);
        //FInd the room,
        Room * roomToRemove = findRoom(room);
        //check legitness
        if (roomToRemove == nullptr) {cout << "\u001b[31;1m"  << "No room of name " << room << endl; return 0;}
        //find the interactable
        Interactable * interactableToRemove = findInteractable(device, roomToRemove);
        //check legitness
        if(interactableToRemove == nullptr) {cout << "\u001b[31;1m" << "No interactable of name " << room << endl; return 0;}
        //must be legit, get rid of it
        roomToRemove->remove_interactable(interactableToRemove);
        return 1;
    }

    //Theyve done something wroing as the fuciton hasnt returned yet, tell them how to do thisa properl;y
    cout << "Follow \"remove\" command syntax:" << endl;
    cout << endl;
    cout << "remove [room_name]" << endl;
    cout << "or" << endl;
    cout << "remove [interactable_name] [room_name]" << endl;
    cout << endl;

    return 0;
}



int Interface::list(vector<string> command)
{
    //const string object_to_list = command.at(1);

    if(command.size() < 2)
    {
        cout << "\u001b[31;1m" << endl;
        cout << "Cannot process \"list\" command" << endl;
        cout << "Follow \"list\" command syntax:" << endl;
        cout << endl;
        cout << "list Rooms" << endl;
        cout << "or" << endl;
        cout << "list [interactable_name] [room_name]" << endl;
        cout << endl;
        return 0;
    }

    //Lists the rooms in the house
    if(command.at(1) == "Rooms")
    {
        home->list();
    }

    //Lists the devices in the specified room
    else if(findRoom(command.at(1)) != nullptr)
    {
        Room * room_to_list = findRoom(command.at(1));
        room_to_list->list();
    }

    else if((command.size() == 3) && (findRoom(command.at(2)) != nullptr))
    {
        Interactable * device_to_print = findInteractable(command.at(1), findRoom(command.at(2)));
        if(device_to_print == NULL) {cout << "No device called " << command.at(1) << " in " << command.at(2) << endl; return 0;}
        device_to_print->print();
    }

    else
    {
        cout << "\u001b[31;1m" << endl;
        cout << "Unable to list object " << command.at(1) << endl;
        cout << "Check to see if this object really exists (e.g. >>list Rooms)" << endl;

        cout << "Follow \"list\" command syntax:" << endl;
        cout << endl;
        cout << "list Rooms" << endl;
        cout << "or" << endl;
        cout << "list [interactable_name] [room_name]" << endl;
        cout << endl;
    }

    return 0;
}




int Interface::set(vector<string> command)
{
    /*
    Command structure
    0: set
    1: interactable name
    2: room it is in
    3: member to alters
    4: status to set it to
    */

    if(command.size() < 5)
    {
        cout << "\u001b[31;1m" << endl;
        cout << "Incorrect command length" << endl;
        cout << "Follow \"set\" command syntax:" << endl;
        cout << endl;
        cout << "set [interactable_name] [room_name] [property] [status]" << endl;
        cout << endl;
        return 0;
    }

    const string interactable_name = command.at(1);
    const string interactable_room = command.at(2);
    const string member = command.at(3);
    const string status = command.at(4);



    //find the room,s to work in
    Room * deviceRoom = findRoom(interactable_room);
    if(deviceRoom == nullptr) {cout << "\u001b[31;1m" << "No Room exists of name: \"" << interactable_room << "\"" << endl; return 0;}
    //find the interactable to work on
    Interactable * interactable_to_change = findInteractable(interactable_name, deviceRoom);
    if(interactable_to_change == nullptr) {cout << "\u001b[31;1m" << "No Interactable exists of name: \"" << interactable_name << "\" " << "in \"" << interactable_room << "\"" << endl; return 0;}


    //handles universal on/off functions
    if(member == "onoff")
    {
        if(status == "on") {interactable_to_change->set_state(1); return 1;}
        else if (status == "off") {interactable_to_change->set_state(0); return 1;}
        else {cout  << "\u001b[31;1m" << "Invalid on/off parameter\n Please choose from either [on] or [off]\n" << endl;}
    }

    if(member == "name") {interactable_to_change->set_name(status); return 1;}


    //Lights
    if(interactable_to_change->type == "Lights")
    {
        cout << "Altering the Light" << endl;
        Lights* actor = dynamic_cast<Lights*>(interactable_to_change);
        if(member == "colour") {actor->set_colour(status); return 1;}

    }



    if(interactable_to_change->type == "Door")
    {
        Door * actor = dynamic_cast<Door*>(interactable_to_change);
        if(member == "lock")
        {
            if(status == "unlock")  {actor->set_state(0); return 1;}
            if(status == "lock")    {actor->set_state(1); return 1;}
        }
        //if(member == "open") {actor->set_state(status)}
    }


    //AC changes
    if(interactable_to_change->type == "AC_Unit")
    {
        //dynamic cast so we knwo what we're working on here
        AC_Unit * actor = dynamic_cast<AC_Unit*>(interactable_to_change);

        //Chanegs to the temp variable
        if(member == "temp")
        {
            //checls the user input to make sure it is of the right type
            if(isFloat(status))
            {
                //enacts this change on the value through the member function and returns
                actor->set_AC_temp(stof(status));
                return 1;
            }
            else
            {
                //user input was obviously absolute rubbish. tell them what they need to input
                cout  << "\u001b[31;1m" << "Temperature Input \"" << status << "\" is not of required type - floating point number" << endl;
                return 0;
            }
        }

        if(member == "speed")
        {
            if(isInt(status))
            {
                actor->set_AC_speed(stoi(status));
                return 1;
            }
            else
            {
                cout  << "\u001b[31;1m" << "Speed Input \"" << status << "\" is not of required type - integer" << endl;
                return 0;
            }
        }
    }

    if(interactable_to_change->type == "Smart_Speaker" )
    {
        Smart_Speaker * actor = dynamic_cast<Smart_Speaker*>(interactable_to_change);
        if(member == "volume")
        {
            if(isInt(status))
            {
                actor->set_media_volume(stoi(status));
                return 1;
            }
            else
            {
                cout  << "\u001b[31;1m" << "Volume Input \"" << status << "\" is not of required type - integer" << endl;
                return 0;
            }
        }

        if(member == "channel") {actor->set_current_channel(status); return 1;}
    }

    if(interactable_to_change->type == "Smart_Television")
    {
        Smart_Television * actor = dynamic_cast<Smart_Television*>(interactable_to_change);
        if(member == "volume")
        {
            if(isInt(status))
            {
                actor->set_media_volume(stoi(status));
                return 1;
            }
            else
            {
                cout  << "\u001b[31;1m" << "Volume Input \"" << status << "\" is not of required type - integer" << endl;
                return 0;
            }
        }

        if(member == "channel") {actor->set_current_channel(status); return 1;}

        if(member == "brightness")
        {
            if(isInt(status))
            {
                actor->set_brightness_level(stoi(status));
                return 1;
            }
            else
            {
                cout  << "\u001b[31;1m" << "Brightness Input \"" << status << "\" is not of required type - integer" << endl;
                return 0;
            }
        }
    }

    cout << "\u001b[31;1m" << "Interactable Property " << member << " does not exist" << endl;

    return 0;
}

void Interface::read(string savename)
{
    ifstream inFile(savename + ".txt");
    string checker;
    getline(inFile, checker);
    if(inFile.good() && checker == "Smart Home Save")
    {
        if(home->rooms->size() > 0)
        {
            cout << "You can't read in an existing home on top of this one!" << endl;
            cout << "If you want to read that home in, either create a new instance of the interface, or delete all remaining rooms" << endl;
        }
        else
        {
            string input;
            int roomCount = -1;
            while(getline(inFile,input))
            {
                //a vector of strings, where each word is an individual element
                vector<string> line;
                string currentRoom;

                //some magic
                istringstream ss(input);

                //the string that will store the individual pieces and push them into the vector
                string del;

                //reads each word of the input in and spilts it at the delimiter ' '
                while(getline(ss, del, ' '))
                {
                  line.push_back(del);
                }

                //This means it is a room
                if(line.size() == 2 && line.at(0) == "Room")
                {
                    home->add_room(line.at(1));
                    currentRoom = line.at(1);
                    roomCount++;
                }
                else
                {

                    if(line.at(0) == "Lights")
                    {
                        Lights *CreatedLight = new Lights(line.at(3), stoi(line.at(2)));
                        CreatedLight->set_name(line.at(1));
                        home->rooms->at(roomCount)->interactables->push_back(CreatedLight);
                    }

                    if(line.at(0) == "Door")
                    {
                        Door *CreatedDoor = new Door(stoi(line.at(2)));
                        CreatedDoor->set_name(line.at(1));
                        home->rooms->at(roomCount)->interactables->push_back(CreatedDoor);
                    }

                    if(line.at(0) == "AC_Unit")
                    {
                        AC_Unit *CreatedAC = new AC_Unit(stof(line.at(3)), stoi(line.at(4)), stoi(line.at(2)));
                        CreatedAC->set_name(line.at(1));
                        home->rooms->at(roomCount)->interactables->push_back(CreatedAC);
                    }

                    if(line.at(0) == "Smart_Television")
                    {
                        Smart_Television *CreatedSmart_Television = new Smart_Television(stoi(line.at(5)));
                        CreatedSmart_Television->set_name(line.at(1));
                        CreatedSmart_Television->set_state(stoi(line.at(2)));
                        CreatedSmart_Television->set_current_channel(line.at(3));
                        CreatedSmart_Television->set_media_volume(stoi(line.at(4)));
                        home->rooms->at(roomCount)->interactables->push_back(CreatedSmart_Television);
                    }

                    if(line.at(0) == "Smart_Speaker")
                    {
                        Smart_Speaker *CreatedSmart_Speaker = new Smart_Speaker;
                        CreatedSmart_Speaker->set_name(line.at(1));
                        CreatedSmart_Speaker->set_state(stoi(line.at(2)));
                        CreatedSmart_Speaker->set_current_channel(line.at(3));
                        CreatedSmart_Speaker->set_media_volume(stoi(line.at(4)));
                        home->rooms->at(roomCount)->interactables->push_back(CreatedSmart_Speaker);
                    }
                }
            }
        }
    }

    else
    {
        cout << "No saved home found of name " << savename << "." << endl;
    }
}

void Interface::write(string savename)
{
    ofstream saveFile;
    saveFile.open (savename + ".txt", ios::out | ios::trunc);
    saveFile << "Smart Home Save\n";

    for (int i = 0; i < home->rooms->size(); i++)
    {
        Room * saveRoom = home->rooms->at(i);
        saveFile << "Room " << saveRoom->room_name << "\n";

        for (int j = 0; j < saveRoom->interactables->size(); j++)
        {
            saveFile << saveRoom->interactables->at(j)->type << " ";
            if(saveRoom->interactables->at(j)->type == "Lights")
            {
                Lights * actor = dynamic_cast<Lights*>(saveRoom->interactables->at(j));
                saveFile << actor->get_name() << " " << actor->get_state() << " " << actor->get_colour() << "\n";
            }

            if(saveRoom->interactables->at(j)->type == "Door")
            {
                Door * actor = dynamic_cast<Door*>(saveRoom->interactables->at(j));
                saveFile << actor->get_name() << " " << actor->get_state()  << "\n";
            }

            if(saveRoom->interactables->at(j)->type == "AC_Unit")
            {
                AC_Unit * actor = dynamic_cast<AC_Unit*>(saveRoom->interactables->at(j));
                saveFile << actor->get_name() << " " << actor->get_state()  << " " << actor->get_AC_temp() << " " << actor->get_AC_speed() << "\n";
            }
            if(saveRoom->interactables->at(j)->type == "Smart_Television")
            {
                Smart_Television * actor = dynamic_cast<Smart_Television*>(saveRoom->interactables->at(j));
                saveFile << actor->get_name() << " " << actor->get_state()  << " " << actor->get_current_channel() << " " << actor->get_media_volume() << " " << actor->get_brightness_level() << "\n";
            }
            if(saveRoom->interactables->at(j)->type == "Smart_Speaker")
            {
                Smart_Speaker * actor = dynamic_cast<Smart_Speaker*>(saveRoom->interactables->at(j));
                saveFile << actor->get_name() << " " << actor->get_state()  << " " << actor->get_current_channel() << " " << actor->get_media_volume() << "\n";
            }
        }
    }

    cout << "Smart Home saved into " << savename << ".txt" << endl;
    saveFile.close();
}








//These functions are utlilies taken solely to confirm the data types do each of the input values
//i do not know what they do
//i do not know how they work
//but i do know, they work
bool Interface::isFloat(string input)
{
    std::istringstream iss(input);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

bool Interface::isInt(string input)
{
    std::istringstream iss(input);
    int f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}
