#include "Admin.h"

CampEquipment * Admin::getEquipment(int i)
{
	if (i >= 0 && i < (*equipments)[0].getCount())
		return equipments[i];

	return nullptr;
}

Admin::Admin()
{
	this->retrieveEquipments();
	this->retrieveLoanRecords();

}

Admin::~Admin()
{
}

void Admin::displayrecords()
{
}

void Admin::displayEquipments()
{
	for (int i = 0; i < equipments[0]->getCount(); i++) {
		cout << equipments[i]->getAllInfo();
	}
}

bool Admin::retrieveEquipments()
{
	string str = readFile("camp_equipment.txt");

	if (str.empty())
		return false;

	stringstream ss(str);
	string token;

	// count the number of line inside the camp_equipment.txt
	int e = 0;
	while (getline(ss, token)) {
		if (!token.empty())
			e++;
	}

	// reset the default counter of stringstream ss
	ss.clear();
	ss.seekg(0, ios::beg);

	// define the size of the records array
	LoanRecord **records = new LoanRecord*[e];

	int i = 0;
	while (getline(ss, token)) {
		if (!token.empty()) {

			string date, return_date, itemid, itemname, userid, status;
			stringstream line(token);

			getline(line, date, '|');
			getline(line, itemid, '|');
			getline(line, itemname, '|');
			getline(line, userid, '|');
			getline(line, return_date, '|');
			getline(line, status, '|');

			records[i++] = new LoanRecord(date, itemid, itemname, userid, return_date, status);
		}
	}

	this->records = records;

	return true;
}

bool Admin::retrieveLoanRecords()
{
	string str = readFile("records.txt");

	if (str.empty())
		return false;

	stringstream ss(str);
	string token;

	// count the number of line
	int e = 0;
	while (getline(ss, token)) {
		if (!token.empty())
			e++;
	}

	// reset the default counter of stringstream ss
	ss.clear();
	ss.seekg(0, ios::beg);

	// define the size of the equipment array
	CampEquipment **equipments = new CampEquipment*[e];

	int i = 0;
	while (getline(ss, token)) {
		if (!token.empty()) {

			string id, name, brand, type, date, condition, status;
			stringstream line(token);

			getline(line, id, '|');
			getline(line, name, '|');
			getline(line, brand, '|');
			getline(line, type, '|');
			getline(line, date, '|');
			getline(line, condition, '|');
			getline(line, status, '|');

			CampEquipment *ptr = nullptr;
			if (id[0] == 'T') {
				string ppl, type, doors, dbLayer, color;
				getline(line, ppl, '|');
				getline(line, type, '|');
				getline(line, doors, '|');
				getline(line, dbLayer, '|');
				getline(line, color, '|');

				ptr = new Tent(id, name, brand, type, date, condition, status, ppl, type, doors, dbLayer, color);
			}
			else if (id[0] == 'S') {
				string stoveType, fuelType;
				getline(line, stoveType, '|');
				getline(line, fuelType, '|');


				ptr = new Stove(id, name, brand, type, date, condition, status, stoveType, fuelType);
			}
			else if (id[0] == 'L') {

				string lantSize, lantType, fuelType;
				getline(line, lantSize, '|');
				getline(line, lantType, '|');
				getline(line, fuelType, '|');


				ptr = new Lantern(id, name, brand, type, date, condition, status, lantSize, lantType, fuelType);
			}

			equipments[i++] = ptr;
		}
	}

	this->equipments = equipments;
	return true;
}

int CampEquipment::eCount = 0;
int Tent::tCount = 0;
int Stove::sCount = 0;
int Lantern::lCount = 0;