#include <iostream>
#include <vector>
#include <string>

#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account {
public:
	string name;
	string email;
	string password;
	string age;
	string gender;

	Account(string name, string email, string password, string age, string gender){
		this->name = name;
		this->email = email;
		this->password = password;
		this->age = age;
		this->gender = gender;
	}
};

vector<Account> load_data();

void welcome();

void login(vector<Account> account_info);

string new_password(vector<Account> account_info);

void register_new();

void menu(vector<Account> account_info);

#endif