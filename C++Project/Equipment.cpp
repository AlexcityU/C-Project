#include "Equipment.h"

CampEquipment::CampEquipment( string itemid, string itemname, string brand, string itemtype, string date, string condition, string status)
{
	
	this->itemid = itemid;
	this->itemname = itemname;
	this->brand = brand;
	this->itemtype = itemtype;
	this->date =date ;
	this->condition = condition;
	this->status = status;
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

void CampEquipment::setCondition()
{

}

void CampEquipment::setStatus()
{
}

void CampEquipment::finditem()
{
	if (itemtype == "tent")
	{	}
}

