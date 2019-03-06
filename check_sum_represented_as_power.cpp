#include <iostream>
#include <cmath>
using namespace std;

bool
check_number(int number) {
	int p;
	for(int i = 2 ; i <= sqrt(number) ; i++)
	{
		p = i;
		while(p<=number) {
			p=p*i;
			if(p == number)
				return true;
		}
	}
	return false;
}

int 
main() {
	int number = 9;
	if(check_number(number))
		std::cout << number << " is written as required\n";
	return 0;
}
