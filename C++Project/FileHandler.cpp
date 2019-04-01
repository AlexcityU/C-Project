#include "FileHandler.h"

string readFile(string path) {
	ifstream file(path, ios::in);

	if (file.is_open()) {
		stringstream buffer;
		buffer << file.rdbuf();

		return buffer.str();
	}

	file.close();

	return NULL;
}

void writeFile(string path, string content) {

	ofstream outfile(path, ios::out);
	stringstream buffer;
	buffer << content;
	outfile << buffer.rdbuf();
}