
/*
#include <iostream>

#include "webscraping.h"

// Prend url et extrait le html du site
// stocké les donné dans un dossier
// Module pour filtré le html
// renvoie les donnée que nous voullons dans une variable ou un dossier

 Exemple fait par Ubert
int main()
{
	WEB_SCRAPING::WebScraping ws;

	std::string data = ws.get_data();

	std::cout << data << std::endl;
}
*/

// test Web-scrapping utilisant les blibliothèque :
#include <Windows.h> // Inclut les définition pour les fonctionnalités du système WINDOWS
#include <winhttp.h> // Contient les définition spécifique à L'API WinHTTP, qui gère les connexions HTTP
#include <iostream> // Entrée-Sortie
using namespace std;

#pragma comment(lib, "winhttp.lib") // Lie la Blibiothèque winhttp.lib, permet l'utilisation des fonctions de WinHTTP.h

int main()
{
	setlocale(LC_ALL, "");
	// URL de la page à WEBSCRAP
	/* Ne fonctionne pas.
	string adressWeb = "o";
	cout << "Entrez l'url de la page désiré: ";
	cin >> adressWeb;

	LPCWSTR url = adressWeb;
	*/

	// LPCWSTR est une chaine unicode (Large pointer to constant wide string)
	LPCWSTR url = L"www.wikipedia.org/"; // url = hote/domaine
	LPCWSTR chemin = L"/"; // le chemin

	// Initialisation de la session a l'aide de WinHttp
	
	HINTERNET hSession = WinHttpOpen(L"Webscrapper/1.0",
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS, 0);

	// Vérifis si la session a été créer avec succès

	if (hSession)
	{
		HINTERNET hConnection = WinHttpConnect(hSession, url, INTERNET_DEFAULT_HTTPS_PORT, 0);

		if (hConnection)
		{
			 // Prépare une requête HTTP

			HINTERNET hRequete = WinHttpOpenRequest(hConnection, L"GET", chemin,
				NULL, WINHTTP_NO_REFERER,

				WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
			// Vérifie si la requete a été ouverte avec succès
			if (hRequete)
			{
				// Envoie la requête
				BOOL bResulats = WinHttpSendRequest(hRequete, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);

				// Reçois la réponse
				if (bResulats)
				{
					bResulats = WinHttpReceiveResponse(hRequete, NULL);
				}
				// Si la réponse a été reçu avec succès
				if (bResulats)
				{
					DWORD dwSize = 0;
					DWORD dwtelechargee = 0;
					LPSTR pszTamponSortie;
					
					BOOL bContinue = TRUE;

					// lis les données en boucle

					do
					{
						// Vérifie la taille des donnés disponible
						dwSize = 0;
						if (!WinHttpQueryDataAvailable(hRequete, &dwSize))
						{
							cout << "Erreur Lors de la vérification des données disponible.\n";
						}
						// Vérifie si les données sont disponible
						if (dwSize > 0)
						{
							// Alloue un tempon pour les données
							pszTamponSortie = new char[dwSize + 1];
							// vérifie si l'allocation de la mémoire à réeussi
							if (!pszTamponSortie)
							{
								cout << "Mémoire insuffisante.\n";
							}
						}

					} while (true);

				}
			}
		}

	}



}

