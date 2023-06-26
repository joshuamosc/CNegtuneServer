//
// Created by eter on 24/06/2023.
//

#include "../headers/CNegtuneServerDirectives.h"

using namespace std;

void firstMenu(string server_file, string cnegtune_files_dir, struct ServerConfiguration server){

    char option;

    cout << "\n--- Welcome to CNegtune Server ---\n";
    cout << "\n1.- Configure a new server\n2.- Load server from a directory\n\n";

    option = char(getch());

    // Menu is only called when the file has been verified

    if ( option == '1' ){
        writeFile(server_file,  "# Please, dont modify this file under any circumstances if you don't know the configuration patterns!\n"
                                "# For more information about the configuration patterns. Please visit https://github.com/joshuamosc/CNegtuneServer/\n\n"
                                "-connection\nremote\n\n-ipVersion\nIPv4\n\n-maxConnections\n100\n\n-serverName\nCNegtune Server\n\n");
        clrscr();
    }
    else if ( option == '2' ) {
        string newPath = loadServerFromFile(server_file, cnegtune_files_dir); // Verifies that the file exists and is valid, its a bucle and nothing goes after unless it passes the sentences
        // It also makes a copy of the file to temp directory for the next time it is opened
        clrscr();
        cout << "\n[!] Your configuration file has just been copied to " << server_file << ". If you want to modify any configuration, you'll have to do it in that file!\n";
        cout << "\nPress any key to continue...\n";
        getch();
    }
    else {
        firstMenu(server_file, cnegtune_files_dir, server);
    }

    setServerConf(server_file, server);
    menu(server_file, server);
}

void menu(const string& server_file, struct ServerConfiguration server) {
    setServerConf(server_file, server);
    clrscr();
    char option;
    cout << "\n--- [" << server.serverName << "] ---\n";
    cout << "\n1.- Server Info\n2.- Turn On Server\n3.- Sign Up Requests\n";

    option = char(getch());

    if ( option == '1' ) {
        clrscr();
        cout << "\n--- Server Info ---\n";
        cout << "\nServer Name: " << server.serverName;
        cout << "\nMax number of connections: " << server.maxConnections;
        cout << "\nType of connection: " << server.connection;
        cout << "\nIP Version: " << server.ipVersion;
        cout << "\n\nPress any key to go back...\n";
        getch();
        menu(server_file, server);
    }

}
