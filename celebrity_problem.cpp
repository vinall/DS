#include <iostream>

/**
 *if x doesn't know y , y cannot be celebrity
 *if x knows y, x cannot be celebrity
 */

bool
knows(int i , int j, bool b[][4]) {
	return b[i][j];
}

int
celebrity( bool b[][4], int num_of_celeb ) {
	int x = 0 ; 
	int y = num_of_celeb - 1 ;
	while ( x < y ) {
		if ( b[x][y] == true ) {
			x++;
		} else {
			y--;
		}
	}

	for ( int i = 0 ; i < 4 ; i++) {
		if( (i != x) && ( !knows(i,x,b) || knows(x,i,b)) )
			return false;
	}
	return x;
}

int
main() {
	bool b[4][4] = { { false, false, true, false },
			 { false, false, true, false },
			 { false, false, false, false },
			 { false, false, true, false } };
	int x = celebrity(b,4);
	std::cout << "Celebrity ID = " << x << std::endl;
	return 0;
}
