#ifndef USER_H
#define USER_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class User
{
private:
	string id;
	string name;
	string section;
	string dob;
	string address;

protected:
	User(string id, string name, string section, string dob, string address);
	int borrow;
	int nItem;

public:
	string getId() const;
	string getName() const;
	string getSection() const;
	string getDob() const;
	string getAddress() const;
	int getBorrow() const;
	int getNumItem() const;

	bool borrowEquip();
	bool returnEquip();

	virtual int findBorrow() const=0 ;
};

class Scout : public User
{
private:
	string rank;

public:
	string getRank() const;
	int findBorrow() const;

	Scout(string id, string name, string section, string dob, string address, string rank);
};

class Scouter : public User
{
private:
	string rank;

public:
	string getRank() const;
	int findBorrow() const;

	Scouter(string id, string name, string section, string dob, string address, string rank);
};

class Rover : public User
{
public:
	int findBorrow() const;

	Rover(string id, string name, string section, string dob, string address);
};

class Venture : public User
{
public:
	int findBorrow() const;

	Venture(string id, string name, string section, string dob, string address);
};


#endif
