#pragma once
#ifndef FileHandler_H
#define FileHandler_H

#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string readFile(string path);

void writeFile(string path, string content);

#endif

