#include "bfs-dfs.cpp"
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

}