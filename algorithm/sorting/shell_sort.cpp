#include <iostream>
using namespace std;

void
display(int arr[],int size) {
        for(int i = 0 ; i < size; i++) {
                std::cout<< arr[i]<< "\t";
        }
        std::cout << std::endl;
}

void
shellsort(int arr[],int size){
	for(int gap = size/2; gap > 0 ; gap /= 2) {
        for(int i = gap ; i < size ; i++ ) {
            int newelement = arr[i];
            int j = i;
            while(j>=gap && arr[j - gap] > newelement) {
                arr[j] = arr[j-gap];
                j-=gap;
            }
            arr[j] = newelement;
        }
	}
}

int
main() {
	int arr[] = {20,35,-15,7,55,1,-22};
	int size = sizeof(arr)/sizeof(arr[0]);
	shellsort(arr,size);
	display(arr,size);
	return 0;
}
