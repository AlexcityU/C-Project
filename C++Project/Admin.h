#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class admin_login
{
private:
	string admin_id;
	string admin_password;

protected:
	admin_login(string admin_id, string admin_password);

public:
	string get_admin_id() const;
	string get_admin_password() const;
};
#endif
