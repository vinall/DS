#include <iostream>
#include <climits>

using namespace std;

void swap ( int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int start, int end) {
	int pivot = arr[end];
	int j = start-1;
	for (int i = start; i <= end - 1; i++ ) {
		if ( arr[i] <= pivot) {
			j++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[end],arr[j+1]);
	return j+1;

}

void quick_sort(int arr[], int start, int end) {
	if ( start < end ) { 
		auto q = partition(arr, start, end);
		quick_sort(arr, start, q - 1);
		quick_sort(arr, q + 1, end);
	}
}

void
closest_to_zero(int arr[], int size) {
	quick_sort(arr,0,size-1);
	int res = 0;
	int min = INT_MAX;
	int i = 0 , j = size-1;
	while( i != j) {
		res = arr[i] + arr[j];
		if ( abs(res) < min ) {
			min = abs(res);
		} 
	       	if ( res > 0 ) {
			j--;
		} else if ( res < 0 ) {
			i++;
		}
	}
	std::cout << "Closest sum to zero =  " << min << std::endl;
}

void
display(int arr[], int size) {
	for (int i = 0 ; i < size ; i++) {
		std::cout << arr[i] << "->\t";
	}
	std::cout << std::endl;
}

int 
main() {
	int arr[] = { 9 , 8 , -2, 1, 4};
	//-2, 1 , 4 , 8, 9
	int size = sizeof(arr)/sizeof(arr[0]);
	closest_to_zero(arr,size);
	return 0;
}
