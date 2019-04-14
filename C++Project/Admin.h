#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <sstream>
#include <string>
#include "Equipment.h"
#include "User.h"
#include "LoanRecord.h"
#include "FileHandler.h"

using namespace std;

class Admin
{
private:

	CampEquipment **equipments;
	LoanRecord **records;

	int equipment_size;
	int records_size;

	bool retrieveEquipments();
	bool retrieveLoanRecords();

	void updateEquipments();


public:
	CampEquipment *getEquipment(int i);


	void displayrecords();
	void displayEquipments();
	bool changeCondition(string eid, string condition);

	Admin();
	~Admin();
	
};

#endif
