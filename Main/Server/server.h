#ifndef SERVER_H
#define SERVER_H

#define PORT 7192
#define ROOT_URL "/"
#define SHOW_USERNAME_URL "/show/<path>"


#include <iostream>

#include "../WebScraping/webscraping.h"
#include "./Crow/include/crow.h"



namespace SERVER_QUEST
{
	class CrowServer
	{
		private:
			crow::SimpleApp app;

			/*
			* A simple Hello World root API. The URL is http://127.0.0.1:7192/
			*/
			void send_hello_word()
			{
				CROW_ROUTE(app, ROOT_URL) 
				([]() {
					return "Hello World";
				});
			}

			/*
			* A simple Hello <user> API (GET). This function is used to get param in url
			*/
			void hello_user()
			{
				CROW_ROUTE(app, SHOW_USERNAME_URL)
				([](std::string user) {
					return "Hello " + user;
				});
			}

		public:
			CrowServer()
			{
				send_hello_word();
				hello_user();
			}

			void start()
			{
				app.port(PORT).multithreaded().run();
			}
	};
}

#endif
