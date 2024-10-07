#define PORT 7192

#define ROOT_URL "/"
#define SHOW_USERNAME_URL "/show/<path>"
#define GET_ALL_HTML_URL "/get-all-html"
#define GET_ALL_TEXT_URL "/get-all-text"

#include <iostream>
#include <functional>

#include "crow.h"

#include "Fonctions.h"
#include "server.h"



namespace SERVER_QUEST
{
	std::string getUrlRequest(
		crow::request req,
		const std::function<std::string(std::string)>& callback_done,
		const std::function<std::string()>& callback_error
	) {
		const std::string URL_PARAM_NAME = "url";
		const auto URL_VALUE = req.url_params.get(URL_PARAM_NAME);

		if (URL_VALUE)
		{
			const std::string URL_VALUE_STRING = std::string(URL_VALUE);
			callback_done(URL_VALUE_STRING);

			return callback_done(URL_VALUE_STRING);
		}

		return callback_error();
	}

	crow::SimpleApp app;

	void CrowServer::send_hello_word()
	{
		CROW_ROUTE(app, ROOT_URL)
			([]() {
			return "Hello World";
				});
	}

	void CrowServer::hello_user()
	{
		CROW_ROUTE(app, SHOW_USERNAME_URL)
			([](std::string user) {
			return "Hello " + user;
				});
	}

	void CrowServer::get_all_html()
	{
		CROW_ROUTE(app, GET_ALL_HTML_URL)
			([](const crow::request& req) {
			return getUrlRequest(req,
				[](std::string url) {
					return std::string("Request Accepted!");
				},
				[]() {
					return std::string("The request is rejected");
				}
			);
				});
	}

	
	CrowServer::CrowServer()
	{
		send_hello_word();
		hello_user();
		get_all_html();
	}

	void CrowServer::start()
	{
		app.port(PORT).multithreaded().run();
	};
}

