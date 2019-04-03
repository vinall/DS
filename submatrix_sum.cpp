#include <iostream>

using namespace std;

int
query_sum ( int mat[][5] , int tli, int tlj, int rbi, int rbj ) {
	int res = 0 ;
	for ( int i = tli ; i <=  rbi ; i++ ) {
		for ( int j = tlj ; j <= rbj ; j++) {
			res = res + mat[i][j];
		}
	}
	return res;
}

void
preprocess

int
main() {
	int mat[4][5] = {{1, 2, 3, 4, 6},
                         {5, 3, 8, 1, 2},
     	                 {4, 6, 7, 5, 5},
                         {2, 4, 8, 9, 4} };
 
	int tli, tlj, rbi, rbj;

	tli = 0; tlj = 0; rbi = 1; rbj = 1;
	int res = query_sum(mat, tli, tlj, rbi, rbj);
	std::cout << "First Query = " << res << std::endl;

	tli = 2; tlj = 2; rbi = 3; rbj = 4;
	res = query_sum(mat, tli, tlj, rbi, rbj);
	std::cout << "Second Query = " << res << std::endl;

	tli = 1; tlj = 2; rbi = 3; rbj = 3;
	res = query_sum(mat, tli, tlj, rbi, rbj);
	std::cout << "Third Query = " << res << std::endl;

	return 0;
}
