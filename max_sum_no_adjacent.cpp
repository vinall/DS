#include <iostream>

using namespace std;

int
max_sum_with_constraints(int arr[],int size) {
	int res_odd = 0,res_even = 0;
	
	auto check = [](int arr[],int init,int size){
		int res = 0;
		for(int i = init ; i < size ; i+=2) {
			res+=arr[i];
		}
		return res;
	};
	res_even = check(arr,0, size);
	res_odd = check(arr,1,size);
	return res_even > res_odd ? res_even : res_odd;
	/*for(int i = 1 ; i < size ; i+=2) {
		res_even+=arr[i];
	}*/
}

int
main() {
	//int arr[] = { 5,5,10,100,10,5};
	//int arr[] = {1,20,3};
	int arr[] = {5,  5, 10, 40, 50, 35};
	int size = sizeof(arr)/sizeof(arr[0]);
	std::cout << max_sum_with_constraints(arr,size) << "\n"; 
	return 0;
}
