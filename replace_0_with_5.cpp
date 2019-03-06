#include <iostream>
#include <cmath>
using namespace std;
int 
replace_0_with_5(int num) {
	int res = 0,t1,t2,i=0;
	while(num) {
		t1 = num%10;
		num = num/10;
		if(t1 == 0)
			t1 = 5;
		res = res + t1*pow(10,i);
		i++;
	}
	std::cout << "Result is = " << res << std::endl;
}

int
main() {
	replace_0_with_5(101);
	return 0;
}
