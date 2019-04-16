#include "Equipment.h"

CampEquipment::CampEquipment()
{
}

CampEquipment::CampEquipment( string itemid, string itemname, string brand, string itemtype, string date, string condition, string status)
{
	eCount++;
	
	this->itemid = itemid;
	this->itemname = itemname;
	this->brand = brand;
	this->itemtype = itemtype;
	this->date =date ;
	this->condition = condition;
	this->status = status;
}

CampEquipment::~CampEquipment()
{
	eCount--;
}



string CampEquipment::getAllInfo() const
{
	return string(this->itemid + "|"+this->itemname +"|" + this->brand + "|" + this->itemtype + "|"
		+ this->date + "|" + this->condition + "|" + this->status);
}

string CampEquipment::getItemId() const
{
	return itemid;
}

string CampEquipment::getItemName() const
{
	return itemname;
}

string CampEquipment::getBrand() const
{
	return brand;
}

string CampEquipment::getItemType() const
{
	return itemtype;
}

string CampEquipment::getDate() const
{
	return date;
}

string CampEquipment::getCondition() const
{
	return condition;
}

string CampEquipment::getStatus() const
{
	return status;
}

int CampEquipment::getCount() const
{
	return eCount;
}

bool CampEquipment::canLoan() const
{
	return (!condition.compare("good") && !status.compare("in")) ? true : false;
}

void CampEquipment::setCondition(string _condition)
{
	this->condition = _condition;
}

void CampEquipment::setStatus(string _status)
{
	this->status = _status;
}

bool CampEquipment::checkborrow()
{
	if (getStatus().compare("in")&&getCondition().compare("good") ) { return true; }return false;
}



string Tent::getTentSize() const
{
	return tentsize;
}

string Tent::getTentType() const
{
	return tenttype;
}

string Tent::getNumDoors() const
{
	 return numdoors;
}

string Tent::getDouLayer() const
{
	return doulayer;
}

string Tent::getAllInfo() const
{
	return string(CampEquipment::getAllInfo() + "|"+this->tentsize +"|"+this->tenttype + "|" + this->numdoors + "|" + this->doulayer + "|" + this->color );
}

Tent::Tent(string itemid, string itemname, string brand, string itemtype, string date, string condition, string status,
	string tentsize, string tenttype, string numdoors, string doulayer, string color)
	:CampEquipment::CampEquipment(itemid, itemname, brand, itemtype, date, condition, status)
	{
	tCount++;
	
	this->tentsize = tentsize;
	this->tenttype = tenttype;
	this->numdoors = numdoors;
	this->doulayer = doulayer;
	this->color = color;
	}

Tent::~Tent()
{
	tCount--;
}

string Lantern::getLantSize() const
{
	return lantsize;
}

string Lantern::getLantType() const
{
	return lantsize;
}

string Lantern::getFuelType() const
{
	return fueltype;
}

string Lantern::getAllInfo() const
{
	return string(CampEquipment::getAllInfo()+"|"+this->lantsize + "|" + this->lanttype + "|" + this->fueltype  );
}

Lantern::Lantern(string itemid, string itemname, string brand, string itemtype, string date, string condition, string status, string lantsize, string lanttype, string fueltype)
	:CampEquipment::CampEquipment(itemid,itemname,brand,itemtype,date,condition,status)
{
	lCount++;

	this->lantsize = lantsize;
	this->lanttype = lanttype;
	this->fueltype = fueltype;
}

Lantern::~Lantern()
{
	lCount--;
}

string Stove::getStoveType() const
{
	return stovetype;
}

string Stove::getFuelType() const
{
	return fueltype;
}

string Stove::getAllInfo() const
{
	return string(CampEquipment::getAllInfo()+"|"+this->stovetype + "|" + this->fueltype );
}

Stove::Stove(string itemid, string itemname, string brand, string itemtype, string date, string condition, string status, string stovetype, string fueltype)
	:CampEquipment::CampEquipment(itemid,  itemname,  brand,  itemtype,  date,  condition,  status)
{
	sCount++;

	this->stovetype = stovetype;
	this->fueltype = fueltype;
}

Stove::~Stove()
{
	sCount--;
}
