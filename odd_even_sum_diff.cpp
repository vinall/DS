#include <iostream>
#include "binary_tree.h"
#include <queue>

int
odd_even_level_sum_diff(std::shared_ptr<node> tree) {
    std::queue<std::shared_ptr<node>> q;
    q.push(tree);
    int level = 1;
    int sum_even = 0 ;
    int sum_odd = 0 ;
    while(1) {
        int size = q.size();
        
        while(size>0) {
            auto l = q.front();
            q.pop();
            if(level%2 == 1) {
                sum_odd += l->data;
            }
            else {
                sum_even += l->data;
            }
            if(l->left){
                q.push(l->left);
            }
            if(l->right){
                q.push(l->right);
            }
            size--;
        }
        if(q.empty())
            break;
        level++;
    }
    return sum_odd - sum_even;
}

int
main() {
    BinarySearchTree bst;
    bst.add_node(5);
    bst.add_node(2);
    bst.add_node(1);
    bst.add_node(4);
    bst.add_node(3);
    bst.add_node(6);
    bst.add_node(8);
    bst.add_node(7);
    bst.add_node(9);
    auto res = odd_even_level_sum_diff(bst.getRoot());
    std::cout << "Result " << res << std::endl;
    return 0;
}
