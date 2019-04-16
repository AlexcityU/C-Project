#include "User.h"

string User::getId() const
{
	return id;
}

string User::getName() const
{
	return name;
}

string User::getSection() const
{
	return section;
}

string User::getDob() const
{
	return dob;
}

string User::getAddress() const
{
	return address;
}

int User::getCount() const
{
	return count;
}

int User::getBorrow() const
{
	return borrow;
}

int User::getNumItem() const
{
	return nItem;
}

bool User::borrowEquip()
{
	bool flag = false;
	if (nItem < borrow) {
		nItem++;
		flag = true;
	}

	return flag;
}

bool User::returnEquip()
{
	bool flag = false;
	if (nItem > 0) {
		nItem--;
		flag = true;
	}

	return flag;
}

User::User(string id, string name, string section, string dob, string address)
{
	this->id = id;
	this->name = name;
	this->section = section;
	this->dob = dob;
	this->address = address;

	count++;
}

string Scout::getRank() const
{
	return rank;
}

int Scout::findBorrow() const
{
	if (!this->rank.compare("Member"))
		return 1;
	if (!this->rank.compare("Patrol Leader") || !this->rank.compare("Assistant Patrol Leader"))
		return 3;

	return -1;
}


Scout::Scout(string id, string name, string section, string dob, string address, string rank)
	: User(id, name, section, dob, address)
{
	this->rank = rank;
	this->borrow = this->findBorrow();
}

int Rover::findBorrow() const
{
	return 5;
}

Rover::Rover(string id, string name, string section, string dob, string address)
	: User(id, name, section, dob, address)
{
	this->borrow = this->findBorrow();
}

int Venture::findBorrow() const
{
	return 3;
}

Venture::Venture(string id, string name, string section, string dob, string address)
	: User(id, name, section, dob, address)
{
	this->borrow = this->findBorrow();
}

string Scouter::getRank() const
{
	return rank;
}

int Scouter::findBorrow() const
{
	return 5;
}

Scouter::Scouter(string id, string name, string section, string dob, string address, string rank)
	: User(id, name, section, dob, address)
{
	this->rank = rank;
	this->borrow = this->findBorrow();
}

int User::count = 0;