/*
*
* WARNING
*
* It's very important to be up to date with the C++ langage for the version 17
*
*/


#include <iostream>
#include "server.h"
#include "Fonctions.h"

int main()
{
    std::wstring test = stringAGrandString("hello");
    //std::string allHtml = get_All_Html(std::string("www.google.com"));
    //std::cout << allHtml << std::endl;

    SERVER_QUEST::CrowServer Cs;
    Cs.start();

    return 0;
}