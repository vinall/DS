#include <iostream>

void display(int arr[],int start,int end) {
    for(int i = start ; i < end ; i++) {
        std::cout << arr[i] << "->\t";
    }
    std::cout << std::endl;
}
int merge(int arr[],int temp[],int start,int mid,int end) {
    int i = start,j = mid;
    int inv_count = 0;
    int k = start;
    while((i <= mid-1 ) && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            display(arr,i,mid);

            inv_count = inv_count + (mid-i);
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid-1) {
        temp[k++] = arr[i++];
    }
    while(j <= end) {
        temp[k++] = arr[j++];
    }
    for(i = start; i <= end; i++)
        arr[i] = temp[i];
    return inv_count;
}

int mergesort(int arr[],int temp[],int start,int end) {
    int inv_count = 0;
    if(start<end) {
        int mid = start + (end-start)/2;
        inv_count = mergesort(arr,temp,start,mid);
        inv_count += mergesort(arr,temp,mid+1,end);

        inv_count += merge(arr,temp,start,mid + 1,end);
    }
    return inv_count;
    
}

int
count_inversion(int arr[],int size) {
    int *temp = new int[size];
    return mergesort(arr,temp,0,size-1);
}


int
main() {
    int arr[]={ 1, 20, 6, 4, 5 }; 
    int size = sizeof(arr)/sizeof(arr[0]);
    int res = count_inversion(arr,size);
    for(int i = 0 ; i < size ; i++) {
        std::cout << arr[i] << "->\t";
    }
    std::cout << "Result = " << res <<  std::endl;
    return 0;
}

