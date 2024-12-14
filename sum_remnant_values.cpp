/*
Suppose you were given a vector<int> and a number k, and you consider k or more copies of the same 
value in a row to constitute a "group". You need to sum up any values that are left over after forming groups; 
these left over values are the remnants. For example, given k = 3 and the following vector:
 {3, 5, 5, 2, 2, 2, 5, 5, 5, 2, 3, 4, 4, 4, 3}
Starting from the left, there is one copy of 3 (not a group, since k = 3), followed by two 5’s (which are also not a group). 
These are followed by three 2’s, which do form a group, and thus are not remnants. This means we effectively have this remaining:
 {3, 5, 5, 5, 5, 5, 2, 3, 4, 4, 4, 3}
Now there are five copies of the value 5, which do form a group. Thus, the portion remaining to be considered is:
 {3, 2, 3, 4, 4, 4, 3}
The cluster of three 4’s is a group, leaving:
{3, 2, 3, 3}
Even though there are k copies of the value 3 remaining, they are not consecutive, and thus do not form a group. 
Your function should return the sum of these remnants, which is 11.
You may assume that seq is not empty, and that k > 1. Example:
vector<int> seq = {3, 5, 5, 2, 2, 2, 5, 5, 5, 2, 3, 4, 4, 4, 3}; int k = 3;
cout << sum_remnant_values(seq, k) << endl; // displays 11
Complexity: O(n)timeandO(n)auxiliaryspace,wherenisthesizeofthegivenvector.
Implementation: You may use anything from the STL. Limit: 30 lines of code (points deducted if longer).
*/
#include <iostream>
#include <vector>

using namespace std;


struct myCount{
	int num;
	int count;
};



int sum_remnant_values(const vector<int> &seq, int k) {
	vector<myCount> sortedVec;

	sortedVec.push_back({seq[0], 1});

	for(size_t i=1; i < seq.size(); i++) {

		if(sortedVec[sortedVec.size() - 1].num == seq[i]) {
			sortedVec[sortedVec.size() - 1].count++;
		} else {
			if(sortedVec[sortedVec.size() - 1].count >= k) {
				sortedVec.pop_back();
			}
			if(sortedVec[sortedVec.size() - 1].num == seq[i]) {
				sortedVec[sortedVec.size() - 1].count++;
			} else {
				sortedVec.push_back({seq[i], 1});
			}
		}
		
	}

	int sum = 0;
	for(size_t i=0; i < sortedVec.size(); i++) {
		sum += sortedVec[i].num * sortedVec[i].count;
	}

	return sum;
}


int main() {
	vector<int> vec = {3, 5, 5, 2, 2, 2, 5, 5, 5, 2, 3, 4, 4, 4, 3};

	cout << sum_remnant_values(vec, 3) << endl;
}


