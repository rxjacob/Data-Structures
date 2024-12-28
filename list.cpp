#include <iostream>
#include <queue>
#include <stack>


using namespace std;

template <typename T>
struct ListNode {
	T val;
	ListNode<T> *next;
	//ListNode<T> *prev;
};


template <typename T>
class List {
	private:
		ListNode<T> *head;
		ListNode<T> *tail;
		size_t vSize;

		// TC: O(n)
		// SC: O(1)
		void printNode(ListNode<T> *n) {
			if(n == nullptr) {
				return;
			}
			cout << n->val << " ";
			printNode(n->next);
		}

	public:
		List<T>() : head(nullptr), tail(nullptr), vSize(0) {}

		~List<T>() {
			ListNode<T> *n = head;
			while(n != nullptr) {
				ListNode<T> *temp = n->next;
				delete n;
				n = temp;
			}
		}

		// TC: O(1)
		// SC: O(1)
		void push_back(T datum) {
			vSize++;
			if(head == nullptr) {
				head = new ListNode<T>();
				head->val = datum;
				head->next = nullptr;
				tail = head;
				return;
			}
			ListNode<T> *n = new ListNode<T>();
			n->val = datum;
			tail->next = n;
			tail = n;
			tail->next = nullptr;
		}

		// TC: O(1)
		// SC: O(1)
		void push_front(T datum) {
			vSize++;
			if(head == nullptr) {
				head = new ListNode<T>();
				head->val = datum;
				head->next = nullptr;
				return;
			}
			ListNode<T> *temp = head;
			head = new ListNode<T>();
			head->val = datum;
			head->next = temp;
		}

		// TC: O(1)
		// SC: O(1)
		void pop_front() {
			vSize--;
			ListNode<T> *temp = head;
			head = head->next;
			delete temp;
		}

		// TC: O(n)
		// SC: O(1)

		void pop_back() {
			vSize--;
			if(head->next == nullptr) {
				delete head;
				head = nullptr;
				tail = nullptr;
				return;
			}
			ListNode<T> *n = head;
			while(n->next->next != nullptr) {
				n = n->next;
			}
			tail = n;
			delete n->next;
			n->next = nullptr;
		}

		// TC: O(1)
		// SC: O(1)
		T front() {
			return head->val;
		}

		// TC: O(1)
		// SC: O(1)
		T back() {
			return tail->val;
		}


		// TC: O(1)
		// SC: O(1)
		size_t size() {
			return vSize;
		}



		void printList() {
			printNode(head);
			cout << endl;
		}


};


int main() {
	List<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	cout << endl;
	myList.printList();

	cout << endl;

	queue<int> myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	int queueFront = myQueue.front();
	cout << queueFront << endl;
	myQueue.pop();
	cout << myQueue.size() << endl;
	cout << myQueue.empty() << endl;
	myQueue.pop();
	myQueue.pop();
	cout << myQueue.empty() << endl;



	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	int stackTop = s.top();
	cout << stackTop << endl;
	s.pop();
	cout << s.size() << endl;
	cout << s.empty() << endl;
	s.pop();
	s.pop();
	cout << s.empty() << endl;
}


