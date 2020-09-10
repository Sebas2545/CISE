//Lab 6

/*
1. 
a. char* ptr;
b. char* arr[];
c. const int* ptr;

2. 
a. "130"
b. "130"
c. "40"
d. "-36"
e. "-2"
f. "5"
g. "9"
h. "32"

3. 
Start: "D'oh"
surprise = -1
Print "D'o"
surprise = 38
Print "'o"
surprise = -66
Print: "D'ph"
surprise = 66
Print "Bart"



*/



// requires <cstring> for strlen()
// could replace with a simple for loop
void reverse(char* arr) {
	int index = strlen(arr);
	
	char* end = (arr + index - 1); // location of final character
	
	for(int i = 0; (arr + i) < (end - i); ++i) {
		char temp = *(arr + i);
		*(arr + i) = *(end - i);
		*(end - i) = temp;
	}  
}

void minMax(int* arr, int n, int*& min, int*& max) {
	if(n <= 0)
		return;
	
	min = max = arr;
	
	for(int i = 1; i < n; ++i) {
		if(*(arr + i) < *min)
			min = (arr + i);
		if(*(arr + i) > *max)
			max = (arr + i);
	}	
}

void descSort(int* nums, int len) { // I think this is insertion sort?
	for(int i = 0; i < len; ++i) {
		for(int j = i + 1; j < len; ++j) {
			if((*(nums + i)) < (*(nums + j)) { // if the later element is bigger, swap them
				int temp = *(nums + i);
				*(nums + i) = *(nums + j);
				*(nums + j) = temp;
			}
		}
	}
}
