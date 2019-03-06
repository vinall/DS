#include <iostream>
using namespace std;

void
rearrange_positive_negative(int arr[],int size) {
	int pos_idx = 0 , neg_idx = size;
	for(;pos_idx < neg_idx; ) {
		if(arr[pos_idx]>0) {
			while(arr[pos_idx]>0) {
				pos_idx++;
			}
		}
		if(arr[neg_idx]<0) {
			while(arr[neg_idx] < 0) {
				neg_idx--;
			}
		}
		if(pos_idx < neg_idx && arr[pos_idx] < 0 && arr[neg_idx]>0) {
			std::cout << arr[pos_idx] << " " << arr[neg_idx] << std::endl;
			int temp = arr[pos_idx];
			arr[pos_idx] = arr[neg_idx];
			arr[neg_idx] = temp;

			pos_idx++;
			neg_idx--;
		}
	}
}

int
main() {
	int arr[] = {-1,2,-3,1,-2,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0 ; i < size ; i++) {
		std::cout << arr[i] << "->\t"; 
	}
	rearrange_positive_negative(arr,size-1);
	for(int i = 0 ; i < size ; i++) {
		std::cout << arr[i] << "->\t"; 
	}
	std::cout << std::endl;
	return 0;
}
