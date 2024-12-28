#include <iostream>
#include <set>
#include <stack>
#include <queue>


using namespace std;


template <typename T>
struct Node {
	T data;
	
	Node<T> *left;
	Node<T> *right;

	Node<T>(T data) : data(data), left(nullptr), right(nullptr) {}
};


template <typename T, typename PC>
class Tree {
public:

	Tree<T, PC>() : head(nullptr) {};

	// TC: O(n)
	// SC: O(n)
	~Tree<T, PC>() {
		if(head == nullptr) {
			return;
		}
		queue<Node<T>*> q;
		q.push(head);
		while(!q.empty()) {
			Node<T> *n = q.front();
			q.pop();
			if(n->left != nullptr) {
				q.push(n->left);
			}
			if(n->right != nullptr) {
				q.push(n->right);
			}
			delete n;
		}
	}



	void insert(T data) {
		if(head == nullptr) {
			head = new Node<T>(data);
		} else {
			insertNode(head, data);
		}
	}


	void printTree() {
		if(head == nullptr) {
			return;
		}
		stack<Node<T> *> q;
		q.push(head);
		while(!q.empty()) {
			Node<T> *n = q.top();
			q.pop();
			if(n->left != nullptr) {
				q.push(n->left);
			}
			if(n->right != nullptr) {
				q.push(n->right);
			}
			cout << n->data << " ";
		}
		cout << endl;
	}


	// TC: O(n)
	// SC: O(n)
	bool contains(T data) {
		if(head == nullptr) {
			return false;
		}
		queue<Node<T> *> q;
		while(!q.empty()) {
			Node<T> *n = q.front();
			q.pop();
			if(!compare(n->data, data) && !compare(data, n->data)) {
				return true;
			}
			if(n->left != nullptr) {
				q.push(n->left);
			}
			if(n->right != nullptr) {
				q.push(n->right);
			}
		}
		return false;
	}



private:
	Node<T> *head;
	PC compare;

	// TC: O(log(n))
	// SC: O(log(n))
	void insertNode(Node<T> *n, T data) {
		if(!compare(n->data, data) && !compare(data, n->data)) {
			return;
		}
		if(compare(data, n->data)) {
			if(n->left == nullptr) {
				n->left = new Node<T>(data);
			} else {
				insertNode(n->left, data);
			}
		} else {
			if(n->right == nullptr) {
				n->right = new Node<T>(data);
			} else {
				insertNode(n->right, data);
			}
		}
	}


	

	// TC: O(log(n))
	// SC: O(log(n))
	bool findNode(Node<T> *n, T data) {
		if(n == nullptr) {
			return false;
		}

		if(!compare(n->data, data) && !compare(data, n->data)) {
			return true;
		}
		if(compare(n->data, data)) {
			return findNode(n->right, data);
		} else {
			return findNode(n->left, data);
		}
	}






};


