#include "User.h"
#include <iostream>
#include <string>
#include "FileHandler.h"
#include "LoanControl.h"
using namespace std;

void admin() {

}
void userac(string username) {

	int num = 0;
	cout << "1. Borrow camp equipment:" << endl;
	cout << "2. Retrieve loan record and loan date:" << endl;
	cout << "3. View of available camp equipment:" << endl;
	cout << "back" << endl;
	switch (switch_on)
	{
	default:
		break;
	}


}


int main() {
	string user;
	string pw;

	cout << "User name plz:" << endl;
	cin >> user;
	cout << "pass word Plz:" << endl;
	cin >> pw;

	if (user == "admin" && pw == "admin")
	{
		admin();
	}
	else { userac(user); }







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