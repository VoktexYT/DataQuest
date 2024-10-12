#include "WebscrapingLibrary.h"

#include <windows.h>
#include <winhttp.h>
#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>



namespace WebscrapingLib
{
    // Fonction pour convertir std::string en std::wstring
    std::wstring WebscrapingLib::Fonctions::string_to_large_string(
        const std::string& str
    ) {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convertisseur;
        return convertisseur.from_bytes(str);
    }

    // Fonction pour supprimer les balises HTML
    std::string WebscrapingLib::Fonctions::remove_html_tags(
        const std::string& html
    ) {
        std::string sortie;
        bool dansBalise = false;

        for (char c : html)
        {
            if (c == '<') {
                dansBalise = true;
            }
            else if (c == '>') {
                dansBalise = false;
            }
            else if (!dansBalise) {
                sortie += c;
            }
        }

        return sortie;
    }


    // Fonction pour recuperer tout le contenu HTML depuis une URL
    std::string WebscrapingLib::Fonctions::get_all_html(
        const std::string& entreeURL
    ) {
        system("cls");
        std::wstring url = string_to_large_string(entreeURL);
        LPCWSTR chemin = L"/";
        std::string resultat;  // Pour stocker le contenu HTML

        HINTERNET hSession = WinHttpOpen(L"WebScraper/1.0",
            WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
            WINHTTP_NO_PROXY_NAME,
            WINHTTP_NO_PROXY_BYPASS, 0);

        if (hSession) {
            HINTERNET hConnection = WinHttpConnect(hSession, url.c_str(), INTERNET_DEFAULT_HTTP_PORT, 0);

            if (hConnection) {
                HINTERNET hRequete = WinHttpOpenRequest(hConnection, L"GET", chemin, NULL,
                    WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

                if (hRequete) {
                    BOOL bResults = WinHttpSendRequest(hRequete, WINHTTP_NO_ADDITIONAL_HEADERS,
                        0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);

                    if (bResults) {
                        bResults = WinHttpReceiveResponse(hRequete, NULL);
                    }

                    if (bResults) {
                        DWORD dwSize = 0;
                        DWORD dwDownloaded = 0;
                        std::vector<char> buffer;

                        do {
                            if (!WinHttpQueryDataAvailable(hRequete, &dwSize)) {
                                std::cerr << "Erreur lors de la v�rification des donn�es disponibles.\n";
                            }

                            if (dwSize > 0) {
                                buffer.resize(dwSize + 1, 0);  // Allouer le tampon
                                if (WinHttpReadData(hRequete, buffer.data(), dwSize, &dwDownloaded)) {
                                    buffer[dwDownloaded] = '\0';
                                    resultat.append(buffer.data());  // Ajouter les donn�es re�ues au r�sultat
                                }
                            }
                        } while (dwSize > 0);
                    }

                    WinHttpCloseHandle(hRequete);
                }

                WinHttpCloseHandle(hConnection);
            }

            WinHttpCloseHandle(hSession);
        }
        else {
            std::cerr << "Erreur lors de l'ouverture de la session WinHTTP.\n";
        }

        return resultat;  // Retourner le contenu HTML
    }


    // Fonction pour r�cup�rer le texte sans balises HTML depuis une URL
    std::string WebscrapingLib::Fonctions::get_all_text(
        const std::string& entreeURL
    ) {
        system("cls");
        std::wstring url = string_to_large_string(entreeURL);
        LPCWSTR chemin = L"/";
        std::string resultat;  // Pour stocker le contenu textuel

        HINTERNET hSession = WinHttpOpen(L"WebScraper/1.0",
            WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
            WINHTTP_NO_PROXY_NAME,
            WINHTTP_NO_PROXY_BYPASS, 0);

        if (hSession) {
            HINTERNET hConnection = WinHttpConnect(hSession, url.c_str(), INTERNET_DEFAULT_HTTP_PORT, 0);

            if (hConnection) {
                HINTERNET hRequete = WinHttpOpenRequest(hConnection, L"GET", chemin, NULL,
                    WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

                if (hRequete) {
                    BOOL bResults = WinHttpSendRequest(hRequete, WINHTTP_NO_ADDITIONAL_HEADERS,
                        0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);

                    if (bResults) {
                        bResults = WinHttpReceiveResponse(hRequete, NULL);
                    }

                    if (bResults) {
                        DWORD dwSize = 0;
                        DWORD dwDownloaded = 0;
                        std::vector<char> buffer;

                        do {
                            if (!WinHttpQueryDataAvailable(hRequete, &dwSize)) {
                                std::cerr << "Erreur lors de la v�rification des donn�es disponibles.\n";
                            }

                            if (dwSize > 0) {
                                buffer.resize(dwSize + 1, 0);  // Allouer le tampon
                                if (WinHttpReadData(hRequete, buffer.data(), dwSize, &dwDownloaded)) {
                                    buffer[dwDownloaded] = '\0';
                                    std::string contenu(buffer.data());
                                    resultat.append(remove_html_tags(contenu));  // Supprimer les balises HTML
                                }
                            }
                        } while (dwSize > 0);

                        WinHttpCloseHandle(hRequete);
                    }

                    WinHttpCloseHandle(hConnection);
                }

                WinHttpCloseHandle(hSession);
            }
            else {
                std::cerr << "Erreur lors de l'ouverture de la session WinHTTP.\n";
            }

            return resultat;  // Retourner le texte sans balises HTML
        }
    }
}

