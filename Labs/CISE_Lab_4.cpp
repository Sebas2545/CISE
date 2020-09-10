void multiplicationTable() {
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j)
			std::cout << i << "*" << j << "=" << i*j << "    ";
		std::cout << std::endl;
	}
}


bool check_gapful(int num) {
	if(num < 100)
		return false;
	
	int hold_num = num; // num is manipulated, holds num for final calculation
	
	int gap_num_left = num % 10;
	num /= 10;
	
	int gap_num_right;
	while(num != 0) { // while the right hand side has not been reached
		if(num / 10 == 0)
			gap_num_right = num;
	
		num /= 10;
	}
	
	int gapful = (10 * gap_num_right) + gap_num_left;
	
	if(hold_num % gapful == 0)
		return true;
	return false;
}

int closest_gapful_number(int num) {
	if(check_gapful(num)) // if the number is gapful, return itself
		return num;
	
	int up_iterator = num + 1; // will iterate towards greater numbers 
	int down_iterator = num - 1; // will iterate towards smaller numbers
	
	while(true) { // technically infinite loop, could throw an exception if too much time has passed
		if(check_gapful(down_iterator)) // check down_iterator first, since smaller gapful number should be returned in equidistant case
			return down_iterator; // if down_iterator is gapful, return true
		else
			--down_iterator; // else, iterate down_iterator
		
		if(check_gapful(up_iterator)) // check up_iterator second
			return up_iterator; 
		else
			++up_iterator;
	}
	
	return -1; // shouldn't reach this return
}
