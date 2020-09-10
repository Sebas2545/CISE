#include <iostream>
using namespace std;

int main() {
	string first_name;
	char last_initial;
	int age;
	int year;
	double weight_in_pounds;
	
	cout << "First Name: ";
	getline(cin, first_name);
	
	//cin.ignore(100000, '\n');
	
	cout << "Last Initial: ";
	cin >> last_initial;
	
	cout << "Age: ";
	cin >> age;
	
	cout << "Weight in Pounds: ";
	cin >> weight_in_pounds;
	
	cout << "Year: ";
	cin >> year;
	cout << endl << endl;
	
	
	cout << "Name: " << first_name << ' ' << last_initial << endl;
	cout << "Age: " << age << endl;
	cout << "Weight: " << weight_in_pounds * .4536 << " kg" << endl;
	cout << "Year: " << year << endl;
	
	return 0;
}
