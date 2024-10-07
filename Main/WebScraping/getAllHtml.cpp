#include "bigstring.h"
#include "getAllHtml.h"


// Demande l'url à l'utilisateur

void get_All_Html(std::string& entreeURL)
{


	system("cls");
	std::wstring url = stringAGrandString(entreeURL);
	LPCWSTR chemin = L"/";

	// Initialiser une session avec WinHTTP
	HINTERNET hSession = WinHttpOpen(L"WebScraper/1.0",
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS, 0);

	// Vérifier si la session a été créée avec succès
	if (hSession) {
		// Connecter à l'hôte
		HINTERNET hConnection = WinHttpConnect(hSession, url.c_str(),
			INTERNET_DEFAULT_HTTP_PORT, 0);

		if (hConnection) {
			// Préparer une requête HTTP
			HINTERNET hRequete = WinHttpOpenRequest(hConnection, L"GET", chemin,
				NULL, WINHTTP_NO_REFERER,
				WINHTTP_DEFAULT_ACCEPT_TYPES,
				0);

			// Vérifier si la requête a été ouverte avec succès
			if (hRequete) {
				// Envoyer la requête
				BOOL bResults = WinHttpSendRequest(hRequete,
					WINHTTP_NO_ADDITIONAL_HEADERS,
					0, WINHTTP_NO_REQUEST_DATA, 0,
					0, 0);

				// Recevoir la réponse
				if (bResults) {
					bResults = WinHttpReceiveResponse(hRequete, NULL);
				}

				// Si la réponse a été reçue avec succès
				if (bResults) {
					DWORD dwSize = 0;
					DWORD dwDownloaded = 0;
					LPSTR pszSortieTempon;
					BOOL  bContinue = TRUE;

					// Lire les données en boucle
					do {
						// Vérifier la taille des données disponibles
						dwSize = 0;
						if (!WinHttpQueryDataAvailable(hRequete, &dwSize)) {
							std::cout << "Erreur lors de la vérification des données disponibles.\n";
						}

						// Si des données sont disponibles
						if (dwSize > 0) {
							// Allouer un tampon pour les données
							pszSortieTempon = new char[dwSize + 1];

							// Vérifier si l'allocation mémoire a réussi
							if (!pszSortieTempon) {
								std::cout << "Mémoire insuffisante.\n";
								dwSize = 0;
							}
							else {
								// Initialiser le tampon
								ZeroMemory(pszSortieTempon, dwSize + 1);

								// Lire les données
								if (WinHttpReadData(hRequete, (LPVOID)pszSortieTempon,
									dwSize, &dwDownloaded)) {
									// Afficher les données reçues

									std::cout << pszSortieTempon;
								}

								// Libérer la mémoire allouée
								delete[] pszSortieTempon;
							}
						}
						// Continuer à lire tant qu'il y a des données disponibles
					} while (dwSize > 0);
				}

				// Fermer la requête
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
}