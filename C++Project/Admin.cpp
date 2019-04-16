#include "Admin.h"

CampEquipment * Admin::getEquipment(int i)
{
	if (i >= 0 && i < (*equipments)[0].getCount())
		return equipments[i];

	return nullptr;
}

LoanRecord * Admin::getRecord(int i)
{
	if (i >= 0 && i < ((hasR)? records[0]->getCount():0))
		return records[i];

	return nullptr;
}

bool Admin::changeCondition(string eid, string condition)
{
	bool can = condition.compare("good") && condition.compare("being repaired") && condition.compare("disposal") && condition.compare("damaged");
	if (!can) {
		for (int i = 0; i < (this->equipments)[0]->getCount(); i++) {
			CampEquipment *e = (this->equipments)[i];

			if (!eid.compare(e->getItemId())) {
				e->setCondition(condition);
				updateEquipments();

				return true;
			}
		}
	}
	return false;
}

Admin::Admin()
{
	this->retrieveEquipments();
	hasR = (this->retrieveLoanRecords()) ? true : false;

}

Admin::~Admin()
{
}

void Admin::displayrecords()
{
	for (int i = 0; i < records[0]->getCount(); i++) {
		cout << records[i]->getRecord() << endl;
	}
}

void Admin::displayEquipments()
{
	for (int i = 0; i < equipments[0]->getCount(); i++) {
		cout << equipments[i]->getAllInfo() << endl;
	}
}

bool Admin::retrieveLoanRecords()
{
	string str = readFile("record.txt");

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

void Admin::updateEquipments()
{
	string str = "";
	for (int i = 0; i < equipments[0]->getCount(); i++) {
		str += equipments[i]->getAllInfo() + '\n';
	}

	writeFile("camp_equipment.txt", str);
}

void Admin::updateRecords()
{
	string str = "";
	for (int i = 0; i < records[0]->getCount(); i++) {
		str += records[i]->getRecord() + '\n';
	}

	writeFile("record.txt", str);
}

bool Admin::retrieveEquipments()
{
	string str = readFile("camp_equipment.txt");

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