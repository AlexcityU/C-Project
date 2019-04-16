#pragma once
#ifndef LOANRECORD_H
#define LOANRECORD_H

#include <string>
using namespace std;

class LoanRecord
{
private:
	string date;
	string itemid;
	string itname;
	string borrower;
	string returnDate;
	string status;

	static int count;

public:

	LoanRecord(string itemid, string itname, string borrower, string status);

	LoanRecord(string date, string itemid, string itname, string borrower, string returnDate, string status);

	~LoanRecord();

	string getRecord();

	string getSid();
	string getEid();

	string getStatus();

	int getCount();

};

#endif

