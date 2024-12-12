#include <iostream>
#include <vector>
#include <queue>

#include "heap.cpp"

using namespace std;


struct Player {
	string name;
	int number;
};


struct PlayerCompare {
	bool operator()(Player p1, Player p2) {
		return p1.number < p2.number;
	}
};



int main() {
	Heap<int, greater<int>> h;
	h.push(15);
	h.push(14);
	h.push(20);
	h.push(10);
	h.push(6);
	h.push(8);
	cout << h.top() << endl;
	h.pop();
	cout << h.top() << endl;


	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(15);
	pq.push(14);
	pq.push(20);
	pq.push(10);
	pq.push(6);
	pq.push(8);
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;


	Heap<Player, PlayerCompare> h2;
	Player p1;
	p1.name = "John";
	p1.number = 1;

	Player p2;
	p2.name = "Jon";
	p2.number = 2;

	Player p3;
	p3.name = "Jhon";
	p3.number = 3;


	h2.push(p1);
	h2.push(p2);
	h2.push(p3);
	cout << h2.top().name << endl;
	h2.pop();
	cout << h2.top().name << endl;

}