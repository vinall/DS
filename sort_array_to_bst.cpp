#include <iostream>
#include <memory>
using namespace std;

struct node {
	node (int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
	int data;
	shared_ptr<node> left;
	shared_ptr<node> right;
};

shared_ptr<node>
newNode(int number) {
	auto newNode = make_shared<node>(number);
	return newNode;
}

shared_ptr<node>
sortedArrayToBst(int sorted_array[],int start,int end) {
	if(start > end) {
		return nullptr;
	}
	int mid = start + (end-start)/2;
	auto root = newNode(sorted_array[mid]);
	root->left = sortedArrayToBst(sorted_array, start, mid-1);
	root->right = sortedArrayToBst(sorted_array, mid+1, end);
	return root;
}

void display(shared_ptr<node> root) {
	if ( root != nullptr ) {
		display(root->left);
		std::cout << root->data << "\t";
		display(root->right);
	}
}

int
main() {
	int sorted_array[] = {1, 2, 3, 4, 5, 6, 7};  
	auto root = sortedArrayToBst(sorted_array , 0, 6);
	display(root);
	std::cout << std::endl;
	return 0;
}
