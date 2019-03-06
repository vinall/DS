#include <iostream>
#include <queue>
using namespace std;

struct binary_tree{
	int data;
	binary_tree *left;
	binary_tree *right;
};

binary_tree *
newnode(int num) {
	binary_tree *node = new binary_tree();
	node->data = num;
	node->left = nullptr;
	node->right = nullptr;
}

void
print_node_without_siblings(binary_tree *root) {
	std::queue<binary_tree*> qtree;
	qtree.push(root);
	while(!qtree.empty() ) {
		auto *p = qtree.front();
		qtree.pop();
		if(p->left == nullptr && p->right == nullptr) {
			continue;
		}
		if(p->left == nullptr || p->right == nullptr) {
			p->left ? std::cout << p->left->data << std::endl : std::cout << p->right->data << std::endl;
		}
		if(p->left != nullptr) {
			qtree.push(p->left);
		}
		if(p->right != nullptr) {
			qtree.push(p->right);
		}
	}
}

int
main() {
	binary_tree *root = newnode(1);
	root->left = newnode(2);
	root->left->right = newnode(4);
	root->right = newnode(3);
	root->right->left = newnode(5);
	root->right->left->left = newnode(6);
	print_node_without_siblings(root);
	return 0;
}
