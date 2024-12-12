// Reverse linked list
// https://leetcode.com/problems/reverse-linked-list/description/
// reverseList()

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// deleteDuplicates()


#include <iostream>

using namespace std;


struct Node {
	int data;
	Node *next;

	Node(int data) : data(data), next(nullptr) {}
};



Node* reverseList(Node* list) {
	if(list == nullptr) {
		return nullptr;
	}
	Node *prev = nullptr;
	Node *curr = list;
	while(curr != nullptr) {
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}


void printList(Node* list) {
	if(list == nullptr) {
		return;
	}
	while(list->next != nullptr) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << list->data << endl;
}


void deleteList(Node* list) {
	while(list != nullptr) {
		Node *n = list->next;
		delete list;
		list = n;
	}
}


Node* deleteDuplicates(Node *list) {
	Node *head = list;

	while(list != nullptr && list->next != nullptr) {
		if(list->data == list->next->data) {
			Node *temp = list->next;
			list->next = list->next->next;
			delete temp;
		}
		list = list->next;
	}
	return head;
}







int main() {
	Node *list = new Node(1);
	list->next = new Node(2);
	list->next->next = new Node(3);
	list->next->next->next = new Node(4);


	Node *reversedList = reverseList(list);

	printList(reversedList);

	deleteList(reversedList);

	cout << "-----" << endl;

	Node *list2 = new Node(1);
	list2->next = new Node(2);
	list2->next->next = new Node(3);
	list2->next->next->next = new Node(3);
	list2->next->next->next->next = new Node(4);
	list2->next->next->next->next->next = new Node(4);

	Node *noDuplicates = deleteDuplicates(list2);

	printList(noDuplicates);

	deleteList(noDuplicates);
}




