cmake_minimum_required(VERSION 3.25)
project(CNegtuneServer)

set(CMAKE_CXX_STANDARD 17)

add_executable(CNegtuneServer main.cpp headers/CNegtuneServerDirectives.h features/files.cpp headers/files.h features/crossPlatformsFunctionalities.cpp headers/crossPlatformsFunctionalities.h features/menu.cpp headers/menu.h features/files.cpp features/loadServerFunctionalities.cpp headers/loadServerFunctionalities.h features/serverFileConfiguration.cpp headers/serverFileConfiguration.h)
