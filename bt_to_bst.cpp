#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "binary_tree.h"


class BinaryTree{
	public:
		BinaryTree(){ }
		void display() {
			inorder(root);
			std::cout << std::endl;
		}
		void create_tree() {
			root = create_node(10); 
			root->left = create_node(30); 
			root->right = create_node(15); 
			root->left->left = create_node(20); 
			root->right->right = create_node(5); 
		}
		void inorder_to_array(std::shared_ptr<node> temp,std::vector<int> &vec) {
			if(temp==nullptr)
				return;
			inorder_to_array(temp->left,vec);
			vec.push_back(temp->data);
			inorder_to_array(temp->right,vec);
		}
		void vec_to_bst(std::vector<int> vec,std::shared_ptr<node> node)  {
			static int i =0;
			if(node==nullptr)
				return;
			vec_to_bst(vec,node->left);
			node->data = vec[i];
			i++;
			vec_to_bst(vec,node->right);
		}
		void binaryTreeToBST(){
			std::vector<int> vec;
			inorder_to_array(root,vec);
			std::sort(vec.begin(),vec.end());
			vec_to_bst(vec,root);
			std::cout << std::endl;
		}

	private:
		void inorder(std::shared_ptr<node> temp) {
			if(temp == nullptr)
				return;
			inorder(temp->left);
			std::cout << temp->data << "->\t";
			inorder(temp->right);
		}
		std::shared_ptr<node> create_node(int data) {
			auto newNode = std::make_shared<node>(data,nullptr,nullptr);
			return newNode;
		}
		std::shared_ptr<node> root;

};

int
main() {
	BinaryTree obj;
	obj.create_tree();
	obj.display();
	obj.binaryTreeToBST();
	obj.display();
	return 0;
}
