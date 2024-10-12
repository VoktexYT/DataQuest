#pragma once
#include <string>

namespace WebscrapingLib
{
	class Fonctions
	{
	private:
		// Fonction pour supprimer les balises HTML
		static std::string remove_html_tags(const std::string& html);

		// Fonction pour convertir std::string en std::wstring
		static std::wstring string_to_large_string(const std::string& str);

	public:
		// Fonction pour recuperer tout le contenu HTML depuis une URL
		static std::string get_all_html(const std::string& entreeUrl);

		// Fonction pour recuperer tout le texte depuis une URL
		static std::string get_all_text(const std::string& entreeURL);
	};
}
