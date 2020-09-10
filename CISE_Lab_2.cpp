#include <iostream> 
#include <string>

int main() {
	int num1, num2;
	std::string command = "";

	std::cout << "Enter your first number: ";
	std::cin >> num1;
	std::cout << "Enter your second number: ";
	std::cin >> num2;
	
	std::cout << "Enter your command: ";
	std::cin >> command;
	
	if(command == "Add")
		std::cout << "Result: " << num1 + num2 << std::endl;
	else if(command == "Subtract")
		std::cout << "Result: " << num1 - num2 << std::endl;
	else if(command == "Multiply")
		std::cout << "Result: " << num1 * num2 << std::endl;
	else if(command == "Divide")
		std::cout << "Result: " << num1 / num2 << std::endl;
	else
		std::cout << "Invalid command!" << std::endl;
	
	return 0;
}

int main() {
	int len;
	
	std::cout << "Enter a number: ";
	std::cin >> len;
	
	int i = 0;
	int j;
	while(i < len) {
		
		j = i + 1;
		while(j < len) {
			std::cout << " ";
			j++;
		}
		i++;
		std::cout << "#" << std::endl;
	}
	
	return 0;
}


int main() {
	int len;
	
	std::cout << "Enter a number: ";
	std::cin >> len;
	
	int i = 0;
	int j;
	while(i < len) {
		
		j = i + 1;
		while(j < len) {
			std::cout << " ";
			j++;
		}
		i++;
		std::cout << "#" << std::endl;
	}
	
	return 0;
}

int main() {
	int len;
	
	std::cout << "Enter a number: ";
	std::cin >> len;
	
	int i = 0;
	int j;
	do {
		for (int j = i+1; j < len; j++){
			cout << " ";
		}
		if(i > 0)
			std::cout << "#" << std::endl;
		++i;
	} while(i < len);
	
	return 0;
}

int main() {
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	
	int sum = 0;
	while(num != 0) {
		sum += num % 10;
		num /= 10;
	}
	
	std::cout << "The sum of the digits in your number is: " << sum << std::endl;
	
	return 0;
}

int main() {
	int num = 0;
	
	
	switch(num) {
		case 1: std:: cout << "nothing special"; break;
		case 2: std:: cout << "nothing special"; break;
		case 3: std::cout << "equinox"; break;
		case 4: std:: cout << "nothing special"; break;
		case 5: std:: cout << "nothing special"; break;
		case 6: std::cout << "summer solstice"; break;
		case 7: std:: cout << "nothing special"; break;
		case 8: std:: cout << "nothing special"; break;
		case 9: std::cout << "equinox"; break;
		case 10: std:: cout << "nothing special"; break;
		case 11: std:: cout << "nothing special"; break;
		case 12: std::cout << "winter solstice"; break; 
	}
	
	
	}




