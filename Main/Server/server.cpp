/*
* 
* WARNING
* 
* It's very important to be up to date with the C++ langage for the version 17
* 
*/


#include <iostream>

#include "server.h"

#include "crow.h"

int main()
{
    SERVER_QUEST::CrowServer Cs;
    Cs.start();

    std::cout << "Test123" << std::endl;

    return 0;
}
