#include "binary_tree.h"
#include <iostream>

void
print_left_boundary(std::shared_ptr< node> root) {
	if(root == nullptr)
		return;
	while(root->left || root->right){
		std::cout << root->data << "->\t";
		root = root->left;
	}
}
void
print_leaf(std::shared_ptr<node> root) {
	if(root == nullptr)
		return;
	if(root->left == nullptr && root->right == nullptr)
		std::cout << root->data << "->\t";
	print_leaf(root->left);
	print_leaf(root->right);
}

void
print_right_boundary(std::shared_ptr<node> root) {
	if(root == nullptr)
		return;
	while(root->left || root->right) {
		std::cout << root->data << "->\t";
		root = root->right;
	}
}

int
main() {
	BinarySearchTree tree;
	tree.add_node(20);
	tree.add_node(8);
	tree.add_node(4);
	tree.add_node(12);
	tree.add_node(10);
	tree.add_node(14);
	tree.add_node(22);
	tree.add_node(25);
	auto root = tree.getRoot();
	print_left_boundary(root);
	print_leaf(root);
	print_right_boundary(root->right);
	std::cout << std::endl;
	return 0;
}
