#include <windows.h>
#include <winhttp.h> 
#include <iostream> 
#include "Fonctions.h"


#pragma comment(lib, "winhttp.lib")


#include <windows.h>
#include <winhttp.h> 
#include <iostream> 
#include "Fonctions.h"

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

	// Boucle pour valider l'entrée utilisateur
	while (fonctionBase != 'A' && fonctionBase != 'B')
	{
		system("cls");
		std::cout << "Erreur!!!\n\nChoisissez une des fonctions suivantes : \n\n[A] get-all-html\n[B] get-all-texts\n\nVous: ";
		std::cin >> fonctionBase;
	}

	// Variable pour stocker le résultat
	std::string resultat;

	// Appel de la fonction en fonction du choix de l'utilisateur
	if (fonctionBase == 'A')
	{
		resultat = get_All_Html(entreeURL);  // Stocker le résultat de get_All_Html
	}
	else if (fonctionBase == 'B')
	{
		resultat = get_All_Text(entreeURL);  // Stocker le résultat de get_All_Text
	}
	else
	{
		std::cout << "Erreur 404\n";
	}

	// Afficher le résultat
	std::cout << "\n\nRésultat :\n" << resultat << std::endl;


	// Codée par Bone230 
	// Version 2.6		22:14 2024-10-05
	// regrouppement de toutes les bibliotheque en une seule
	// les Fonction on maintenant des return
	// Les void on été remplacer par des strings avec des réturns et main a été changer avec
	// une nouvelle variable resultat afin de faire apparaitre le html
	// résolution des pertes de donné dans le code
	// and minor fixes

	return 0;
}

