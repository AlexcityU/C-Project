
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

	while (ended)
	{
		system("cls");
		cout << "Admin Mode" << endl;
		cout <<"####################\n"
			 << "#1. Loan Rord      #\n"
			 << "#2. change status  #\n"
			 << "#3. look equi      #\n"
			 << "#4. produe .txt    #\n"
			 << "#5. close          #\n"
			 <<"####################\n";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			LoanControl.displayUserRecords();
			system("pause");

		}
		else if (choice == 2)
		{
			string status;
			system("cls");
			cout << "plz enter the status:";
			cin >> status;
			CampEquipment.setStatus(status);
			system("pause");
		}
		else if (choice == 3)
		{
			system("cls");
			CampEquipment.getAllInfo();
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

void userLog() {
	int choice;
	bool ended = true;

	while (ended)
	{
		system("cls");
		cout << "Now choose what you want to do~~~" << endl;
		cout << "---------------------------------" << endl;
		cout << "########################\n"
			<< "#1. Borrow equipment   #\n"
			<< "#2. Info of item       #\n"
			<< "#3. available equi     #\n"
			<< "#4. return item        #\n"
			<< "#5. close              #\n"
			<< "########################\n";
		cin >> choice;
		if (choice == 1)
		{
			string itemID;
			system("cls");
			cout << "plz nter the itemID:\n" << endl;
			cin >> itemID;
			LoanControl.borrowEquipment(itemID);
			system("pause");

		}
		else if (choice == 2)
		{
			system("cls");
			CampEquipment.getAllInfo();
			system("pause");
		}
		else if (choice == 3)
		{
			system("cls");
			cout << "available" << endl;
			system("pause");
		}
		else if (choice == 4)
		{
			string rItemID;
			system("cls");
			cout << "plz enter the item ID:\n" << endl;
			cin >> rItemID;
			LoanControl.returnEquipment(rItemID);
			system("pause");
		}
		else if (choice == 5)
		{
			ended = false;
		}




	}

}
bool checkuser(string naem, string pw) {
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
		bool isUser;
		LoanControl(name, pw,isUser);
		if (isUser)
		{
			userLog();
		}
	}
	
	system("pause");
	return 0;
}