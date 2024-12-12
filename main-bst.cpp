#include "bst.cpp"
#include <set>
#include <map>

struct Player {
	string name;
	int number;

	Player(string name, int number) : name(name), number(number) {}

};

struct PlayerCompare {
	bool operator()(Player p1, Player p2) {
		return p1.number < p2.number;
	}
};


int main() {
	Tree<int, less<int>> t;
	t.insert(5);
	t.insert(3);
	t.insert(7);
	t.insert(1);
	t.insert(9);
	t.insert(6);
	t.insert(4);
	t.insert(7);
	t.printTree();

	cout << endl;
	cout << t.contains(1) << endl;
	cout << t.contains(2) << endl;


	Tree<Player, PlayerCompare> team;
	team.insert(Player("John", 1));
	team.insert(Player("Jack", 2));




	set<int> s;
	s.insert(5);
	s.insert(3);
	s.insert(7);
	s.insert(1);
	s.insert(9);
	s.insert(6);
	s.insert(4);
	s.insert(7);
	s.erase(4);
	auto it = s.find(7);
	cout << *it << endl;
	it++;
	cout << *it << endl;



	map<int, string> m;
	m.insert(make_pair(1, "John"));
	pair<int, string> p2 = make_pair(2, "Jon");
	m.insert(p2);
	m.insert({3, "Jhon"});
	m.insert(make_pair(4, "Juan"));
	m.erase(1);
	auto it2 = m.find(3);
	pair<int, string> p1 = *it2;
}

