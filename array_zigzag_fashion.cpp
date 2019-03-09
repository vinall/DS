#include <iostream>


void
swap(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void
array_zigzag_fashion(int arr[],int size) {
    for(int i = 0 ; i < size ; i += 2) {
        if((arr[i] < arr[i+1]) && (arr[i+1] > arr[i+2])) {
            continue;
        }
        if(arr[i] > arr[i+1])
            swap(arr[i],arr[i+1]);
        if(arr[i+1] < arr[i+2])
            swap(arr[i+1],arr[i+2]);
    }
}

void
display(int arr[],int size) {
    for(int i = 0 ; i <= size ; i++)
        std::cout << arr[i] << "->\t";
    std::cout << std::endl;
}

int
main() {
    int arr[] = {4,3,7,8,6,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << size << std::endl;
    array_zigzag_fashion(arr,size);
    size = sizeof(arr)/sizeof(arr[0]);
    std::cout << size << std::endl;
    display(arr,size-1);
    return 0;
}
