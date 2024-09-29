
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
#include <windows.h> // Inclut les d�finition pour les fonctionnalit�s du syst�me WINDOWS
#include <winhttp.h> // Contient les d�finition sp�cifique � L'API WinHTTP, qui g�re les connexions HTTP
#include <iostream> // Entr�e-Sortie
#include "bigstring.h"

#pragma comment(lib, "winhttp.lib")


int main()
{
	setlocale(LC_ALL, "");
	
	// Demande l'url � l'utilisateur

	std::string entreeURL;
	std::cout << "Entr�e l'url d'un site Web sous se format : www.example.com\n\nToi: ";
	std::cin >> entreeURL;
	system("cls");
	std::wstring url = stringAGrandString(entreeURL);
	LPCWSTR chemin = L"/";

	// Initialiser une session avec WinHTTP
	HINTERNET hSession = WinHttpOpen(L"WebScraper/1.0",
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS, 0);

	// V�rifier si la session a �t� cr��e avec succ�s
	if (hSession) {
		// Connecter � l'h�te
		HINTERNET hConnection = WinHttpConnect(hSession, url.c_str(),
			INTERNET_DEFAULT_HTTP_PORT, 0);

		if (hConnection) {
			// Pr�parer une requ�te HTTP
			HINTERNET hRequete = WinHttpOpenRequest(hConnection, L"GET", chemin,
				NULL, WINHTTP_NO_REFERER,
				WINHTTP_DEFAULT_ACCEPT_TYPES,
				0);

			// V�rifier si la requ�te a �t� ouverte avec succ�s
			if (hRequete) {
				// Envoyer la requ�te
				BOOL bResults = WinHttpSendRequest(hRequete,
					WINHTTP_NO_ADDITIONAL_HEADERS,
					0, WINHTTP_NO_REQUEST_DATA, 0,
					0, 0);

				// Recevoir la r�ponse
				if (bResults) {
					bResults = WinHttpReceiveResponse(hRequete, NULL);
				}

				// Si la r�ponse a �t� re�ue avec succ�s
				if (bResults) {
					DWORD dwSize = 0;
					DWORD dwDownloaded = 0;
					LPSTR pszSortieTempon;
					BOOL  bContinue = TRUE;

					// Lire les donn�es en boucle
					do {
						// V�rifier la taille des donn�es disponibles
						dwSize = 0;
						if (!WinHttpQueryDataAvailable(hRequete, &dwSize)) {
							std::cout << "Erreur lors de la v�rification des donn�es disponibles.\n";
						}

						// Si des donn�es sont disponibles
						if (dwSize > 0) {
							// Allouer un tampon pour les donn�es
							pszSortieTempon = new char[dwSize + 1];

							// V�rifier si l'allocation m�moire a r�ussi
							if (!pszSortieTempon) {
								std::cout << "M�moire insuffisante.\n";
								dwSize = 0;
							}
							else {
								// Initialiser le tampon
								ZeroMemory(pszSortieTempon, dwSize + 1);

								// Lire les donn�es
								if (WinHttpReadData(hRequete, (LPVOID)pszSortieTempon,
									dwSize, &dwDownloaded)) {
									// Afficher les donn�es re�ues
									std::cout << pszSortieTempon;
								}

								// Lib�rer la m�moire allou�e
								delete[] pszSortieTempon;
							}
						}
						// Continuer � lire tant qu'il y a des donn�es disponibles
					} while (dwSize > 0);
				}

				// Fermer la requ�te
				WinHttpCloseHandle(hRequete);
			}

			// Fermer la connexion
			WinHttpCloseHandle(hConnection);
		}

		// Fermer la session
		WinHttpCloseHandle(hSession);
	}
	else {
		std::cout << "Erreur lors de l'ouverture de la session WinHTTP.\n";
	}
	std::cout << "\n\n\n\nCod�e par Bone230\nVersion 2.0";

	return 0;
}

