/* Homework 3
General Notes
- Helper functions are allowed
- There should be a main func, although it wont be called
- Only main may use cin/cout (cerr is okay)
- Any func passed a bad argument must return -1 (if they return an int)
- Any string comparisons may use comparison operators (==, <, etc)
- Avoid creating additional arrays in
	- moveToBack, moveToFront, deleteDups, meld, split
- May not use <algorithm>
- May not use global variables (const okay)
- Must build under g31
- No undefined behaviour
*/

/* FUNCTIONS TO BE IMPLEMENTED
1. int countMatches(const string a[], int n, string target); DONE/NOT TESTED
- Return the number of strings in the array that are equal to target

2. int detectMatch(const string a[], int n, string target); DONE/NOT TESTED
- Return the position of a string in the array that is equal to the target
	- Return the earliest possible string

3. bool detectSequence(const string a[], int n, string target, int& begin, int& end); DONE/NOT TESTED
- Find the earliest occurence of one or more consecutive strings equal to target
	- If found, change begin & end such that they encompass the range and return true, else return false

4. int detectMin(const string a[], int n); DONE/NOT TESTED
- Return the index of the smallest string

5. int moveToBack(string a[], int n, int pos); DONE/NOT TESTED
- Move the element @ index pos to the back (shifting everything to the left as needed) and return pos

6. int moveToFront(string a[], int n, int pos); DONE/NOT TESTED
- As in number 5, moving to the front and right

7. int detectDifference(const string a1[], int n1, const string a2[], int n2); DONE/NOT TESTED
- Return the position of the first element of a1 & a2 that are NOT equal
	- If they are equal to the point that one runs out, return the whichever value of n1/n2 that is smaller

8. int deleteDups(string a[], int n); DONE/NOT TESTED
- Delete any consecutive duplicate elements and return the number of items retained (see ex. for better explaination)

9. bool contains(const string a1[], int n1, const string a2[], int n2); DONE/NOT TESTED
- If all elements of a2 appear in a1 in order (not necessarily consecutively), return true
	- Yes, every set contains the empty set (n2 = 0)

10. int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max); DONE/NOT TESTED
- if both a1 & a2 have elements in nondecreasing order, place the elements of a1 & a2 in result
such that result is also nondecreasing and return the number of elements placed
- if the result would overflow result OR a1 and/or a2 are not in nondecreasing order, return -1

11. int split(string a[], int n, string splitter); DONE/NOT TESTED
- Reorder the array such that the front is less than splitter, and the back is greater than splitter
	- Not necesarrily in decreasing order, each side may be unordered so long as each side is distinct
- Return the position of the first element that is NOT < splitter (first element of back half, return n if no such element exists)


*/

// START CODE
#include <string>
#include <cassert>

using namespace std;

//START PROTOTYPES
int countMatches(const string a[], int n, string target);

int detectMatch(const string a[], int n, string target);

bool detectSequence(const string a[], int n, string target, int& begin, int& end);

int detectMin(const string a[], int n);

int moveToBack(string a[], int n, int pos);

int moveToFront(string a[], int n, int pos);

int detectDifference(const string a1[], int n1, const string a2[], int n2);

int deleteDups(string a[], int n);

bool contains(const string a1[], int n1, const string a2[], int n2);

int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max);

int split(string a[], int n, string splitter);

bool helper_check_negative(int n);

bool helper_check_nondecreasing(int* arr, int n);

//START MAIN/TESTING
int main() {
	string d[9] = {"thor", "romanoff", "danvers", "danvers", "stark", "stark", "stark", "danvers", "danvers"};

	//TESTING countMatches()
	assert(countMatches(d, 0, "") == -1); // empty array case
	assert(countMatches(d, -1, "") == -1); // negative size case
  assert(countMatches(d, 9, "thor") == 1); // single match case
  assert(countMatches(d, 9, "danvers") == 4); // multiple matches case






	return 0;
}

//START FUNCTION IMPLEMENTATION
int countMatches(const string a[], int n, string target) { // Return the number of strings in the array that are equal to target
	if(helper_check_negative(n)) // if n is negative
		return -1; // return -1 (bad argument)

	int count = 0; // holds # of matches to target

	for(int i = 0; i < n; ++i) // linear search over the whole array (order is not guarenteed)
		if(a[i] == target) // if a match is found
			++count; // increment count

	return count;
}

int detectMatch(const string a[], int n, string target) { // Return the position of a string in the array that is equal to the target
	if(helper_check_negative(n)) // if n is negative
		return -1; // return -1 (bad argument)

	for(int i = 0; i < n; ++i)
		if(a[i] == target) // if target is found
			return i; // return index

	return -1; // else, return -1
}

bool detectSequence(const string a[], int n, string target, int& begin, int& end) { // Find the earliest occurence of one or more consecutive strings equal to target
	if(helper_check_negative(n)) // if n is negative
		return false; // return false (bad argument)

	bool flag = false; // flag detecting whether a sequence has been found or not

	int temp = detectMatch(a, n, target); // use temp var, as begin shouldn't be changed if a match isn't found
	if(temp == -1) // if no match is found
		return flag; // return false

	flag = true; // else, set flag as true
	end = begin = temp; // set up bounds

	for(int i = begin; a[i] == target; ++i) // while there are consecutive targets
		++end; // increment end

	return flag;
}

int detectMin(const string a[], int n) { // Return the index of the smallest string
	if(helper_check_negative(n) || n == 0) // if n is negative or 0 (to prevent undefined behaviour)
		return -1; // return -1 (bad argument)

	string smallest = a[0];
	int smallest_index = 0;

	for(int i = 1; i < n; ++i) { // iterate over the rest of the array
		if(a[i] < smallest) { // if another element is smaller
			smallest = a[i]; // make it the new smallest item
			smallest_index = i; // and update index
		}
	}
	return smallest_index;
}

int moveToBack(string a[], int n, int pos) { // Move element @ pos to the back and return pos
	if(helper_check_negative(n) || n == 0 || helper_check_negative(pos) || pos == 0) // if n or pos is negative or 0
		return -1; // return -1 (bad argument)

	string temp = a[pos];
	for(int i = pos; i < n - 1; ++i) // TODO, check the bounds (not sure if i < n - 1 is correct)
		a[i] = a[i + 1];
	a[n - 1] = temp;

	return pos;
}

int moveToFront(string a[], int n, int pos) { // Move element @ pos to front and return pos
	if(helper_check_negative(n) || n == 0 || helper_check_negative(pos) || pos == 0) // if n or pos is negative or 0
		return -1; // return -1 (bad argument)

		string temp = a[pos];
		for(int i = pos; i > 0; --i)
			a[i] = a[i - 1];
		a[0] = temp;

		return pos;
}

int detectDifference(const string a1[], int n1, const string a2[], int n2) { // Return the position of the first element of a1 & a2 that are NOT equal
	if(helper_check_negative(n1) || helper_check_negative(n2))
		return -1;

	for(int i = 0; i < n1 && i < n2; ++i)
		if(a1[i] != a2[i])
			return i;

	if(n1 < n2)
		return n1;
	return n2;
}

int deleteDups(string a[], int n) {
	if(helper_check_negative(n1))
		return -1;

	for(int i = n - 1; i > 0; --i) {
		if(a[i - 1] == a[i]) {
				moveToBack(a, n, i);
				--n;
		}
	}

	return n;
}

bool contains(const string a1[], int n1, const string a2[], int n2) { // check if a1 contains a2
	if(helper_check_negative(n1) || helper_check_negative(n2))
		return false;
	if(n2 == 0) // every set contains the empty set
		return true;


	int i = 0;
	int itertor_a2 = 0;
	for(; i < n1; ++i) {
		if(iterator_a2 == n2) {
			return true;
		}
		else if(a1[i] == a2[iterator_a2]) {
			++iterator_a2;
		}
	}
	return false;
}


int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max) { // if both a1 & a2 have elements in nondecreasing order, place the elements of a1 & a2 in result
  if(helper_check_negative(n1)) // size error checking                                   // such that result is also nondecreasing and return the number of elements placed
		return -1;
	if(helper_check_negative(n2))
		return -1;
	if(helper_check_negative(max) || n1 + n2 > max)
		return -1;

	// check that both arrays are nondecreasing
	if(helper_nondecreasing(a1, n1))
		return -1;
	if(helper_nondecreasing(a2, n2))
		return -1;

	int iterator_a1 = 0;
	int iterator_a2 = 0;

	for(int i = 0; i < n1 + n2; ++i) {
		if(a1[iterator_a1] < a2[iterator_a2]) { // if a1 < a2
			result[i] = a1[iterator_a1];
			++iterator_a1;
		}
		else { // else a1 >= a2
			result[i] = a2[iterator_a2];
			++iterator_a2;
		}
	}
	return n1 + n2;
}

/*
Ideas for Algorithm
- Sort the array in descending order, linear search from the back to find value to be returned
	- Pros: Easy to implement, just grab a sort algorithm; Doesn't require a new array
	- Cons: Not super efficient, as it does more work than needed

- Modified Insertion Sort: iterate through the array.
When an element > splitter is found, swap it with the furthest back value (that is < splitter) and iterate an iterator from the back
	- Pros: Much more efficient, (ideally) only one pass through the array, does minimal work; Doesn't require a new array
	- Cons: Harder to write; Doesn't cover ==splitter case well, biggest issue w/ this method
*/
int split(string a[], int n, string splitter) { // Reorder the array such that the front is less than splitter, and the back is greater than splitter
	if(helper_check_negative(n) || n == 0) // if n is negative or 0 (to prevent undefined behaviour)
		return -1; // return -1 (bad argument)

	// Insertion Sort
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(a[i] > a[j]) {
				string temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	// Find index of first element > splitter
	for(int i = 0; i < n; ++i)
		if(a[i] > splitter)
			return i;

	return n; // if no element > splitter is found
}

bool helper_check_negative(int n) { // checks if n is negative for bad size argument case
	if(n < 0)
		return true;
	return false;
}

bool helper_check_nondecreasing(int* arr, int n) { // returns true if an array is nondecreasing
	for(int i = 0; i < n - 1; ++i)
		if(arr[i] > arr[i + 1] )
			return false;

	return true;
}
