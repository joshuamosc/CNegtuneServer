//
// Created by eter on 25/06/2023.
//

#include "../headers/CNegtuneServerDirectives.h"

using namespace std;

namespace fs = filesystem;

string loadServerFromFile(string server_file, string cnegtune_files_dir) {

    string fullPath;
    bool passFile = false, errorFile = false, passValid = false, errorValid = false;

    while ( !passValid ) {
        while( !passFile ) {

            clrscr();

            cout << "\n-- Load a server from another directory --\n";
            if ( errorFile ) {
                cout << "\n[x] The server configuration file doesn't exist!\n";
            }
            if ( errorValid ) {
                cout << "\n[x] The server configuration file isn't valid, please visit https://github.com/joshuamosc/CNegtuneServer to get help about the configuration patterns!\n";
            }
            cout << "\n[*] Please enter the full path of the server configuration file...\n\n";
            cout << "[CNegtune Server]> ";
            getline(cin, fullPath);
            bool exists = fileExists(fullPath);

            if ( exists ) {
                errorFile = false;
                passFile = true;
            } else {
                errorFile = true;
            }
            errorValid = false;
        }
        bool verifyValid = verifyValidServerConfFile(fullPath, cnegtune_files_dir, true);

        if ( verifyValid ) {
            passValid = true;
        } else {
            errorValid = true;
            passFile = false;
        }
    }

    fs::copy_file(fullPath, server_file);

    return fullPath;
}
