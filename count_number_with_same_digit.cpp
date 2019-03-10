#include <iostream>
int
count_with_same_digit(int start,int end) {
    int temp = start;
    int maxtens = 1 ;
    int count=0;
    while(temp>=10) {
        temp/=10;
        maxtens*=10;
    }
    std::cout << maxtens << std::endl;
    while(start < 10 ){
        std::cout << start << "->\t";
        start++;
        count++;
    }

    for(int j = maxtens ; j < end ; j*=10) {
        for(int i = 1; i < 9  ; i++) {
            int res = i*j+i;
            std::cout << res << "->\t";
            if(res > end){
                std::cout << count << std::endl;
                return count;
            }
            count++;
        }
    }
    std::cout << std::endl;
    return count;
}

int
main() {
    std::cout << count_with_same_digit(101,201) << std::endl;
    return 0;
}
