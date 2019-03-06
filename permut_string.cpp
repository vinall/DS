#include <iostream>

void
swap(char arr[],int start,int end) {
	auto temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
}

void
permute_string(char arr[],int start,int end) {
	if(start==end) {
		std::cout << arr << std::endl;
		return;
	}
	else {
		for(int i = start;i <= end; i++) {
			swap(arr,i,end);
			permute_string(arr,start+1,end);
			swap(arr,i,end);
		}
	}
}

int
main() {
	char arr[] = "abc";
	permute_string(arr,0,2);
	return 0;
}
