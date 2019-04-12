#pragma once
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CampEquipment
{
private:
	
	string itemid;
	string itemname;
	string brand;
	string itemtype;
	string date;
	string condition;
	string status;

	
protected:
	CampEquipment( string itemid, string itemname, string brand, string itemtype, string date, string condition, string status);

public:
	
	string getItemId() const;
	string getItemName() const;
	string getBrand() const;
	string getItemType() const;
	string getDate() const;
	string getCondition() const;
	string getStatus() const;
	void setCondition();
	void setStatus();

	virtual void finditem() {};
};

class Tent : CampEquipment
{
public:
	void finditem(){}
	string tentsize;
	string tenttype;
	string numdoors;
	bool doulayer;
	string color;
	Tent(string tentsize, string tenttype,string numdoors,bool doulayer,string color);
};
class Lantern : CampEquipment
{
public:
	void finditem() {}
	string lantsize;
	string lanttype;
	string fueltype;
	Lantern(string lantsize, string lanttype,string fueltype );
};
class Stove : CampEquipment
{
public:
	void finditem() {}
	string stovetype;
	string fueltype;
	Stove(string stovetype, string furltype);
};




#endif
