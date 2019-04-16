#include "LoanRecord.h"

LoanRecord::~LoanRecord()
{
	count--;
}

LoanRecord::LoanRecord(string itemid, string itname, string borrower, string status)
{
	this->date = "";
	this->returnDate = "";
	this->itemid = itemid;
	this->itname = itname;
	this->borrower = borrower;
	this->status = status;

	count++;
}

LoanRecord::LoanRecord(string date, string itemid, string itname, string borrower, string returnDate, string status)
{
	this->date = date;
	this->returnDate = returnDate;

	this->itemid = itemid;
	this->itname = itname;
	this->borrower = borrower;
	this->status = status;

	count++;
}

string LoanRecord::getRecord()
{
	return string(date + '|' + itemid + '|' + itname + '|' + borrower + '|' + returnDate + '|' + status + '\n');
}

string LoanRecord::getSid()
{
	return borrower;
}

string LoanRecord::getEid()
{
	return itemid;
}

string LoanRecord::getStatus()
{
	return status;
}

int LoanRecord::getCount()
{
	return count;
}

int LoanRecord::count = 0;
