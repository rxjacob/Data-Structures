// https://leetcode.com/problems/add-binary/description/


#include <iostream>

using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(n)

string addBinary(string a, string b) {
	string sumStr = "";
	int carry = 0;

	auto it1 = a.rbegin(), it2 = b.rbegin();

	for(;it1 != a.rend() && it2 != b.rend(); it1++, it2++) {
		int aDigit = static_cast<int>(*it1) - '0';
		int bDigit = static_cast<int>(*it2) - '0';
		int sum = aDigit + bDigit + carry;

		if(sum == 0) {
			sumStr = '0' + sumStr;
			carry = 0;
		} else if(sum == 1) {
			sumStr = '1' + sumStr;
			carry = 0;
		} else if(sum == 2) {
			sumStr = '0' + sumStr;
			carry = 1;
		} else {
			sumStr = '1' + sumStr;
			carry = 1;
		}
	}
	while(it1 != a.rend()) {
		int aDigit = static_cast<int>(*it1) - '0';
		int sum = aDigit + carry;
		if(sum == 0) {
			sumStr = '0' + sumStr;
			carry = 0;
		} else if(sum == 1) {
			sumStr = '1' + sumStr;
			carry = 0;
		} else if(sum == 2) {
			sumStr = '0' + sumStr;
			carry = 1;
		}
		it1++;
	}
	while(it2 != b.rend()) {
		int bDigit = static_cast<int>(*it2) - '0';
		int sum = bDigit + carry;
		if(sum == 0) {
			sumStr = '0' + sumStr;
			carry = 0;
		} else if(sum == 1) {
			sumStr = '1' + sumStr;
			carry = 0;
		} else if(sum == 2) {
			sumStr = '0' + sumStr;
			carry = 1;
		}
		it2++;
	}

	if(carry == 1) {
		sumStr = '1' + sumStr;
	}


	return sumStr;
}


string addBinary2(string a, string b) {
	string sumStr = "";
	int carry = 0;

	while(!a.empty() && !b.empty()) {
		int aDigit = static_cast<int>(a[a.size() - 1]) - '0';
		int bDigit = static_cast<int>(b[b.size() - 1]) - '0';
		int sum = aDigit + bDigit + carry;

		if(sum == 0) {
			sumStr = '0' + sumStr;
			carry = 0;
		} else if(sum == 1) {
			sumStr = '1' + sumStr;
			carry = 0;
		} else if(sum == 2) {
			sumStr = '0' + sumStr;
			carry = 1;
		} else {
			sumStr = '1' + sumStr;
			carry = 1;
		}

		a.pop_back();
		b.pop_back();
	}
	while(!a.empty()) {
		int aDigit = static_cast<int>(a[a.size() - 1]) - '0';
		int sum = aDigit + carry;
		if(sum == 0) {
			sumStr = '0' + sumStr;
			carry = 0;
		} else if(sum == 1) {
			sumStr = '1' + sumStr;
			carry = 0;
		} else if(sum == 2) {
			sumStr = '0' + sumStr;
			carry = 1;
		}
		a.pop_back();
	}
	while(!b.empty()) {
		int bDigit = static_cast<int>(b[b.size() - 1]) - '0';
		int sum = bDigit + carry;
		if(sum == 0) {
			sumStr = '0' + sumStr;
			carry = 0;
		} else if(sum == 1) {
			sumStr = '1' + sumStr;
			carry = 0;
		} else if(sum == 2) {
			sumStr = '0' + sumStr;
			carry = 1;
		}
		b.pop_back();
	}

	if(carry == 1) {
		sumStr = '1' + sumStr;
	}


	return sumStr;
}


int main() {
	cout << addBinary("1010", "1011") << endl;
	cout << addBinary("11", "1") << endl;
	cout << addBinary2("1010", "1011") << endl;
	cout << addBinary2("11", "1") << endl;
}




