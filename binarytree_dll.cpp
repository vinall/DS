#include <iostream>
#include "binary_tree.h"

void
bintree_to_dll(std::shared_ptr<node> root,std::shared_ptr<node> prev) {
    if(root == nullptr)
        return ;
    bintree_to_dll(root->left,prev);
    root->left = prev;
    if(prev != nullptr)
        prev->right = root;
    prev = root;
    bintree_to_dll(root->right,prev);
}

void
display(std::shared_ptr<node> root) {
    auto temp = root;
    while(root!=nullptr) {
         if(root->right == nullptr)
            temp = root;
        std::cout << root->data << "->\t";
        root = root->right;
   }
    std::cout << std::endl;
    
    while(temp!=nullptr) {
        std::cout << temp->data << "->\t";
        temp = temp->left;
    }
    std::cout << std::endl;

}

int
main() {
    BinarySearchTree mytree;
    mytree.add_node(1);
    mytree.add_node(2);
    mytree.add_node(4);
    mytree.add_node(5);
    mytree.add_node(7);
    mytree.add_node(8);
    mytree.add_node(3);
    mytree.add_node(6);
    mytree.add_node(9);
    mytree.add_node(10);
    mytree.display();
    std::cout << std::endl;
    auto root = mytree.getRoot();
    std::shared_ptr<node> prev;
    bintree_to_dll(root,prev);
    display(root);
    return 0;
}
