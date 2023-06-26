//
// Created by Cuent on 24/06/2023.
//

#include <string>

#ifndef CNEGTUNESERVER_FILES_H
#define CNEGTUNESERVER_FILES_H

bool fileExists( std::string fileName );
bool writeFile( std::string dirFileName, std::string content );
bool removeFile(std::string path);
bool directoryExists(std::string path);

#endif //CNEGTUNESERVER_FILES_H
