#include <iostream>

#include "webscraping.h"

int main()
{
	WEB_SCRAPING::WebScraping ws;

	std::string data = ws.get_data();

	std::cout << data << std::endl;
}
