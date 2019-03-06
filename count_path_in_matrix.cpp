#include <iostream>

using namespace std;

int count = 0;

int
count_matrix_path(int arr[][3],int i,int j,int n,int m) {
	if(i>n)
		return 0;
	if(j>m)
		return 0;
	if(i==n && j==m) {
		
		return 1;
	}

	return count_matrix_path(arr,i+1,j,n,m) + count_matrix_path(arr,i,j+1,n,m);	
}

int
main() {
	int arr[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	int cnt = count_matrix_path(arr,0,0,2,2);
	std::cout <<"Count = " << cnt << std::endl;
	return 0;
}
