#include "Interface.h"
#include "Interactable.h"
#include "AC_Unit.h"


int main()
{
    //Home * home = ;
    Interface Manager(new Home);
    Manager.header();
    Manager.console();
    return 0;
}
