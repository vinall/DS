#include <iostream>
using namespace std;

int
floorSqrt(int x) {
	if(x == 0 || x == 1) {
		return x;
	}
	int i = 1,result = 1;
	while(result <= x) {
		i++;
		result = i*i;
	}
	return i-1;
}

int
main() {
	cout << floorSqrt(11) << std::endl;
	cout << floorSqrt(4) << std::endl;
	cout << floorSqrt(9) << std::endl;
	return 0;
}
