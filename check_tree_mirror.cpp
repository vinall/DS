#include <iostream>

using namespace std;

struct binary_tree {
	int data;
	binary_tree *left;
	binary_tree *right;
};

bool
check_tree_mirror(binary_tree *tree1,binary_tree *tree2) {
	if(tree1 == nullptr && tree2 == nullptr)
		return true;
	if(tree1 == nullptr || tree2 == nullptr)
		return false;
	return (tree1->data == tree2->data) && check_tree_mirror(tree1->left,tree2->right) && check_tree_mirror(tree1->right,tree2->left);
}

binary_tree *
newNode(int number) {
	binary_tree *node = new binary_tree();
	node->data = number;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

int
main() {
	binary_tree *a = newNode(1); 
	binary_tree *b = newNode(1); 
	a->left = newNode(2); 
	a->right = newNode(3); 
	a->left->left  = newNode(4); 
	a->left->right = newNode(5); 

	b->left = newNode(3); 
	b->right = newNode(2); 
	b->right->left = newNode(5); 
	b->right->right = newNode(4); 
	check_tree_mirror(a,b) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
