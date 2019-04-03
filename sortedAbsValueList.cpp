#include <iostream>
#include <memory>

using namespace std;

struct node {
	node(int data) {
		this->data = data;
		this->next = nullptr;
	}
	int data;
	shared_ptr<node> next;
};


shared_ptr<node>
newNode(int number) {
	auto newNode = make_shared<node>(number);
	return newNode;
}

shared_ptr<node>
sortAbs(shared_ptr<node> l) {
	auto temp = l;
	shared_ptr<node> prev;
	shared_ptr<node> newHead = nullptr;
	while ( l && l->data > 0 ) {
		prev = l;
		l = l->next;
	}

	if (prev != nullptr) {
		prev->next = nullptr;
		newHead = l;
		while( l->next != nullptr ) {
			l = l->next;
		}
		l->next = temp;
	}
	return newHead == nullptr ? temp : newHead;
}

void
display(shared_ptr<node> res) {
	while(res != nullptr) {
		std::cout << res->data << "->\t";
		res = res->next;
	}
	std::cout << std::endl;
}

int
main() {
	shared_ptr<node> l1 = make_shared<node>(1);
	l1->next = make_shared<node>(-10);
	l1->next->next = nullptr;
	auto res = sortAbs(l1);
	display(res);
	return 0;
}
