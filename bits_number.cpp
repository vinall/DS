#include <iostream>

using namespace std;

void print_binary(unsigned int number){
	char ch;
	while(number) {
		std::cout << (number&1);
		number = number >> 1;
	}
	std::cout << std::endl;
}

int
main() {
	unsigned int n = 7;
	print_binary((~7));
	return 0;
}
