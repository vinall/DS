#include <iostream>
using namespace std;

void
reverseKPosition(int arr[],int size,int k) {
	for(int i = 0 , j = k-1 ; i < j ; i++, j--) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	for(int i = 0 ; i < size ; i++) {
		std::cout << arr[i] << "->\t";
	}
	std::cout << std::endl;
}

int
main() {
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	reverseKPosition(arr,size,4);
	return 0;
}
