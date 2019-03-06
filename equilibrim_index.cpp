#include <iostream>
using namespace std;

int
find_equilibrim(int arr[],int size) {
	int low_half = 0 , upper_half = 0 , res = 0;
	for(int i = 0 ; i < size ; i++)
		res += arr[i];

	for(int i = 1 ; i < size ; i++) {
		low_half += arr[i-1];
		upper_half = res - arr[i] - low_half;
		if(low_half == upper_half)
			return i;
	}
	return -1;
}

int
main() {
	int arr[] = {-7,1,5,2,-4,3,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	int res = find_equilibrim(arr,size); 
	std::cout << "Index = " << res << " " << arr[res] << std::endl;
	return 0;
}
