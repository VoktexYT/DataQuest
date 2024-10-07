#ifndef SERVER_H
#define SERVER_H


#include "Fonctions.h"
#include <iostream>
#include <functional>
#include "crow.h"



namespace SERVER_QUEST
{
	std::string getUrlRequest(
		crow::request req,
		const std::function<std::string(std::string)>& callback_done,
		const std::function<std::string()>& callback_error
	);

	class CrowServer
	{
		private:
			void send_hello_word();
			void hello_user();
			void get_all_html();

		public:
			CrowServer();

			void start();
	};
}

#endif
