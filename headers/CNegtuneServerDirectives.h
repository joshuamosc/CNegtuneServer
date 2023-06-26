//
// Created by eter on 24/06/2023.
//

#ifndef CNEGTUNESERVER_CNEGTUNESERVERDIRECTIVES_H
#define CNEGTUNESERVER_CNEGTUNESERVERDIRECTIVES_H

// C/C++ Libraries

#include <iostream>
#include <string>
#include <conio.h>
#include <filesystem>
#include <fstream>

// CNegtuneServer Libraries

#include "files.h"
#include "crossPlatformsFunctionalities.h"
#include "menu.h"
#include "loadServerFunctionalities.h"
#include "serverFileConfiguration.h"


// Macros

#if defined(_WIN64) || defined(_WIN32)
#include <windows.h> // Library required to know the current username
#endif


#endif //CNEGTUNESERVER_CNEGTUNESERVERDIRECTIVES_H
