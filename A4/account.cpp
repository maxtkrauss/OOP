#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include "account.h"

using namespace std;

vector<Account> load_data() { // Data loading function (reads from .txt file and stores all users into a vector)
	vector<Account> account_info;
    account_info.clear();
	string email, password, name, age, gender;

	ifstream myfile("account_database.txt");
	string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			int start = 0;
			int end = line.find(" "); 

			email = line.substr(start, end + start);
			start = end + 1;
			end = line.find(" ", start);


			password = line.substr(start, end - start);
			start = end + 1;
			end = line.find(" ", start);


			name = line.substr(start, end - start);
			start = end + 1;
			end = line.find(" ", start);

			age = line.substr(start, end - start);
			start = end + 1;
			end = line.find(" ", start);

			gender = line.substr(start, end - start);

			Account vect(name, email, password, age, gender);

			account_info.push_back(vect);
		}
		return account_info;
	}
	else {
		cout << "No previous account data." << endl;
		return account_info;
	}
};

void welcome() { // Welcome Message Function
	cout << " - - - Welcome to Assignment 4's CLI - - -" << endl;
};

void login(vector<Account> account_info) { // Login Function
	string email, password;
	string name, age;
	int acc_count = -1, check;

	cout << "Enter email: ";
	cin >> email;
	
	for (int i = 0; i < account_info.size(); i++) {
		if (email == account_info[i].email) {
			acc_count = i;
			i = account_info.size() + 1;
		}
	}
	if(acc_count == -1) {
		cout << "No account associated with this email." << endl;
		return;
	}
	else{
		cout << "Password: ";
		cin >> password;
		if (password == account_info[acc_count].password) {
			cout << "Welcome back " << account_info[acc_count].name << "! " << endl;
			cout << "Your age: " << account_info[acc_count].age << endl;
			cout << "Your gender: " << account_info[acc_count].gender << endl;
			return;
		}
		else {
			cout << "Incorrect password." << endl;
		}
	}
};

string new_password() { // Password Input Function
	string password, check;

	cout << "Enter password (at least 8 digits long w/ no special characters): ";
	cin >> password;

	if (password.size() < 8) {
		cout << "Password must be at least 8 digits long!" << endl;
		new_password();
		return password;
	}

	cout << "Re-enter password: ";
	cin >> check;

	if (check != password) { // Password Verification
		cout << "Passwords do not match!" << endl;
		new_password();
	}
	else {
		return password;
	}
    return "hello";

}

void register_new(vector<Account> account_info) { // User Registration Function

	char create = 1;
	string name, email, password, age, gender;

    cout << "Enter email address: ";
	cin >> email;
    for(int i = 0; i < account_info.size(); i++){ // Email checker
        if(account_info[i].email == email){
            cout << "There is already an account registered under this email." << endl;
            return;
        }
    }

    password = new_password();

	cout << "Enter first name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> age;
	cout << "Enter gender: ";
	cin >> gender;

	Account account(name, email, password, age, gender); // Account created using custom constructor

	create = char(int(create) + 1);

	ofstream file; 
	file.open("account_database.txt", ios::app); // Account written to .txt file
	file << email << " " << password << " " << name << " " << age<< " " << gender << endl;
	file.close();

	cout << "New account created for " << name << "." << endl;

	return;
};


void menu(vector<Account> account_info) { // Menu Navigation Function
	int option;
    
    cout << " - Menu - " << endl;
	cout << " 1.) Login " << endl;
	cout << " 2.) Register New User " << endl;
	cout << " 3.) Quit " << endl;
	cout << " Enter desired path(1-3): ";
	cin >> option;

	if (option == 1) {
		login(account_info);
		menu(account_info);
	}
	else if (option == 2) {
		register_new(account_info);
		vector<Account> reload_info = load_data();
		menu(reload_info);
	}
	else if (option == 3) {
		cout << "Have a great day!";
		return;
	}
	else {
		cout << "Invalid input." << endl;
		menu(account_info);
	}
};



