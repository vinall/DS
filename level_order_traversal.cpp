#include <iostream>
#include <queue>
using namespace std;

struct 
binary_tree{
	int data;
	binary_tree *left;
	binary_tree *right;
};

void
level_order_traversal(binary_tree *root) {
	std::queue<binary_tree *> bt_queue;
	bt_queue.push(root);
	while(!bt_queue.empty()) {
		int h = bt_queue.size()-1;
		while(h>=0) {
			auto *node = bt_queue.front();
			bt_queue.pop();
			std::cout << node->data << "->\t";
			if(node->left)
				bt_queue.push(node->left);
			if(node->right)
				bt_queue.push(node->right);
			h--;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

binary_tree *
newNode(int number) {
	binary_tree *node = new binary_tree();
	node->data = number;
	node->left = nullptr;
	node->right = nullptr;
}

int
main() {
	binary_tree *root =  newNode(1); 
	root->left        = newNode(2); 
	root->right       = newNode(3); 
	root->left->left  = newNode(4); 
	root->left->right = newNode(5); 
	level_order_traversal(root);
	return 0;
}
