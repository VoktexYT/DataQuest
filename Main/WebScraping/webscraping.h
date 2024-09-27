#ifndef WEBSCRAPING_H
#define WEBSCRAPING_H

#include <iostream>


namespace WEB_SCRAPING
{
	class WebScraping
	{
		public:
			std::string get_data()
			{
				return "{\"msg\": \"Hello World\"}";
			}
	};
}


#endif // WEBSCRAPING_H
