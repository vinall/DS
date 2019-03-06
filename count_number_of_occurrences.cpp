#include <iostream>
using namespace std;

int
left(int arr[],int start,int end,int x) {
	if( start > end )
		return -1;
	int mid = start + (end-start)/2;
	std::cout << mid << " " << arr[mid] << " " << arr[mid+1] << std::endl;
	if(arr[mid] == x && arr[mid-1] != x || arr[mid] != x && arr[mid+1] == x)
		return mid;
	return left(arr,start,mid-1,x);
}

int
right(int arr[],int start,int end,int x) {
	if(start > end)
		return -1;
	int mid = start + (end-start)/2;
	std::cout << mid << " " << arr[mid] << " " << arr[mid+1] << std::endl;
	if(arr[mid]==x && arr[mid+1] != x || (arr[mid]!=x && arr[mid-1] == x ))
		return mid;
	return right(arr,mid+1,end,x);
}

int
count_occurrences(int arr[],int start,int end,int x) {
	int mid = start + (end - start)/2;
	int lft = left(arr,start,mid,x);
	std::cout << "left = " << lft << std::endl;
	std::cout << " -------------- \n";
	int rght = right(arr,mid+1,end,x);
	std::cout << lft << " - " << rght << std::endl;
	return rght - lft;
}

int
main() {
	int arr[] = {1,1,1,1,2,2,3};
	int x = 2;
	int size = sizeof(arr)/sizeof(arr[0]);
	int y = count_occurrences(arr,0,size-1,x);
	std::cout << "# of occurrence of " << x << " = " << y << std::endl; 
	return 0;
}
