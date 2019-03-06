#include "binary_tree.h"

int
main() {
	BinarySearchTree mytree;
	mytree.add_node(16);
	mytree.add_node(10);
	mytree.add_node(12);
	mytree.add_node(9);
	mytree.add_node(18);
	mytree.display();

	return 0;
}
