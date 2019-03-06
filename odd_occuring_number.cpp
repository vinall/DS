#include <iostream>
using namespace std;

int
odd_occuring_number(int arr[],int size) {
	int res = 0;
	for(int i = 0 ; i < size ; i++) {
		res = res^arr[i];
	}
	return res;
}

int
main() {
	int arr[] = {1,2,3,2,3,1,3,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int res = odd_occuring_number(arr,size);
	std::cout << "Result = " << res << std::endl;
	return 0;
}
