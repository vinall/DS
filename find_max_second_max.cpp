#include <iostream>
#include <limits>
using namespace std;

void
findMaxSecondMax(int arr[],int size) {
	int max = std::numeric_limits<int>::min();
        int secMax = std::numeric_limits<int>::min();
	
	int neg_max = std::numeric_limits<int>::max();
	int secNegMax = std::numeric_limits<int>::max();
	for(int i = 0 ; i <= size ; i++) {
		if(arr[i] > max) {
			secMax = max;
			max = arr[i];
		}else if(secMax < arr[i]) {
			secMax = arr[i];
		}
		if(arr[i] < 0 && arr[i] < neg_max) {
			secNegMax = neg_max;
			neg_max = arr[i];
		} else if(arr[i] < 0 && secNegMax > arr[i]) {
			secNegMax = arr[i];
		}

	}
	std::cout << "Max = " << max << " secMax = " << secMax << std::endl;
	std::cout << "NegMax = " << neg_max << " secNegMax = " << secNegMax << std::endl;
}

int
main() {
	int arr[] = { 3,-4,1,-3,1,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	findMaxSecondMax(arr,size-1);
	return 0;
}
