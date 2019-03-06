#include <iostream>
#include <unordered_set>
using namespace std;

bool
pair_product(int arr[],int num,int size) {
	unordered_set<int> _set;
	for(int i = 0 ; i < size ; i++) {
		_set.insert(arr[i]);
	}
	int temp,mod;
	for(int i = 0 ; i < size ; i++) {
		temp = num/arr[i];
		mod = num%arr[i];
		if(mod == 0 && _set.find(temp) != _set.end()) {
			cout << "pair_product " << temp << " * " << arr[i] << "\n";
			return true;
		}	
	}
	return false;
}

int
main() {
	int arr[]={10,20,9,40};
	int size = sizeof(arr)/sizeof(arr[0]);
	pair_product(arr,400,size);
	pair_product(arr,190,size);
	int arr1[]={-10,20,9,-40};
	pair_product(arr1,400,size);
	int arr2[]={-10,20,9,40};
	pair_product(arr2,-400,size);
	return 0;
}
