// https://leetcode.com/problems/palindrome-number/


#include <iostream>

using namespace std;

// Space complexity: O(1)
// Time complexity: O(n)

bool isPalindrome(int x) {
	int ogNum = x;
	int reversedNum = 0;

	while(x > 0) {
		int digit = x % 10;
		reversedNum = (reversedNum * 10) + digit;
		x /= 10;
	}

	if(ogNum == reversedNum) {
		return true;
	}
	return false;
}

int main_() {
	if(isPalindrome(1234321)) {
		cout << "It is a palindrome" << endl;
	} else {
		cout << "It is not a palindrome" << endl;
	}
	return 0;
}