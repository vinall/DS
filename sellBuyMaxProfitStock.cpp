#include <iostream>
#include <climits>

using namespace std;

struct solution {
	int sellIdx;
	int buyIdx;
};

void
max_profit (int arr[], int days) {
	int min = INT_MAX, max = INT_MIN;
	int maxIdx = 0;
	int count = 0;
	solution sol[days];
	for(int i = 0 ; i < days - 1 ; i++) {
		while( (i < days - 1) && arr[i+1] <= arr[i])
			i++;
		if(i == days-1)
			break;
		sol[count].buyIdx = i++;
		while( (i < days - 1) && arr[i+1]>=arr[i])
			i++;
		sol[count].sellIdx = i;
		count++;
	}

	for(int i = 0 ; i < count ; i++) {
		std::cout << sol[i].buyIdx << " " << sol[i].sellIdx << std::endl;
	}
}

int
main() {
	int stock_price[] = {100, 180, 260, 10, 40, 535, 695};
	max_profit(stock_price,7);
	return 0;
}
