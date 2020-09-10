#include <iostream>
#include <string> 

// only works for natural numbers and 0
std::string reverse(std::string num) {
	std::string reverse = "";
	
	for(int i = num.length() - 1; i >= 0; --i) //moves from right to left along the string
		reverse += num.at(i); // saves each character to reverse
	
	return reverse;
}

int fibonacci(int n) {
	int n_1 = 1; 
	int n_2 = 1;
	int n_3 = 2; // not strictly neccesay to initialize here
	
	if(n < 3) // if n is 1 or 2 (negative cases not handeled), just return 1 to avoid handling cases in loop
		return 1;
	
	for(int i = 2; i < n; ++i) {
		n_3 = n_1 + n_2;
		n_1 = n_2; // moves n_1 over one value in sequence
		n_2 = n_3; // moves n_2 over one value in sequence
	}
	
	return n_3;
}

int max3(int score1, int score2, int score3) {
	if(score1 > score2) { // cases where score 1 is biggest, and score3 > score2 > score1 (3 cases total)
		if(score1 > score3)
			return score1;
		else
			return score3;
	}
	
	if(score2 > score3) // cases where score2 is biggest (2 cases)
		return score2;
	return score3; // case where score3 is biggest (1 case)
}


std::string ToLowerCase(std::string str) {
	for(int i = 0; i < str.length(); ++i) 
		if(islower(str.at(i)) == false)
			str.at(i) += 32;
  return str;
}

std::string reverse_sentence(std::string sentence) {
	std::string backwards_sentence = "";
	std::string word = "";
	
	for(int i = 0; i < sentence.length(); ++i) {
		if(sentence.at(i) == ' ') {
			backwards_sentence += reverse(word) + " ";
			word = "";
		}
		else {
			word += sentence.at(i);
		}
	}
	backwards_sentence.pop_back();
	return backwards_sentence;
}

int main() {
  std::string str;
  std::cout << "Input: ";
  getline(std::cin, str);

  std::cout << "Output: " << reverse(str) << std::endl;
}
