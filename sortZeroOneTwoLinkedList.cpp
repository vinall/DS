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

void
sortZeroOneTwo(shared_ptr<node> l1) {
	int a[3] = { 0 };
	auto temp = l1;
	while ( l1 != nullptr) {
		a[l1->data]++;
		l1 = l1->next;
	}
	int i = 0; 
	while ( temp != nullptr) {
		auto t = a[i];
		while ( t != 0 ) {
			temp->data = i;
			temp = temp->next;
			t--;
		}
		i++;
	}
}

void 
display(shared_ptr<node> l1) {
	while ( l1 != nullptr) {
		std::cout << l1->data << "->\t";
		l1 = l1->next;
	}
	std::cout << std::endl;
}

int
main() {
	//{0, 1, 2, 0, 1, 2}
	shared_ptr<node> l1 = make_shared<node>(0);
	l1->next = make_shared<node>(1);
	l1->next->next = make_shared<node>(2);
	l1->next->next->next = make_shared<node>(0);
	l1->next->next->next->next = make_shared<node>(1);
	l1->next->next->next->next->next = make_shared<node>(2);
	l1->next->next->next->next->next->next = make_shared<node>(0);
	display(l1);
	sortZeroOneTwo(l1);
	display(l1);
	return 0;
}
