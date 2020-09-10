//Lab 7

int helper_array_to_int(int* arr, int size) { // converts an array of integers into a single integer ([1, 2, 3] -> 123)
	int sum = 0;
	for(int i = size - 1; i >= 0; --i) {
		sum += arr[i] * pow(10, size - 1 - i); // as i gets smaller (moves to the right), exponent should get bigger
	}
	return sum;
}

// implicit use of pow() from <cmath>, could make another helper function
void sum(int* list1, int list1_size, int* list2, int list2_size) {
	int num1 = helper_array_to_int(list1, list1_size);
	int num2 = helper_array_to_int(list2, list2_size);
	
	std::cout << num1 + num2;
}

bool simonSays(int* arr1, int* arr2, int len) {
	for(int i = 0; i < len - 1; ++i) // iterates from the first element of arr1 to second to last element of arr1
		if(arr1[i] != arr2[i + 1]) // if any element isn't equal
			return false; // return false
			
	return true; 
}