//
// Created by eter on 24/06/2023.
//

#include "../headers/CNegtuneServerDirectives.h"

using namespace std;

void globalVariables( string& cnegtune_files_dir, string& server_file )
{

#if defined(_WIN64) || defined(_WIN32)
    char acUserName[1000];
    std::string userName;
    DWORD nUserName = sizeof (acUserName);
    if( GetUserName(acUserName, &nUserName) ) {
        userName = acUserName;
        cnegtune_files_dir = "C:/Users/" + userName + "/AppData/Local/Temp/CNegtuneServer";
        server_file = cnegtune_files_dir + "/serverConf.dat";
    }
#elif defined(_linux) || defined (_unix)
    cnegtune_files_dir = "/usr/CNegtuneServer";
    server_file = cnegtune_files_dir + "/serverConf.dat";
#endif

}

void clrscr() {
#if defined(_WIN64) || defined(_WIN32)
    system("cls");
#elif defined(_linux) || defined (_unix)
    system("clear");
#endif
}