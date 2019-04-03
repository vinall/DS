#include <iostream>
#include "linked_list.h"
#include <unordered_set>

std::shared_ptr<node>
intersection(std::unordered_set<int> first_list,std::shared_ptr<node> head2) {
	mylist newlist;
	while ( head2 != nullptr ) {
		if ( first_list.find(head2->data) != first_list.end() ) {
			newlist.add_node(head2->data);
		}
		head2 = head2->next;
	}
	return newlist.getHead();
}

std::shared_ptr<node>
union_f(std::unordered_set<int> first_list,std::shared_ptr<node> head1, std::shared_ptr<node> head2) {
	mylist newlist;

	while(head1 != nullptr) {
		newlist.add_node(head1->data);
		head1 = head1->next;
	}
	while ( head2 != nullptr ) {
		if ( first_list.find(head2->data) == first_list.end()) {
			newlist.add_node(head2->data);
		}
		head2 = head2->next;
	}
	return newlist.getHead();
}

void
display(std::shared_ptr<node> lt) {
	while ( lt ) {
		std::cout << lt->data << "\t";
		lt = lt->next;
	}
	std::cout << std::endl;
}

int
main() {
	std::unordered_set<int> first_list;
	mylist l1,l2;
	l1.add_node(20);
	l1.add_node(4);
	l1.add_node(15);
	l1.add_node(10);

	l2.add_node(10);
	l2.add_node(2);
	l2.add_node(4);
	l2.add_node(8);
	
	auto head1 = l1.getHead();
	auto head2 = l2.getHead();
	auto l = head1;
	while ( l != nullptr) {
		first_list.insert(l->data);
		l = l->next;
	}

	auto intersection_list = intersection(first_list,head2);
	display(intersection_list);
	auto union_list = union_f(first_list,head1,head2);
	display(union_list);
	return 0;
}

