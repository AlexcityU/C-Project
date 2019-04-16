#include "LoanControl.h"


User ** LoanControl::retrieveUsers()
{
	string str = readFile("user.txt");

	if (str.empty())
		return false;

	stringstream ss(str);
	string token;

	// count the number of line inside the user.txt
	int u = 0;
	while (getline(ss, token)) {
		if (!token.empty())
			u++;
	}

	// reset the default counter of stringstream ss
	ss.clear();
	ss.seekg(0, ios::beg);

	// define the size of the records array
	User **users = (u) ? new User*[u] : nullptr;

	int i = 0;
	while (getline(ss, token)) {
		if (!token.empty()) {

			string id, name, section, date, address;
			stringstream line(token);

			getline(line, id, '|');
			getline(line, name, '|');
			getline(line, section, '|');
			getline(line, date, '|');
			getline(line, address, '|');

			if (id[0] == 'S') {
				string rank;
				
				getline(line, rank, '|');

				if (id[2] == 'T') {
					users[i++] = new Scout(id, name, section, date, address, rank);
				}
				else if (id[2] == 'M') {
					users[i++] = new Scouter(id, name, section, date, address, rank);
				}
			}
			else if (id[0] == 'V') {
				users[i++] = new Venture(id, name, section, date, address);
			}
			else if (id[0] == 'R') {
				users[i++] = new Rover(id, name, section, date, address);
			}
		}
	}

	return users;
}

void LoanControl::setUser()
{
	int count = getRecord(0)->getCount();
	for (int i = 0; i < count; i++) {
		LoanRecord *r = getRecord(i);

		if (!r->getSid().compare(user->getId())) {
			if (!r->getStatus().compare("out for loan")) {
				for (int j = i + 1; j < count; i++) {
					LoanRecord *r2 = getRecord(j);

					user->borrowEquip();

					if (!r2->getEid().compare(r->getEid())) {
						if (!r2->getSid().compare(r->getSid())) {
							if (!r2->getStatus().compare("returned")) {
								user->returnEquip();

								break;
							}
						}
					}
				}
			}
		}
	}
}

void LoanControl::addRecord(LoanRecord * r)
{
	int count = getRecord(0)->getCount() - 1;
	LoanRecord **shift_r = new LoanRecord*[count + 1];
	for (int i = 0; i < count; i++) {
		shift_r[i] = getRecord(i);
	}
	shift_r[count] = r;
	delete[] records;

	records = shift_r;
}

void LoanControl::displayLoanAvailableEquipments()
{
	for (int i = 0; i < getEquipment(0)->getCount(); i++) {
		CampEquipment *e = getEquipment(i);

		if (e->canLoan())
			cout << e->getAllInfo() << endl;
	}
}

void LoanControl::displayUserRecords()
{
	// current records?
	for (int i = 0; i < getRecord(0)->getCount(); i++) {
		LoanRecord *record = getRecord(i);
		if (!record->getSid().compare(user->getId())) {
			cout << record->getRecord();

		}
	}

	



}

bool LoanControl::borrowEquipment(string eid)
{
	for (int i = 0; i < getEquipment(0)->getCount(); i++) {
		CampEquipment *e = getEquipment(i);

		if (!e->getItemId().compare(eid)) {
			if (e->canLoan() && user->borrowEquip()) {

				// update Equipments

				e->setStatus("out");
				updateEquipments();

				// update Records

				LoanRecord *new_r = new LoanRecord(e->getItemName(), e->getItemId(), user->getId(), "out");
				addRecord(new_r);
				updateRecords();

				return true;
			}
			else {
				return false;
			}
		}
	}

	return false;

}

bool LoanControl::returnEquipment(string eid)
{
	{
		for (int i = 0; i < getEquipment(0)->getCount(); i++) {
			CampEquipment *e = getEquipment(i);

			if (!e->getItemId().compare(eid)) {
				if (e->canLoan()) {
					if (user->borrowEquip()) {

						// update Equipments

						e->setStatus("in");
						updateEquipments();

						// update Records

						LoanRecord *new_r = new LoanRecord(e->getItemName(), e->getItemId(), user->getId(), "out");
						addRecord(new_r);
						updateRecords();

						return true;
					}
				}
			}
		}
	}
	
	return true;
}


LoanControl::LoanControl(string username, string password, bool &isUser)
	: Admin::Admin()
{
	isUser = false;

	User **users = retrieveUsers();
	int i;
	for (i = 0; i < users[0]->getCount(); i++) {
		if (!username.compare(users[i]->getId()) && !password.compare(users[i]->getDob())) {

			for (int j = 0; j < i; j++) {
				delete users[j];
			}
			for (int j = i + 1; j < users[0]->getCount(); j++) {
				delete users[j];
			}

			this->user = users[i];
			setUser();

			delete[] users;
			isUser = true;
			break;
		}
	}
}


LoanControl::~LoanControl()
{
	delete user;
}
 