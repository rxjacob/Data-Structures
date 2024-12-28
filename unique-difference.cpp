/*
Given two vectors, a and b, return a vector of all unique elements that are NOT members of both a and b. 
If there are duplicate elements within one vector that do not appear in the other, 
you may select an arbitrary element from the duplicates to include 
(i.e., you may pick the element to include; see the example with 8 in vector b below). 
Elements in the vectors may be compared using the < and == operators. You may return the output in any order.
Example: Given
vector<int> a = {2, 1, 0, 5, 3, 7};
vector<int> b = {0, 5, 8, 0, 8};
callingunique_difference(a, b)willreturnavectorcontaining{1, 2, 3, 7, 8}(inanyorder).
Complexity: O(n log(n)) time and O(n) space (in addition to memory for the returned vector), wheren = a.size() + b.size().
Implementation: Write your code neatly in the space below. Limit: 30 lines of code (points deducted if longer). 
You MAY use any STL algorithms/functions.
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <class T>
vector<T> unique_difference(vector<T> a, vector<T> b) {

	set<T> uda;
	set<T> udb;

	set<T> ud;

	vector<T> diff;

	for(size_t i=0; i < a.size(); i++) {
		uda.insert(a[i]);
	}
	for(size_t i=0; i < b.size(); i++) {
		udb.insert(b[i]);
	}

	for(size_t i=0; i < a.size(); i++) {
		if(udb.find(a[i]) == udb.end()) {
			ud.insert(a[i]);
		}
	}
	for(size_t i=0; i < b.size(); i++) {
		if(uda.find(b[i]) == uda.end()) {
			ud.insert(b[i]);
		}
	}

	for(auto it = ud.begin(); it != ud.end(); it++) {
		diff.push_back(*it);
	}

	return diff;
}


int main() {
	vector<int> a = {2, 1, 0, 5, 3, 7};
	vector<int> b = {0, 5, 8, 0, 8};

	vector<int> result = unique_difference(a, b);

	for(size_t i=0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}
