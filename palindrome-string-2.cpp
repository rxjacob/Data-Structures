//https://leetcode.com/problems/valid-palindrome/description/

#include <iostream>
#include <cctype>
using namespace std;


// Time Complexity: O(n)
// Space Complexiy: O(1)

bool isUppercase(char c) {
	if(c >= 'A' && c <= 'Z') {
		return true;
	}
	return false;
}


bool isLowercase(char c) {
	if(c >= 'a' && c <= 'z') {
		return true;
	}
	return false;
}


bool isPalindrome(string s) {
	for(size_t i=0, j = s.size()-1; i <= j; i++, j--) {
		while(!isUppercase(s[i]) && !isLowercase(s[i])) {
			i++;
		}
		while(!isUppercase(s[j]) && !isLowercase(s[j])) {
			j--;
		}
		if(i <= j) {
			break;
		}

		if(isUppercase(s[i])) {
			s[i] += 32;
		}
		if(isUppercase(s[j])) {
			s[j] += 32;
		}

		if(s[i] != s[j]) {
			return false;
		}
	}
	return true;
}



int main_() {
	if(isPalindrome("A man, a plan, a canal: Panama")) {
		cout << "It is a palindrome" << endl;
	} else {
		cout << "It is not a palindrome" << endl;
	}
	return 0;
}