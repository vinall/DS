#include <iostream>
#include <string>

using namespace std;

struct node {
    string info;
    node(string info) {
        this->info = info;
        left = nullptr;
        right = nullptr;
    }

    node *left;
    node *right;
};


int
eval(node *root) {
	if(root == nullptr)
		return 0;
    if(!root->left && !root->right)
        return std::stoi(root->info);

	auto leval = eval(root->left);
	auto reval = eval(root->right);
	auto res = 0;
	if(root->info == "+") {
		res = leval + reval;
	}
	if(root->info == "*") {
		res = leval * reval;
	}
	if(root->info == "-") {
		res = leval - reval;
	}
	return res;
}

int
main() {
    node *root = new node("+"); 
    root->left = new node("*"); 
    root->left->left = new node("5"); 
    root->left->right = new node("4"); 
    root->right = new node("-"); 
    root->right->left = new node("100"); 
    root->right->right = new node("20"); 
    cout << eval(root) << endl; 

    return 0;
}
