#include <iostream>
#include "../Server/server.h"

int main()
{
	SERVER_QUEST::Server server;
	server.display();
	system("pause");

	std::cout << "Hello World!" << std::endl;
}