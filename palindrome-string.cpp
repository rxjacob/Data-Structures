//https://leetcode.com/problems/valid-palindrome/description/

#include <iostream>
#include <cctype>
using namespace std;


// Time Complexity: O(n)
// Space Complexiy: O(n)


string fixStr(string s) {
	string str = "";
	for(size_t i=0; i < s.size(); i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
		if(s[i] >= 'a' && s[i] <= 'z') {
			str += s[i];
		}
	}
	return str;
}


bool isPalindrome(string s) {
	s = fixStr(s);
	string reversedStr = "";

	for(auto it = s.rbegin(); it != s.rend(); it++) {
		reversedStr += *it;
	}

	if(s == reversedStr) {
		return true;
	}
	return false;
	
}






int main_() {
	if(isPalindrome("A man, a plan, a canal: Panama")) {
		cout << "It is a palindrome" << endl;
	} else {
		cout << "It is not a palindrome" << endl;
	}
	return 0;
}