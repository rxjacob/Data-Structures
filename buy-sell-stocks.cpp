// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

// TC: O(n^2)
// SC: O(1)
int maxProfitBF(vector<int>& prices) {
    int max = 0;

    for(size_t i=0; i < prices.size(); i++) {
    	for(size_t j=i; j < prices.size(); j++) {
    		if(prices[j] - prices[i] > max) {
    			max = prices[j] - prices[i];
    		}
    	}
    }

    return max;
}

// TC: O(nlog(n))
// SC: O(n)
int maxProfitPQ(vector<int>& prices) {
	priority_queue<int, vector<int>, greater<int>> pq;

	int max = 0;

	if(prices.size() == 0) {
		return 0;
	}

	pq.push(prices[0]);

	for(size_t i=1; i < prices.size(); i++) {
		if(max < (prices[i] - pq.top())) {
			max = prices[i] - pq.top();
		}
		pq.push(prices[i]);
	}

	return max;
}


// TC: O(n)
// SC: O(1)
int maxProfit(vector<int>& prices) {
	int max = 0;

	int minSoFar = INT_MAX;

	for(size_t i=0; i < prices.size(); i++) {
		if(prices[i] < minSoFar) {
			minSoFar = prices[i];
		}
		if(max < (prices[i] - minSoFar)) {
			max = prices[i] - minSoFar;
		}
	}
	return max;
}






int main() {
	vector<int> v = {7,1,5,3,6,4};

	cout << maxProfit(v) << endl;
}