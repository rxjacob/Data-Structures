#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;






int main() {
	vector<string> vec = {"John", "Jack", "Jason", "Joe", "John"};

	unordered_map<string, int> um;


	for(auto it = vec.begin(); it != vec.end(); it++) {
		if(um.find(*it) == um.end()) {
			um.insert({*it, 1});
		} else {
			um[*it]++;
		}
	}

	int max = 0;
	string name = "";
	for(auto it = um.begin(); it != um.end(); it++) {
		if(it->second > max) {
			max = it->second;
			name = it->first;
		}
	}

	cout << name << endl;
}