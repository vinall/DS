#include <iostream>
#include <memory>
struct node{
	int data;
	std::shared_ptr<node> next;
};

class mylist { 
	public:
		mylist(){}
		void add_node(int number) {
			auto new_node = create_node(number);
			if(head == nullptr) {
				head = new_node;
			}	
			else {
				new_node->next = head;
				head = new_node;
			}
		}
		void display() {
			auto temp = head;
			while(temp) {
				std::cout << temp->data << "->\t";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
		const std::shared_ptr<const node> getHead() {
			return head;
		}
	private:
		std::shared_ptr<node> create_node(int number) {
			auto newNode = std::make_shared<node>();
			newNode->data = number;
			newNode->next = nullptr;
			return newNode;
		}
		std::shared_ptr<node> head;
};
