# include <iostream>
# include <vector>
#include <ostream>
#include <fstream>

using namespace std;

class Disc {
public:
	string name;
	string type;
	string color;
	string manufacturer;
	string plastic;

	string speed;
	string glide;
	string turn;
	string fade;

	//int get_price() {
	//	return price;
	//}

	void get_description() {

		string flightnumbers = speed + ", " + glide + ", " + turn + ", " + fade;

		cout << "Disc Name: " + name << endl;
		cout << "Disc Manufacturer: " + manufacturer << endl;
		cout << "Disc Flight Numbers: " + flightnumbers << endl;
	}

	//Disc(string name, string type, string manufacturer, string plastic)
	//{
	//	this->name = name;
	//	this->type = type;
	//	this->manufacturer = manufacturer;
	//	this->plastic = plastic;

	//	if (plastic == "P" || plastic == "p") {
	//		price = 20;
	//	}
	//	else if (plastic == "B" || plastic == "b") {
	//		price = 12;
	//	}
	//	else
	//	{
	//		price = 0;
	//	}

	//	cout << "Disc created with custom compiler." << endl;
	//}

private:
	int price = 20;

};

void print_vector(vector<Disc> disc_collection) {

	cout << "Imaginary disc collection:"<< endl;

	for (int i = 0; i < disc_collection.size(); i++)
	{
		cout << "Disc Name: " << disc_collection[i].name << endl;
		cout << "Manufacturer: " << disc_collection[i].manufacturer << endl;
		cout << "Plastic Type: " << disc_collection[i].plastic << endl;
		cout << "Flight Numbers: " << disc_collection[i].speed + ", " + disc_collection[i].glide + ", " + disc_collection[i].turn + ", " + disc_collection[i].fade << endl;

	}
}

void print_vect2file(vector<disc> disc_collection) {
	ofstream file;
	file.open("disc_collection.txt", ios::app);

	for (int i = 0; i < disc_collection.size(); i++) {
		file << "Name: " << disc_collection[i].name << " " << disc_collection[i].manufacturer << " " << disc_collection[i].plastic << endl;
	}
	file.close();

}

int main() {

	vector<Disc> disc_collection;
	Disc disc;

	cout << "Welcome to the imaginary disc collection!" << endl;

	char d;
	do {
		cout << "Enter name of disc: ";
		cin >> disc.name;
		cout << "Enter disc manufacturer: ";
		cin >> disc.manufacturer;
		cout << "Enter disc plastic: ";
		cin >> disc.plastic;
		cout << "Enter disc speed: ";
		cin >> disc.speed;
		cout << "Enter disc glide: ";
		cin >> disc.glide;
		cout << "Enter disc turn: ";
		cin >> disc.turn;
		cout << "Enter disc fade: ";
		cin >> disc.fade;
		cout << "Do you wanna add another disc to the collection?(Y/N): ";
		cin >> d;
		disc_collection.push_back(disc);
	} while (d == 'y' || d == 'Y');

	print_vector(disc_collection);

	return 0;
}