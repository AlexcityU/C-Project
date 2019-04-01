#include "User.h"
#include <iostream>
#include <string>
#include "FileHandler.h"
#include "LoanControl.h"
using namespace std;

int main() {
	string str = readFile("123.txt");


	std::istringstream iss(str);
	std::string token;

	/*User.foo("dsfsaf","dsa","jjjjsa","dsafds","asda");*/





	while (std::getline(iss, token, '|'))
	{
		cout << token << endl;
	}


	/*
		str = "Hello World!";
		writeFile("123.txt", str);
	*/
	system("pause");
	return 0;
}