#include "User.h"
#include <iostream>
#include <string>
#include "Admin.h"

using namespace std;




int main() {
	Admin a = Admin();

	cout << a.changeCondition("T001", "good") << endl;
	a.displayEquipments();
	system("pause");
	return 0;
}