#include "headers/CNegtuneServerDirectives.h"

using namespace std;

// Global Variables
std::string CNEGTUNE_FILES_DIR;
std::string SERVER_FILE;

struct ServerConfiguration server;

int main() {

    globalVariables(CNEGTUNE_FILES_DIR, SERVER_FILE);

    bool isValidServerConfFile = verifyValidServerConfFile(SERVER_FILE, CNEGTUNE_FILES_DIR, false);

    if ( isValidServerConfFile ){
        menu(SERVER_FILE, server);
    } else {
        firstMenu(SERVER_FILE, CNEGTUNE_FILES_DIR, server);
    }

    return 0;
}
