#include <memory>
#include <iostream>
struct node{
	node(int data,std::shared_ptr<node> left,std::shared_ptr<node> right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
	int data;
	std::shared_ptr<node> left;
	std::shared_ptr<node> right;
};

class BinarySearchTree{
	public:
		BinarySearchTree() {
		}
		void add_node(int data){
			if(root == nullptr)
				root = create_node(data);
			else {
				root = insert_recursion(root,data);
			}
		}
		void display() {
			auto temp = root;
			inorder(root);
		}
		std::shared_ptr<node> getRoot() {
			return root;
		}
	private:
		void inorder(std::shared_ptr<node> bst){
			if(bst == nullptr)
				return;
			inorder(bst->left);
			std::cout << bst->data;
			inorder(bst->right);
		}

		void insert(int data) {
			auto temp = root;
			while(temp) {
				if(temp->data > data) {
					if(temp->left == nullptr)
						temp->left = create_node(data);
					else
						temp = temp->left;
				}
				else {
					if(temp->right == nullptr) 
						temp->right = create_node(data);
					else
						temp = temp->right;
				}
			}
		}	
		std::shared_ptr<node>
			insert_recursion(std::shared_ptr<node> bst,int data) {
				if(bst == nullptr) {
					bst = create_node(data);
					return bst;
				}
				if(bst->data > data)
					bst->left = insert_recursion(bst->left,data);
				else if(bst->data < data)
					bst->right = insert_recursion(bst->right,data);
				return bst;	
			}
		std::shared_ptr<node> create_node(int data) {
			auto res = std::make_shared<node>(data,nullptr,nullptr);
			return res;
		}
		std::shared_ptr<node> root;
};
