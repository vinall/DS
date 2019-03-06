#include <iostream>
using namespace std;

int
find_max(int arr[],int start,int end){
	if(start>end){
		return -1;
	}
	int mid = start +  (end-start)/2;

	if(mid > start && arr[mid] < arr[mid-1]) {
		std::cout << arr[mid] << " " << arr[mid-1] << " " << mid << std::endl;
		return mid;
	}
	if(mid < end && arr[mid] > arr[mid+1]) {
		std::cout << arr[mid] << " " << arr[mid-1] << " " << mid << std::endl;
		return mid+1;
	}
	if(arr[start] > arr[end]) {
		int l = find_max(arr,start,mid-1);
		int r = find_max(arr,mid+1,end);
		return l == -1 ?  r : l;
	}
}

int
find_max_rev(int arr[],int start,int end){
	if(start>end) {
		return -1;
	}
	int mid = start +  (end-start)/2;

	//{4,3, 2, 1, 5};
	if(mid > start && arr[mid] > arr[mid-1]) {
		std::cout  <<"first "<< arr[mid] << " " << arr[mid-1] << " " << mid << std::endl;
		return mid;
	}
	if(mid < end && arr[mid] < arr[mid+1]) {
		std::cout << "second "<< arr[mid] << " " << arr[mid+1] << " " << mid << std::endl;
		return mid+1;
	}
	if(arr[start] < arr[end]) {
		int l = find_max_rev(arr,start,mid-1);
		int r = find_max_rev(arr,mid+1,end);
		return l == -1 ?  r : l;
	}
}

int
max_find(int arr[],int start,int end) {
	int result = 0;
	if(start>end) 
		return -1;
	if(arr[start] < arr[end]){
		result = find_max_rev(arr,start,end);
	}
	else{
		std::cout << "here\n";
		result = find_max(arr,start,end);
	}
	return result;
}

int
main() {
	//int arr[] = {2,3,4,5,1};
	int arr[] = {4,3, 2, 1, 5};
	int size = sizeof(arr)/sizeof(arr[0]);
	std::cout << max_find(arr,0,size-1) << std::endl;
	return 0;
}
