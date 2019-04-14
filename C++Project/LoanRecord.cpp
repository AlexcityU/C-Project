#include "LoanRecord.h"

LoanRecord::~LoanRecord()
{
	count--;
}

LoanRecord::LoanRecord(string date, string itemid, string itname, string borrower, string returnDate, string status)
{
	this->date = date;
	this->itemid = itemid;
	this->itname = itname;
	this->borrower = borrower;
	this->status = status;

	count++;
}

string LoanRecord::getRecord()
{
	return string(date + '|' + itemid + '|' + itname + '|' + borrower + '|' + returnDate + '|' + status);
}

int LoanRecord::count = 0;
