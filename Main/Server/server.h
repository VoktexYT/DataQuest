#ifndef SERVER_H
#define SERVER_H

#define PORT 7192
#define ROOT_URL "/"


#include <iostream>

#include "../WebScraping/webscraping.h"
#include "./Crow/include/crow.h"



namespace SERVER_QUEST
{
	class CrowServer
	{
		private:
			crow::SimpleApp app;

			void send_hello_word()
			{
				CROW_ROUTE(app, ROOT_URL) 
				([]() {
					return "Hello World";
				});
			}

		public:
			CrowServer()
			{
				send_hello_word();
			}

			void start()
			{
				app.port(PORT).multithreaded().run();
			}
	};
}

#endif
