#include <iostream>
#include "binary_tree.h"

int
diameter_of_binary_tree(std::shared_ptr<node> root,int *height) {
    if(root == nullptr) {
        *height = 0;
        return 0;
    }
    int ldiameter = 0 , rdiameter = 0;
    int lh = 0 , rh = 0;
    ldiameter = diameter_of_binary_tree(root->left,&lh);
    rdiameter = diameter_of_binary_tree(root->right,&rh);
    *height = std::max(lh,rh) + 1;
    return std::max(lh + rh + 1, std::max(ldiameter,rdiameter));
}

int
main() {
    BinarySearchTree mytree;
    mytree.add_node(1);
    mytree.add_node(2);
    mytree.add_node(3);
    mytree.add_node(4);
    mytree.add_node(5);
    auto root = mytree.getRoot();
    int head = 0 ;
    auto h = diameter_of_binary_tree(root,&head);
    std::cout << "Diameter = " << h << std::endl;
    return 0;
}
