#include <iostream>
using namespace std;

void
insertion_sort(int arr[],int size){
	for(int i = 1; i < size; i++) {
		int newelement = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] > newelement) {
			arr[j+1] = arr[j]; 
			j--;
		}
		arr[j+1] = newelement;
	}
}

void 
display(int arr[],int size) {
	for(int i = 0 ; i < size; i++) {
		std::cout<< arr[i]<< "\t";
	}
	std::cout << std::endl;
}

int
main() {
	int arr[] = {20,35,-15,7,55,1,-22};
	int size = sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr,size);
	display(arr,size);
	return 0;
}
