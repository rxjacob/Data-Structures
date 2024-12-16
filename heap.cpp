#include <iostream>
#include <vector>
#include <queue>


using namespace std;


template <typename T, typename PC>
class Heap {

private:
	vector<T> v;

	PC compare;

	// TC: O(log(n))
	// SC: O(1)
	void fixUp(size_t i) {
		while(i != 0 && compare(v[(i-1)/2], v[i])) {
			swap(v[i], v[(i-1)/2]);
			i = (i-1)/2;
		}
	}

	// TC: O(log(n))
	// SC: O(1)
	void fixDown(size_t i) {
		size_t maxi;
		while(2*i+1 < v.size()) {
			if(2*i+2 >= v.size()) {
				maxi = 2*i+1;
			} else if(compare(v[2*i+2],v[2*i+1])) {
				maxi = 2*i+1;
			} else {
				maxi = 2*i+2;
			}
			if(compare(v[i], v[maxi])) {
				swap(v[i], v[maxi]);
			} else {
				return;
			}

			i = maxi;
		}
	}



public:
	Heap() {}



	size_t size() {
		return v.size();
	}


	T top() {
		return v[0];
	}


	// TC: O(log(n))
	// SC: O(1)
	void push(T val) {
		v.push_back(val);
		fixUp(v.size()-1);
	}


	// TC: O(log(n))
	// SC: O(1)
	void pop() {
		swap(v[0], v[v.size()-1]);
		v.pop_back();
		fixDown(0);
	}

	// TC: O(n)
	// SC: O(1)
	void heapify() {
		
		size_t i = v.size()-1;
		while(i != 0) {
			fixDown(v[i]);
			i = (i-1)/2;
		}
		fixDown(v[i]);
	}



};




