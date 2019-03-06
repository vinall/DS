#include <iostream>

using namespace std;

void
heapify(int arr[],int idx,int size) {
	int left = 2*idx+1;
	int right = 2*idx+2;
	int max = idx;
	if(left <= size && arr[left] > arr[idx])
		max = left;
	if(right <= size && arr[right] > arr[max])
		max = right;
	if(max != idx) {
		int temp = arr[max];
		arr[max] = arr[idx];
		arr[idx] = temp;
		heapify(arr,max,size);
	}
}

void
create_heap(int arr[],int size) {
	for(int i = (size/2)-1; i >= 0 ; --i) {
		heapify(arr,i,size);
	}
}

int
getMax(int arr[],int &heapSize) {
	int res = arr[0];
	int temp = arr[heapSize];
	arr[heapSize] = arr[0];
	arr[0] = temp;
	heapify(arr,0,heapSize-1);
	heapSize--;
	return res;
}

int
main() {
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int k = 2;
	int n = sizeof(arr)/sizeof(arr[0]);
	create_heap(arr,n-1);
	int heapSize = n-1;
	for(int i = 0 ; i < k ; i++) {
		std::cout << getMax(arr,heapSize) << "->\t";
	}
	std::cout << std::endl;

	for(int i = n-1 ; i >= 0 ; i--) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heapify(arr,0,i-1);
	}

	for(int i = 0 ; i < n ; i++) {
		std::cout << arr[i] << "->" << "\t";
	}
	std::cout << "\n";

	return 0;
}
