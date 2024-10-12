/*
*
* WARNING
*
* It's very important to be up to date with the C++ langage for the version 17
*
*/


#include <iostream>
#include "ServerLibrary.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    ServerLib::CrowServer Cs;
    Cs.start();

    return 0;
}