#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <string>

using namespace std;

class Disc {
public:
	string name, manufacturer, plastic, speed, glide, turn, fade;
	int num;

	static int disc_count; //Static Member

	static int get_count() { //Static Method
		return disc_count;
	}

	int get_price() { //getter
		return price;
	}

	void set_price(int input) { //setter
		price = input;
	}

	string get_flightnumbers() {

		string flightnumbers = speed + ", " + glide + ", " + turn + ", " + fade;

		return flightnumbers;
	}

	Disc(string name, string manufacturer, string plastic, string speed, string glide, string turn, string fade)
	{
		
		this->name = name;
		this->plastic = plastic;
		this->manufacturer = manufacturer;
		this->speed = speed;
		this->glide = glide;
		this->turn = turn;
		this->fade = fade;
		disc_count++;
		this->num = disc_count;

		cout << "Disc created with custom compiler." << endl;
	}

	~Disc() {
		disc_count--;
	}

private:
	int price = 20; // default price

};

void print_vector(vector<Disc> disc_collection){

	cout << "Imaginary disc collection contains: " << disc_collection[0].get_count() << " discs " << endl;

	for (int i = 0; i < disc_collection.size(); i++)
	{
		cout << "Disc #" << disc_collection[i].num << endl;
		cout << "Disc Name: " << disc_collection[i].name << endl;
		cout << "Manufacturer: " << disc_collection[i].manufacturer << endl;
		cout << "Plastic Type: " << disc_collection[i].plastic << endl;
		cout << "Flight Numbers: " << disc_collection[i].get_flightnumbers() << endl;
		cout << "Price: " << disc_collection[i].get_price() << endl;

	}
}

void print_vect2file(vector<Disc> disc_collection){
	ofstream file;
	file.open("disc_collection.txt", ios::app);

	for (int i = 0; i < disc_collection.size(); i++) {
		file << "Disc #" << disc_collection[i].num << endl;
		file << "Name: " << disc_collection[i].name << endl;
		file << "Manufacturer: " << disc_collection[i].manufacturer << endl;
		file << "Plastic: " << disc_collection[i].plastic << endl;
		file << "Flight Numbers: " << disc_collection[i].get_flightnumbers() << endl;
		file << "Price: $" << disc_collection[i].get_price() << endl;
	}

	file.close();

}

int read_file()
{
	int count = 0;
	string line;
	ifstream file;
	file.open("disc_collection.txt", ios::in);
	while (getline(file, line)) {
		count++;
	}

	return (count/6);

	file.close();
}

vector<Disc> create_vect() {

	vector<Disc> disc_collection;
	string name, manu, plastic, speed, glide, turn, fade;
	int price;

	cout << "Welcome to the imaginary disc collection!" << endl;

	char d; //set do while loop
	do {
		cout << "Enter name of disc: ";
		cin >> name;
		cout << "Enter disc manufacturer: ";
		cin >> manu;
		cout << "Enter disc plastic: ";
		cin >> plastic;
		cout << "Enter disc price: ";
		cin >> price;
		cout << "Enter disc speed: ";
		cin >> speed;
		cout << "Enter disc glide: ";
		cin >> glide;
		cout << "Enter disc turn: ";
		cin >> turn;
		cout << "Enter disc fade: ";
		cin >> fade;
		Disc disc(name, manu, plastic, speed, glide, turn, fade);

		cout << "Do you wish to add another disc to the collection?(Y/N): ";
		cin >> d;

		disc.set_price(price);
		disc_collection.push_back(disc);

	} while (d == 'y' || d == 'Y');

	return disc_collection;
}

int Disc::disc_count = read_file();
int main(){

	vector<Disc> disc_collection = create_vect();

	print_vector(disc_collection);

	print_vect2file(disc_collection);

	return 0;
}

