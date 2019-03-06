#include <iostream>
#include "linked_list.h"

int
find_mid(const std::shared_ptr<const node> head) {
	auto fast = head;
	auto slow = head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}

int
main() {
	mylist l;
        l.add_node(3);
        l.add_node(4);
        l.add_node(5);
        l.add_node(6);
        l.add_node(7);
        l.add_node(1);
        l.add_node(9);
	auto head = l.getHead();
	std::cout << find_mid(head) << std::endl;

	l.display();	
	return 0;
}
