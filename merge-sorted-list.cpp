// Merge sorted list
// https://leetcode.com/problems/merge-two-sorted-lists/description/  (NO STRUCT)


#include <iostream>

using namespace std;


struct Node {
	int data;
	Node *next;

	Node(int data) : data(data), next(nullptr) {}
};


// TC: O(n)
// SC: O(n)

Node* mergeTwoLists(Node* list1, Node* list2) {
	Node *list3 = nullptr;

	if(list1 == nullptr && list2 == nullptr) {
		return nullptr;
	}


	if(list1 == nullptr || list1->data > list2->data) {
		list3 = new Node(list2->data);
		list2 = list2->next;
	} else {
		list3 = new Node(list1->data);
		list1 = list1->next;
	}

	Node *list3head = list3;

	while(list1 != nullptr && list2 != nullptr) {
		if(list1->data > list2->data) {
			list3->next = new Node(list2->data);
			list2 = list2->next;
		} else {
			list3->next = new Node(list1->data);
			list1 = list1->next;
		}
		list3 = list3->next;
	}

	while(list1 != nullptr) {
		list3->next = new Node(list1->data);
		list1 = list1->next;
		list3 = list3->next;
	}

	while(list2 != nullptr) {
		list3->next = new Node(list2->data);
		list2 = list2->next;
		list3 = list3->next;
	}

	return list3head;

}

// TC: O(n)
// SC: O(1)
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


// TC: O(n)
// SC: O(1)
void deleteList(Node* list) {
	while(list != nullptr) {
		Node *n = list->next;
		delete list;
		list = n;
	}
}


int main() {
	Node *list1 = new Node(1);
	list1->next = new Node(2);
	list1->next->next = new Node(5);

	Node *list2 = new Node(3);
	list2->next = new Node(4);
	list2->next->next = new Node(6);


	Node *mergedList = mergeTwoLists(list1, list2);

	printList(mergedList);

	deleteList(list1);
	deleteList(list2);
	deleteList(mergedList);
}




