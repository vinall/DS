#include <iostream>
#include "linked_list.h"
using namespace std;

//1 2 3 4 5 6 7 8
void
delete_n_after_m(std::shared_ptr< node> head,int num) {
    if(head == nullptr)
        return;
    int i = 0;
    while(i<num-1 && head!=nullptr) {
        head = head->next;
        i++;
    }
    auto temp = head;
    head = head->next;
    i = 0; 
    while( i < num && head != nullptr ) {
        auto t = head;
        head = head->next;
        t->next = nullptr;
        i++;
    }
    temp->next = head;
    delete_n_after_m(head,num);
}

void
display(std::shared_ptr<node> head) {
    while(head!=nullptr) {
        std::cout << head->data << "->\t";
        head = head->next;
    }
    std::cout << std::endl;
}

int
main() {
    mylist l;
    for(int i = 8 ; i > 0 ; i--) {
        l.add_node(i);
    }
    auto head = l.getHead();
    delete_n_after_m(head,2);
    display(head);
    return 0;
}
