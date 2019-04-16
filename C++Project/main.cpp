
#include <iostream>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Equipment.h"
#include "LoanControl.h"
#include "LoanRecord.h"
#include "FileHandler.h"

using namespace std;
void admin() {
	int choice;
	bool ended = true;

	Admin a;
	while (ended)
	{
		system("cls");
		cout << "Admin Mode" << endl;
		cout <<"######################\n"
			 << "#1.Loan Rord         #\n"
			 << "#2.display equi      #\n"
			 << "#3.change status     #\n"
			 << "#4.produe .txt       #\n"
			 << "#5.close             #\n"
			 <<"######################\n";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			a.displayrecords();
			system("pause");

		}
		else if (choice == 2)
		{
			system("cls");
			a.displayEquipments();
			system("pause");
		}
		else if (choice == 3)
		{
			string status, eid;
			system("cls");
			cout << "enter the equipment id:"<<endl;
			cin >> eid;
			cout << "plz enter the status:"<<endl;
			cin >> status;
			
			a.changeCondition(eid, status);
			cout << "sucess" << endl;
			system("pause");
		}
		else if (choice == 4)
		{
			system("cls");
			cout << "produe .txt" << endl;
			system("pause");
		}
		else if (choice == 5)
		{
			ended = false;
		}
	}
}

bool userLog(string username, string password) {

	int choice;
	
	bool ended = true;
	bool isUser = false;

	LoanControl lc(username, password, isUser);
	
	
	if (!isUser)
		return false;

	while (ended)
	{
		system("cls");
		cout << "Now choose what you want to do~~~" << endl;
		cout << "---------------------------------" << endl;
		cout << "########################\n"
			<< "#1.Borrow equipment    #\n"
			<< "#2.Info of loan record #\n"
			<< "#3.available equi      #\n"
			<< "#4.close               #\n"
			<< "########################\n";
		cin >> choice;
		if (choice == 1)
		{
			string itemID;
			system("cls");
			cout << "plz nter the itemID:\n" << endl;
			cin >> itemID;

			if (lc.borrowEquipment(itemID)) {
				cout << "succes" << endl;

			}
			
			system("pause");

		}
		else if (choice == 2)
		{
			system("cls");

			lc.displayUserRecords();

			system("pause");
		}
		else if (choice == 3)
		{
			system("cls");
			lc.displayLoanAvailableEquipments();

			system("pause");
		}
		
		else if (choice == 4)
		{
			ended = false;
		}




	}
	
	return true;
}


int main() {
	/*bool isUser;
	LoanControl("VEN002", "24121991", isUser);
	*/
	string name;
	string pw;
	cout << "Welcome to the Loan!!" <<endl;
	cout << "---------------------" << endl;
	cout << "Now plz enter your Info~~" << endl;
	cout << "\n" << endl;
	cout << "plz enter the name:";
	cin >> name;
	cout << "plz enter the PW: ";
	cin >> pw;
	if (name == "admin" && pw == "admin")
	{
		admin();
	}
	else {
		if (!userLog(name, pw))
		{
			cout << "no such user" << endl;
		}
	}
	
	system("pause");
	return 0;
}