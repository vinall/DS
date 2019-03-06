#include <iostream>
using namespace std;
struct point{
	int x;
	int y;
};
bool
two_rectangle_overlap(point p1,point p2,point p3,point p4) {
	if((p2.x < p3.x or p1.x > p4.x) or (p1.y < p4.y or p2.y > p3.y))
		return false;
	return true;
}

int 
main() {
	point p1={0,10},p2={10,0};
	point p3={5,5},p4={15,0};
	bool res = two_rectangle_overlap(p1,p2,p3,p4);
	if(res)
		cout << "Overlap\n";
	else
		cout << "Don't Overlap\n";
	return 0;
}
