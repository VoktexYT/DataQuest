#pragma once
#include <string>
#include <functional>
#include "crow.h"


namespace ServerLib
{
	std::string get_url_request(
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