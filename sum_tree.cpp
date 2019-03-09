#include <iostream>
#include "binary_tree.h"

using tree = std::shared_ptr<node>;

int
sumtree(tree root) {
    if(root == nullptr)
        return 0;
    auto temp = root->data;
    if(root->left == nullptr && root->right == nullptr) {
        root->data = 0;
    }
    root->data = sumtree(root->left) + sumtree(root->right);
    return temp+root->data;
}

int
main() {
    BinarySearchTree mytree;
    mytree.add_node(10);
    mytree.add_node(-2);
    mytree.add_node(8);
    mytree.add_node(-4);
    mytree.add_node(16);
    mytree.add_node(15);
    mytree.display();
    auto root = mytree.getRoot();
    int val = sumtree(root);
    mytree.display();
    return 0;
}
