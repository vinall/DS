#include <iostream>
#include "linked_list.h"
using namespace std;

bool
detect_loop(std::shared_ptr<node> head) {
	auto slow = head,fast = head;
	while ( fast != nullptr && fast != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			return true;
		}
	}
	return false;
}

int main() {
	mylist lt;
	lt.add_node(4);
	lt.add_node(2);
	lt.add_node(5);
	lt.add_node(6);
	lt.add_node(7);
	lt.add_node(8);
	auto head = lt.getHead();
	//head->next->next->next->next = head;
	auto flag = detect_loop(head);
	if ( flag ) {
		std::cout << "Yeah\n";
	} else {
		std::cout << "Naah\n";
	}
	return 0;
}

