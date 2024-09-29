
/*
#include <iostream>

#include "webscraping.h"

// Prend url et extrait le html du site
// stock� les donn� dans un dossier
// Module pour filtr� le html
// renvoie les donn�e que nous voullons dans une variable ou un dossier

 Exemple fait par Ubert
int main()
{
	WEB_SCRAPING::WebScraping ws;

	std::string data = ws.get_data();

	std::cout << data << std::endl;
}
*/

// test Web-scrapping utilisant les bliblioth�que :
#include <Windows.h> // Inclut les d�finition pour les fonctionnalit�s du syst�me WINDOWS
#include <winhttp.h> // Contient les d�finition sp�cifique � L'API WinHTTP, qui g�re les connexions HTTP
#include <iostream> // Entr�e-Sortie
using namespace std;

#pragma comment(lib, "winhttp.lib") // Lie la Blibioth�que winhttp.lib, permet l'utilisation des fonctions de WinHTTP.h

int main()
{
	setlocale(LC_ALL, "");
	// URL de la page � WEBSCRAP
	/* Ne fonctionne pas.
	string adressWeb = "o";
	cout << "Entrez l'url de la page d�sir�: ";
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

	// V�rifis si la session a �t� cr�er avec succ�s

	if (hSession)
	{
		HINTERNET hConnection = WinHttpConnect(hSession, url, INTERNET_DEFAULT_HTTPS_PORT, 0);

		if (hConnection)
		{
			 // Pr�pare une requ�te HTTP

			HINTERNET hRequete = WinHttpOpenRequest(hConnection, L"GET", chemin,
				NULL, WINHTTP_NO_REFERER,

				WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
			// V�rifie si la requete a �t� ouverte avec succ�s
			if (hRequete)
			{
				// Envoie la requ�te
				BOOL bResulats = WinHttpSendRequest(hRequete, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);

				// Re�ois la r�ponse
				if (bResulats)
				{
					bResulats = WinHttpReceiveResponse(hRequete, NULL);
				}
				// Si la r�ponse a �t� re�u avec succ�s
				if (bResulats)
				{
					DWORD dwSize = 0;
					DWORD dwtelechargee = 0;
					LPSTR pszTamponSortie;
					
					BOOL bContinue = TRUE;

					// lis les donn�es en boucle

					do
					{
						// V�rifie la taille des donn�s disponible
						dwSize = 0;
						if (!WinHttpQueryDataAvailable(hRequete, &dwSize))
						{
							cout << "Erreur Lors de la v�rification des donn�es disponible.\n";
						}
						// V�rifie si les donn�es sont disponible
						if (dwSize > 0)
						{
							// Alloue un tempon pour les donn�es
							pszTamponSortie = new char[dwSize + 1];
							// v�rifie si l'allocation de la m�moire � r�eussi
							if (!pszTamponSortie)
							{
								cout << "M�moire insuffisante.\n";
							}
						}

					} while (true);

				}
			}
		}

	}



}

