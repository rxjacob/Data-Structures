/*Given a vector of integers (of size n, n > 1), find the smallest section of the vector such that sorting that section will 
make the entire vector sorted (in increasing order). You should display the first and last indices that need to be sorted 
(BOTH inclusive, using 0-based indexing). You can assume that your function WILL be called with a vector containing exactly 
one such section.
Forexample,giventheinputvector:{ 1, 2, 5, 7, 3, 6, 4, 8 } Youroutputshouldbe:Sort from index 2 to index 6
Hint: You can use INT_MAX and INT_MIN for the largest and smallest values that can fit inside a variable of type int.
Requirements: Your solution runtime must be no worse than O(n) time. You may use up to O(1) auxiliary space.
Implementation: Write your code neatly in the space below. Limit: 20 lines of code (points deducted if longer). 
You may NOT use any STL algorithms, functions or containers (except the provided vector).*/


#include <vector>
#include <climits>
#include <iostream>


using namespace std;


void find_subarray(const vector<int> &v) {
	int lefti = -1;
	int righti = -1;

	int max_so_far = INT_MIN;
	int min_so_far = INT_MAX;


	for(size_t i=0; i < v.size(); i++) {
		if(max_so_far < v[i]) {
			max_so_far = v[i];
		}
		if(v[i] < max_so_far) {
			righti = static_cast<int>(i);
		}
	}

	for(int i = static_cast<int>(v.size() - 1); i >= 0; i--) {
		if(min_so_far > v[static_cast<size_t>(i)]) {
			min_so_far = v[static_cast<size_t>(i)];
		}
		if(v[static_cast<size_t>(i)] > min_so_far) {
			lefti = i;
		}
	}

	cout << "Sort from index " << lefti << " to index " << righti << endl;
}



int main() {
	vector<int> v = {1, 2, 5, 7, 3, 6, 4, 8};

	find_subarray(v);
}



