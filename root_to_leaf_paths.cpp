#include <iostream>
#include <vector>
using namespace std;

struct 
binary_tree {
	int data;
	binary_tree *left;
	binary_tree *right;
};

int 
height(binary_tree *root) {
	if(root == nullptr)
		return 0;
	int left_height = height(root->left);
	int right_height = height(root->right);
	return (1+max(left_height,right_height));
}

binary_tree *
newNode(int number) {
	binary_tree *node = new binary_tree();
	node->data = number;
	node->left = nullptr;
	node->right = nullptr;
}

void
print_path(vector<int> arr){
	for(const auto &i : arr)
		std::cout << i << "->";
	std::cout << std::endl;
}

void
root_to_leaf_paths(binary_tree *root,vector<int> arr) {
	if(root == nullptr)
		return;
	arr.push_back( root->data);
	if(root->left == nullptr && root->right == nullptr) {
		print_path(arr);
		return;
	}
	root_to_leaf_paths(root->left,arr);
	root_to_leaf_paths(root->right,arr);
	arr.pop_back();
}

int
main() {
	/*binary_tree *root = newnode(10); 
	  root->left        = newnode(8); 
	  root->right       = newnode(2); 
	  root->left->left  = newnode(3); 
	  root->left->right = newnode(5); 
	  root->right->left = newnode(2); */
	binary_tree *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->right->left->right = newNode(8);
	int h = height(root) ;
	vector<int> paths;
	root_to_leaf_paths(root,paths);
	return 0;
}
