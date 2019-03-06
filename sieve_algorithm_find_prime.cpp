#include <iostream>
using namespace std;

void
find_primes(int number,int res[]) {
	//bool res[number+1] ;
	for(int i = 1 ; i < number ; i++)
		res[i] = true;

	for(int i = 2 ; i <= number ; i++) {
		if(res[i]) {
			for(int j = i*i; j <= number ; j+=i) {
				res[j] = false;
			}
		}
	}
	for(int i = 1 ; i < number ; i++) {
		if(res[i]) {
			std::cout << i << "\t";
		}
	}
	std::cout << std::endl;
}

int
main() {
	int number = 30;
	int res[number+1];
	find_primes(number,res);
	for(int i = 1 ; i <= number; i++)
	{
		if(res[i] && res[number-i]) {
			std::cout << i << " " << number-i << " " << number << std::endl;
			break;
		}
	}
	return 0;
}
