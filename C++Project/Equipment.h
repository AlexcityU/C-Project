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

	static int eCount;


public:
	virtual string getAllInfo()const;
	string getItemId() const;
	string getItemName() const;
	string getBrand() const;
	string getItemType() const;
	string getDate() const;
	string getCondition() const;
	string getStatus() const;
	virtual int getCount() const;

	void setCondition(string& _condition);
	void setStatus(string & _status);

	bool checkborrow();

	
	CampEquipment();
	CampEquipment(string itemid, string itemname, string brand, string itemtype, string date, string condition, string status);
	~CampEquipment();
};

class Tent : public CampEquipment
{
private:
	
	string tentsize;
	string tenttype;
	string numdoors;
	string doulayer;
	string color;

	static int tCount;


public:
	string getTentSize()const;
	string getTentType()const;
	string getNumDoors()const;
	string getDouLayer()const;

	string getAllInfo()const;


	Tent(string itemid, string itemname, string brand, string itemtype, string date, string condition,
		string status, string tentsize, string tenttype, string numdoors, string doulayer, string color);
	~Tent();

};
class Lantern : public CampEquipment
{
private:
	string lantsize;
	string lanttype;
	string fueltype;

	static int lCount;

public:
	string getLantSize()const;
	string getLantType()const;
	string getFuelType()const;

	string getAllInfo()const;

	Lantern(string itemid, string itemname, string brand, 
		string itemtype, string date, string condition, string status,string lantsize,string lanttype,string fueltype);
	~Lantern();

};
class Stove : public CampEquipment
{
private:

	string stovetype;
	string fueltype;

	static int sCount;

public:

	string getStoveType()const;
	string getFuelType()const;

	string getAllInfo()const;
	
	Stove(string itemid, string itemname, string brand, string itemtype, string date, string condition, string status,string stovetype,string fueltype);
	~Stove();
};




#endif
