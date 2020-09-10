//Lab 5

/*
#1

Save last string in array, move everything one to the right
{the, quick, brown, brown, fox, jumps, over, the, lazy }
str = dog
i = 3

Swap 4 (word 5), last
{the, quick, brown, brown, lazy, jumps, over, the, fox}
str = dog
i = 3


replace 3 (word 4) w/ str 
{the, quick, brown, dog, lazy, jumps, over, the, fox}



#2
Binary search, returns index of largest value less than target in case where target DNE

(C)


#3
.a) 
"Result: How the t"

b.)
"Result: "





*/

// Doesn't work
bool equality(int arr[], int n, int num) {
	// single digit case
	if(n == 1) {
		if(arr[0] != num) 
			return false;
		else 
			return true;
	}
	
	
	int last_digit = num % 10;
	int num /= num;
	for(int i = n - 1; n >= 0; --i) {
		if(arr[i] != last_digit)
			return false;
		
		last_digit %= num;
		num /= num;
	}
	
	return true;
}

// looking for single pair, NOT any combination of nums
bool hasTwoSum(int arr[], int n, int sum) {
	for(int i = 0; i < n; ++i) // goes through the list linearly
		for(int j = i + 1; j < n; ++j) // comparing every element against every other element
			if(arr[i] + arr[j] == sum)
				return true;
	
	return false;	
}

int maxUnique(int candies[], int k) {
	int num_unique = 0;
	
	for(int i = 0; i < k; ++i)
	
	
	
	
}



/*
sorted_nums: sorted in increasing order
n: # of elements in sorted_nums
target: number to search for within sorted_nums

return true of target is found, false if not
*/
bool rangeSearch(int stored_nums[], int n, int target, int& start, int& end) {
	// Quick and Dirty: Linear Search
	// Should work, obviously inefficient
	// Look into binary search equivalent
	bool found = false;
	
	for(int i = 0; i < n; ++i) {
		if(stored_nums[i] == target) { // check if target is found
			found = true;
			
			//relies on sorted array
			if(stored_nums[i - 1] != target) // if previous element is not target
				start = i; // this is the beginning of the range
			if(stored_nums[i + 1] != target)// if next element is not target
				end = i; // this is the end of the range
		}
	}
	
	return found;
}


int findDuplicate(int A[], int n) {
	
	
	
}


