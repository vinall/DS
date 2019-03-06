#include <iostream>

using namespace std;

int
count_triplets(int arr[],int size,int number){
	int resCnt = 0;
	for(int k = 0 ; k < size ; k++) {
		for(int i = k+1 , j = size-1; i < j ; ) {
			if(i == k || j == k){
				i == k ? i++: j--;
				continue;
			}
			if(arr[i] + arr[k] + arr[j] < number) {
				resCnt+=(j-i);
				std::cout << "i= " << i << " k= " << k  << " j= " << j << std::endl;
				std::cout << arr[i] << " " << arr[k] << " "<< arr[j] << std::endl;
				i++;
			}else {
				j--;
			}
		}
	}
	return resCnt;
}

int
main() {
	int arr[] = {1,3,4,5,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int sum = 12;
	std::cout << count_triplets(arr,size,sum) << std::endl;
	return 0;
}
