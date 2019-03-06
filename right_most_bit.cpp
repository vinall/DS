#include <iostream>
#include <cmath>
using namespace std;

int
rightmost_position(int num) {
	int complement = (~num) + 1;
	return log(num & complement)/log(2);
}

int
main() {
	std::cout << "Right most position of 1 " << rightmost_position(16) << "\n";
	return 0;
}
