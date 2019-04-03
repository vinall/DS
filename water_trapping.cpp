#include <iostream>

using namespace std;
/*
 * Logic came out to be very simple.
 * Two variable storing max_left and max_right height of tower.
 * max_left and max_right will be updated if the current tower is of the max height. No water can be stored here.
 * For each tower total water stored can be min(max_left,max_right)-h(tower)
 * */

int
total_water_trapped(int h[],int number_of_towers) {
	int max_left = 0 , max_right = 0 ;
	int l = 0 , r = number_of_towers-1;
	int ans = 0;
	while ( l < r) {
		if ( h[l] < h[r] )
		{	
			if ( h[l] > max_left) {
				max_left = h[l];
			}
			else {
				ans = ans + max_left - h[l];
				std::cout << max_left << " " << max_right << " " << h[l] << " " << h[r] << std::endl;
			}
			l++;
		} else {
			if ( h[r] > max_right ) {
				max_right = h[r];
			} 
			else {
				ans = ans + max_right - h[r];
			}
			r--;
		}
	}
	return ans;
}

int main() {
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int number_of_towers = sizeof(arr)/sizeof(arr[0]);
	int total_water_stored = total_water_trapped(arr, number_of_towers);
	std::cout << total_water_stored << " litres of water is trapped\n";
	return 0;
}
