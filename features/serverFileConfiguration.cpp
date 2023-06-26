//
// Created by eter on 25/06/2023.
//

#include "../headers/CNegtuneServerDirectives.h"

using namespace std;

namespace fs = filesystem;

bool verifyValidServerConfFile(string server_file, string cnegtune_files_dir, bool load)
{
    if ( !directoryExists(cnegtune_files_dir) ) {
        fs::create_directory(cnegtune_files_dir);
    }

    bool isValid = false, passMaxConnections = false, passConnection = false, passServerName = false, passIpVersion = false;
    string data, maxConnections = "", connection = "", ipVersion = "", serverName = "";

    bool serverFileExists = fileExists(server_file);

    if ( serverFileExists ) {
        ifstream File(server_file);
        while(getline(File, data)){
            if (passMaxConnections) {
                maxConnections = data;
                passMaxConnections = false;
            }
            if (data == "-maxConnections"){
                passMaxConnections = true;
            }

            if (passConnection) {
                connection = data;
                passConnection = false;
            }
            if (data == "-connection"){
                passConnection = true;
            }

            if (passServerName) {
                serverName = data;
                passServerName = false;
            }
            if (data == "-serverName"){
                passServerName = true;
            }

            if (passIpVersion) {
                ipVersion = data;
                passIpVersion = false;
            }
            if (data == "-ipVersion"){
                passIpVersion = true;
            }

            if ( passMaxConnections && passIpVersion && passConnection && passServerName ) {
                break;
            }
        }

        File.close();

        if (maxConnections != "" && ipVersion != "" && serverName != "" && connection != ""){
            isValid = true;
        }
    }

    if (!load) {
        if (!isValid && serverFileExists) {
            removeFile(server_file);
        }
    }

    return isValid;
}

void setServerConf(string server_file, struct ServerConfiguration& server) {

    string data;
    bool passMaxConnections = false, passConnection = false, passServerName = false, passIpVersion = false;

    ifstream ServerFile(server_file);
    while(getline(ServerFile, data)){
        if (passMaxConnections) {
            server.maxConnections = stoi(data);
            passMaxConnections = false;
        }
        if (data == "-maxConnections"){
            passMaxConnections = true;
        }

        if (passConnection) {
            server.connection = data;
            passConnection = false;
        }
        if (data == "-connection"){
            passConnection = true;
        }

        if (passServerName) {
            server.serverName = data;
            passServerName = false;
        }
        if (data == "-serverName"){
            passServerName = true;
        }

        if (passIpVersion) {
            server.ipVersion = data;
            passIpVersion = false;
        }
        if (data == "-ipVersion"){
            passIpVersion = true;
        }
    }

    ServerFile.close();

}
