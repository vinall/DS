//fixed point in array is a point where
//index == value stored at that index
#include <iostream>
using namespace std;

int
find_fixed_point(int arr[],int start,int end) {
	if(start>end)
		return 0;
	int mid = start + (end-start)/2;

	if(mid == arr[mid])
		return mid;
	if(mid < arr[mid])
		return find_fixed_point(arr,start,mid-1);
	else
		return find_fixed_point(arr,mid+1,end);
}

int
main() {
	int arr[] = {-10,-5,0,3,7};
	int res = find_fixed_point(arr,0,4);
	std::cout << res << std::endl;
	return 0;
}
