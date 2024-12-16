/*You work at the university registrar, and you have a vector of n student ID numbers that are currently in use at the university. 
To make assigning new student IDs easier, you always keep your vector of IDs in sorted order. 
However, a mischievous EECS 281 student hacked into the system last night and shuffled the order of student IDs in your vector!
Fortunately, the hacker was nice enough to tell you that every ID number in the shuffled vector is at most d positions away 
from its correct sorted position, where d is an integer in the range [1, n). Your goal is to implement a function that can restore 
the sorted vector of student IDs, given the value of d.
Complexity: O(nlog(d)) time and O(d) auxiliaryspace.
Implementation: You may use anything from the STL. Limit: 20 lines of code (points deducted if
longer).
Example: Given d=2 and the following altered vector:
ids = [2, 1, 3, 5, 7, 4, 6]
the restore_sorted_IDs() function should restore ids so that its elements are in sorted order:
                     ids = [1, 2, 3, 4, 5, 6, 7]
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void restore_sorted_IDs(vector<int> &ids, size_t d) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(size_t i=0; i < d+1; i++) {
        pq.push(ids[i]);
    }
    size_t i=0;
    for(; i < ids.size() - d - 1; i++) {
        ids[i] = pq.top();
        pq.pop();
        pq.push(ids[i+d+1]);
    }
    while(!pq.empty()) {
        ids[i] = pq.top();
        pq.pop();
        i++;
    }
}


int main() {
    vector<int> v = {2, 1, 3, 5, 7, 4, 6};

    restore_sorted_IDs(v, 2);

    for(size_t i=0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}



