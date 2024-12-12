// https://leetcode.com/problems/longest-common-prefix/description/https://leetcode.com/problems/longest-common-prefix/description/


#include <iostream>
#include <vector>

using namespace std;



// Time Complexity: O(n*m)
// Space Complexity: O(n)

string longestCommonPrefix(vector<string>& strs) {
	string lcp = "";
	for(size_t i=0; i < strs[0].size(); i++) {
		char c = strs[0][i];
		bool found = true;
		for(size_t j=1; j < strs.size(); j++) {
			if(strs[j].size() < i || strs[j][i] != c) {
				found = false;
				break;
			}
		}
		if(found) {
			lcp += c;
		} else {
			break;
		}
	}
	return lcp;
}



int main() {
	vector<string> v = {"flower","flow","flight"};
	cout << longestCommonPrefix(v) << endl;
}



