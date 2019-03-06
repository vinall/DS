#include <iostream>

using namespace std;
void 
swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int
partition(int arr[],int start,int end) {
	int pivot = arr[end];
	int pivot_id=0;
	int i = start-1;
	for(int j = start ; j <= end;j++) {
		if(arr[j] <= pivot) {
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[end]);
	return i+1;
}

void 
quick_sort(int arr[],int start,int end){
	if(start<end){
		int q = partition(arr,start,end);
		quick_sort(arr,start,q-1);
		quick_sort(arr,q+1,end);
	}
}

int
main() {
	int arr[] = { 1,2,0,1,2,1};
	std::cout << "start ---- \n";
	int size = sizeof(arr)/sizeof(arr[0]);
	partition(arr,0,size-1); // quick_sort(arr,0,size-1);
	for(int i = 0 ; i < size ; i++) {
		std::cout << arr[i] << "->\t";
	}
	std::cout << "\n";

	return 0;
}
