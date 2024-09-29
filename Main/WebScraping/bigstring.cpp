#include <windows.h>
#include <winhttp.h>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "bigstring.h"


// Fonction pour convertire les string mince à des grand string (std::string -> std::wstring)
std::wstring stringAGrandString(const std::string& str)
{
	setlocale(LC_ALL, "");

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convertisseur;

	return convertisseur.from_bytes(str);


}
