#ifndef LOANCONTROAL_H
#define LOANCONTROAL_H

#include "User.h"
#include "Admin.h"

class LoanControl : protected Admin
{
private:
	
	User *user;

	User **retrieveUsers();

	void setUser();

	void addRecord(LoanRecord *r);

public:

	void displayLoanAvailableEquipments();
	void displayUserRecords();

	bool borrowEquipment(string eid);
	bool returnEquipment(string eid);

	LoanControl(string username, string password, bool &isUser);
	virtual ~LoanControl();
};

#endif // !1