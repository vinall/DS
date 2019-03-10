#include <iostream>

using namespace std;

int
find_equilibrium_index(int arr[],int size) {
    int totalsum = 0,i=0;
    int leftsum = 0;
    for( ; i < size ; i++) {
        totalsum+=arr[i];
    }
    for(int i = 0 ; i < size ; i++) {
        totalsum=totalsum - arr[i];
        if(leftsum == totalsum)
            return i;
        leftsum += arr[i];
    }
    return -1;
}

int
main() {
    int arr[] = {-7,1,5,2,-4,3,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    auto res = find_equilibrium_index(arr,size);
    std::cout << "Equilibrium result = " << res << std::endl;
    return 0;
}
