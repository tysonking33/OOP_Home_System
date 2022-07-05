
#ifndef MEMBERS_H_
#define MEMBERS_H_

#include <iostream>

class Members{

    private:
        std::string name;       //name of the member
        bool access_level;      //access level of the member (either 1 or 0)

    public:
    
    //Default Constructor
    Members();

    //Variable Constructor
    Members(std::string member_name, bool access_lvl);

    //set_name function
    void set_name(std::string Name);

    //get_name function
    std::string get_name();

    //set_access_level function
    void set_access_level(bool value);

    //get_access_level function
    bool get_access_level();

    //Default Destructor
    ~Members();

};

#endif //MEMBERS_H_