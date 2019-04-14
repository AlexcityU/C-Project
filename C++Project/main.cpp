#include "User.h"
#include <iostream>
#include <string>
#include "Admin.h"

using namespace std;




int main() {
	Admin a = Admin();

	cout << a.getEquipment(0)->getAllInfo();

	system("pause");
	return 0;
}