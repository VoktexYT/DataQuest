#include "WebscrapingLibrary.h"

#include <windows.h>
#include <winhttp.h> 
#include <iostream> 

#pragma comment(lib, "winhttp.lib")


int main()
{
	setlocale(LC_ALL, "");

	std::string entreeURL;
	char fonctionBase;
	std::cout << "Entrez l'URL d'un site Web sous ce format : www.example.com\n\nVous: ";
	std::cin >> entreeURL;
	std::cout << "\n\nChoisissez une des fonctions suivantes :\n\n[A] get-all-html\n[B] get-all-texts\n\nVous: ";
	std::cin >> fonctionBase;

	// Boucle pour valider l'entr�e utilisateur
	while (fonctionBase != 'A' && fonctionBase != 'B')
	{
		system("cls");
		std::cout << "Erreur!!!\n\nChoisissez une des fonctions suivantes : \n\n[A] get-all-html\n[B] get-all-texts\n\nVous: ";
		std::cin >> fonctionBase;
	}

	// Variable pour stocker le r�sultat
	std::string resultat;

	// Appel de la fonction en fonction du choix de l'utilisateur
	if (fonctionBase == 'A')
	{
		resultat = WebscrapingLib::Fonctions::get_all_html(entreeURL);  // Stocker le r�sultat de get_All_Html
	}
	else if (fonctionBase == 'B')
	{
		resultat = WebscrapingLib::Fonctions::get_all_text(entreeURL);  // Stocker le r�sultat de get_All_Text
	}
	else
	{
		std::cout << "Erreur 404\n";
	}

	// Afficher le r�sultat
	std::cout << "\n\nR�sultat :\n" << resultat << std::endl;


	// Cod�e par Bone230 
	// Version 2.6		22:14 2024-10-05
	// regrouppement de toutes les bibliotheque en une seule
	// les Fonction on maintenant des return
	// Les void on �t� remplacer par des strings avec des r�turns et main a �t� changer avec
	// une nouvelle variable resultat afin de faire apparaitre le html
	// r�solution des pertes de donn� dans le code
	// and minor fixes

	return 0;
}
