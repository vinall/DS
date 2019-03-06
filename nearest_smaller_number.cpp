#include <iostream>
#include <stack>
using namespace std;
//1       1       0       2
void
nearest_smaller_number(int arr[],int size) {
	int currMin = arr[0];
	for(int i = 1 ; i < size ; i++) {
		if(arr[i] > arr[i-1]) {
			std::cout << arr[i-1] << "\t";
		} 
		else if(arr[i] < arr[i-1] && arr[i]>currMin) 
			std::cout << currMin << "\t";
		else if(arr[i] < currMin)
			continue;
		if(arr[i-1] < currMin)
			currMin = arr[i-1];
	}
	std::cout << std::endl;
}

void
printPrevSmaller(int arr[],int n) {
	stack<int> s;
	for(int i = 0 ; i < n ; i++) {
		while(!s.empty() && s.top()>=arr[i])
			s.pop();
		if(s.empty())
			std::cout << "_, "; 
		else
			std::cout << s.top() <<	", ";
		s.push(arr[i]);
	}
	std::cout << std::endl;
}

int
main() {
	int arr[] = {1,6,4,10,2,5};
	int arr1[] = {1,3,0,2,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	nearest_smaller_number(arr,size);
	nearest_smaller_number(arr1,size1);
	printPrevSmaller(arr,size);
	printPrevSmaller(arr1,size1);
	return 0;
}
