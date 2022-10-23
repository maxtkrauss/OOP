#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

#include "account.h"

using namespace std;

int main(){
	vector<Account> account_info; // create vector to read data into

	account_info = load_data(); // read in registered user data

	welcome(); // welcome message

	menu(account_info); // navigation menu

    return 0;
}
