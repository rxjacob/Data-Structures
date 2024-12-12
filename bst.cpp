#include <iostream>
#include <set>


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


	~Tree<T, PC>() {
		deleteNode(head);
	}



	void insert(T data) {
		if(head == nullptr) {
			head = new Node<T>(data);
		} else {
			insertNode(head, data);
		}
	}


	void printTree() {
		printNode(head);
	}


	// TC: O(log(n))
	// SC: O(1)
	bool contains(T data) {
		Node<T> *n = head;
		while(n != nullptr) {
			if(!compare(n->data, data) && !compare(data, n->data)){
				return true;
			}
			if(compare(n->data, data)) {
				n = n->right;
			} else {
				n = n->left;
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

	// TC: O(n)
	// SC: O(n)
	void printNode(Node<T> *n) {
		if(n == nullptr) {
			return;
		}
		cout << n->data << " ";
		printNode(n->left);
		printNode(n->right);
	}


	// TC: O(n)
	// SC: O(n)
	void deleteNode(Node<T> *n) {
		if(n == nullptr) {
			return;
		}
		deleteNode(n->left);
		deleteNode(n->right);
		delete n;
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


