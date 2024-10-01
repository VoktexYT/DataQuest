#include <windows.h>
#include <winhttp.h> 
#include <iostream> 
#include "bigstring.h"
#include "getAllHtml.h"
#include "getAllText.h"


#pragma comment(lib, "winhttp.lib")


int main()
{
	setlocale(LC_ALL, "");

	std::string entreeURL;
	char fonctionBase;
	std::cout << "Entrée l'url d'un site Web sous se format : www.example.com\n\nVous: ";
	std::cin >> entreeURL;
	std::cout << "\n\nChoisissez une des fonction suivante :\n\n[A] get-all-html\n[B] get-all-texts\n\nToi: ";
	std::cin >> fonctionBase;

	while (fonctionBase != 'A' && fonctionBase != 'B')
	{
		system("cls");
		std::cout << "Erreur!!!\n\nChoisissez une des fonction suivante : \n\nget-all-html\nget-all-texts\n\nVous: ";
		std::cin >> fonctionBase;

	}
	if (fonctionBase == 'A')
	{
		get_All_Html(entreeURL);
	}
	else if (fonctionBase == 'B')
	{
		get_All_Text(entreeURL);
	}
	else
	{
		std::cout << "Erreur 404";
	}



	// Codée par Bone230 
	// Version 2.3

	return 0;
}

