// Find the negative counterpart
// Ex: {4, 8, -3, -2, -8, 5, -5, -4, 3}


#include <iostream>
#include <vector>

using namespace std;


// Time Complexity: O(n^2)
// Space Complexiy: O(1)

int findMissingCounterpart(vector<int> &vec) {
	for(size_t i=0; i < vec.size(); i++) {
		bool hasCounterpart = false;
		for(size_t j=0; j < vec.size(); j++) {
			if(vec[j] == vec[i] * -1) {
				hasCounterpart = true;
			}
		}
		if(hasCounterpart == false) {
			return vec[i];
		}
	}
	return 0;
}




int findMissingCounterpart2(vector<int> &vec) {
	int sum = 0;
	for(auto it = vec.begin(); it != vec.end(); it++) {
		sum += *it;
	}
	return sum;
}





int main() {
	vector<int> v = {4, 8, -3, -2, -8, 5, -5, -4, 3};
	cout << findMissingCounterpart(v) << endl;
	cout << findMissingCounterpart2(v) << endl;
}



