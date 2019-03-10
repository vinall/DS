#include <iostream>

using namespace std;

void
display(int arr[],int size){
    for(int i = 0 ; i <= size ; i++) {
        std::cout << arr[i] << "->\t";
    }
    std::cout << std::endl;
}


void
swap(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int
partition(int arr[],int start,int end) {
    int pivot = arr[end];
    int i = start-1;
    for(int j = start; j <= end-1;j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[end],arr[i+1]);
    return i+1;
}

int
quick_sort(int arr[],int start,int end) {
    if(start < end) {
        int q = partition(arr,start,end);
        quick_sort(arr,start,q-1);
        quick_sort(arr,q+1,end);
    }
}

void
merge(int arr1[],int arr2[],int size) {

    int i = 0;
    int j = 0;
    int cnt = 0;
    int temp[size] = {0,0,0,0,0,0};
    while( i <= size && j <= size) {
        if(arr1[i] >= arr2[j]) {
            temp[i]++;
            j++;
        } else{
            i++;
        }
    }


    for( i = 1 ; i <= size ; i++) {
        temp[i] += temp[i-1];
    }
    display(temp,size);
}   

int
main() {
    int arr1[] = {1,2,3,4,7,9};
    int arr2[] = {0,1,2,1,1,4};
    quick_sort(arr2,0,5);
    merge(arr1,arr2,5);
    return 0;
}
