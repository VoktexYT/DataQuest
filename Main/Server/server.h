#ifndef SERVER_H
#define SERVER_H

#define PORT 7192
#define ROOT_URL "/"
#define SHOW_USERNAME_URL "/show/<path>"

#define GET_ALL_HTML_URL "/get-all-html"

#pragma once

#include <iostream>
#include <functional>
#include "../WebScraping/webscraping.h"
#include "crow.h"



namespace SERVER_QUEST
{
	std::string getUrlRequest(
		crow::request req,
		const std::function<std::string(std::string)>& callback_done,
		const std::function<std::string()>& callback_error
	){
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

			/*
			* Get all html from web page API (Using url param)
			*/
			void get_all_html()
			{
				CROW_ROUTE(app, GET_ALL_HTML_URL)
				([](const crow::request &req) {
					return getUrlRequest(req, 
						[](std::string url) {
							return std::string("The request is accepted");
						},
						[]() {
							return std::string("The request is rejected");
						}
					);
				});
			}

		public:
			CrowServer()
			{
				send_hello_word();
				hello_user();
				get_all_html();
			}

			void start()
			{
				app.port(PORT).multithreaded().run();
			}
	};
}

#endif
