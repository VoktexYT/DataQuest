#ifndef SERVER_H
#define SERVER_H



#include <iostream>
#include "../WebScraping/webscraping.h"

namespace SERVER_QUEST
{
	class Server
	{
		public:
			void display()
			{
				WEB_SCRAPING::WebScraping ws;
				std::string data = ws.get_data();

				std::cout << data << std::endl;
			}
	};
}

#endif
