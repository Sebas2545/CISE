#include <iostream>
#include <iomanip> // formatting
#include <string> 

//GLOBAL CONSTANTS
// in dollars
const double FIRST_TIER_RATE = 2.71; 
const double SECOND_TIER_RATE_HIGH_SEASON = 3.39; 
const double SECOND_TIER_RATE_LOW_SEASON = 2.87;


double calculateCost(int i, int f, char s);

int main() {
	// in HCF (hundred cubic feet)
	int initial_meter_reading;
	int final_meter_reading;
	
	std::string name; // customer name
	int month; // (1=Jan, 2=Feb, ...)
	char season = 'l'; // 'h' for high season, low season by default
	
	
	// BEGIN GATHERING INPUT
	
	std::cout << "Initial meter reading: ";
	std::cin >> initial_meter_reading;
	
	std::cout << "Final meter reading: ";
	std::cin >> final_meter_reading;
	
	std::cin.ignore(100000, '\n');
	std::cout << "Customer Name: ";
	getline(std::cin, name);
	
	std::cout << "Month number (1=Jan, 2=Feb, ...): ";
	std::cin >> month;

	// only need to check for high season, initialized to low season by default
	if (month >= 4 && month <= 10) // high usage months (4-10)
		season = 'h';
	
	// FINISHED GATHERING INPUT
	
	
	// BEGIN OUTPUT
	
	std::cout << "---" << std::endl; // required for testing software to begin looking for output
	
	//Error cases
	if(initial_meter_reading < 0) { // check for negative initial meter reading
		std::cout << "The initial meter reading must be nonnegative.";
		return 0; // stops program before addditional output
	}
	
	if(final_meter_reading < initial_meter_reading) { // check for final meter reading less than initial
		std::cout << "The final meter reading must be at least as large as the initial reading.";
		return 0; // stops program before addditional output
	}

	if(name == "") { // check for empty name
		std::cout << "You must enter a customer name.";
		return 0; // stops program before addditional output
	}
		
	if(month < 1 || month > 12) {// check if it is out of bounds of months	
		std::cout << "The month number must be in the range 1 through 12." << std::endl;
		return 0; // stops program before addditional output
	}
		
	// Valid case
	std::cout << "The bill for " << name << " is $" << std::fixed << std::showpoint << std::setprecision(2) << calculateCost(initial_meter_reading, final_meter_reading, season);

	return 0;
}


double calculateCost(int initial_meter_reading, int final_meter_reading, char season) {
	int dif = final_meter_reading - initial_meter_reading;
	
	if(season == 'h') { // high season, first 43 HCF billed at first tier
		if(dif < 43)
			return FIRST_TIER_RATE * dif;

		dif -= 43;
		return (43 * FIRST_TIER_RATE) + (dif * SECOND_TIER_RATE_HIGH_SEASON);
	}
	else { // low season, first 29 HCF billed at first tier
		if(dif < 29)
			return FIRST_TIER_RATE * dif;

		dif -= 29;
		return (29 * FIRST_TIER_RATE) + (dif * SECOND_TIER_RATE_LOW_SEASON);
		
	}
}



















