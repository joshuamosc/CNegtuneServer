//
// Created by eter on 25/06/2023.
//


#ifndef CNEGTUNESERVER_SERVERFILECONFIGURATION_H
#define CNEGTUNESERVER_SERVERFILECONFIGURATION_H

#include <string>

struct ServerConfiguration {
    std::string connection;
    std::string ipVersion;
    int maxConnections;
    std::string serverName;
};

bool verifyValidServerConfFile(std::string server_file, std::string cnegtune_files_dir, bool load);
void setServerConf(std::string server_file, struct ServerConfiguration&);

#endif //CNEGTUNESERVER_SERVERFILECONFIGURATION_H
