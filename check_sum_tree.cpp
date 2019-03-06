#include <iostream>
#include <queue>
using namespace std;

struct binary_tree{
	binary_tree(int number) { this->data = number ; } 
	int data;
	binary_tree *left;
	binary_tree *right;
};

binary_tree * 
newNode(int number) {
	binary_tree *node = new binary_tree(number);
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

int
sum_tree(binary_tree *root) {
	if(root == nullptr)
		return 0;
	int res = sum_tree(root->left) + root->data + sum_tree(root->right);
	return res;
}
bool
checkSumTree(binary_tree *root) {
	if(root == nullptr)
		return true;
	if(root->left == nullptr && root->right == nullptr)
		return true;
	int data = (root->left? sum_tree(root->left) : 0)  + (root->right ? sum_tree(root->right) : 0);
	auto left = checkSumTree(root->left);
	auto right = checkSumTree(root->right);
	return (data == root->data) && left && right;
}

void display(binary_tree *root) {
	std::queue<binary_tree *> q;
	q.push(root);
	int inner_loop;
	while(!q.empty()) {
		inner_loop = q.size();
		while(inner_loop>0) {
			auto val = q.front();
			q.pop();
			std::cout << val->data << "\t";
			if(val->left)
				q.push(val->left);
			if(val->right)
				q.push(val->right);
			inner_loop--;
		}
		std::cout << "\n";
	}
}

int
main() {
	struct binary_tree *root  = newNode(26); 
	root->left         = newNode(10); 
	root->right        = newNode(3); 
	root->left->left   = newNode(4); 
	root->left->right  = newNode(6); 
	root->right->right = newNode(3); 
	display(root);
	auto flag = checkSumTree(root);
	if(flag)
		std::cout << "Tree is sum tree\n";
	else
		std::cout << "This tree is not sum tree\n";
	return 0;
}
