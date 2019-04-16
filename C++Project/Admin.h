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


	bool retrieveEquipments();
	bool retrieveLoanRecords();

protected:

	CampEquipment **equipments;
	LoanRecord **records;

	bool hasR;

	void updateEquipments();
	void updateRecords();

public:
	CampEquipment *getEquipment(int i);
	LoanRecord *getRecord(int i);

	void displayrecords();
	void displayEquipments();
	bool changeCondition(string eid, string condition);

	Admin();
	virtual ~Admin();
	
};

#endif
