#include <iostream>
using namespace std;

void
printPatternUtil(char str[],char buff[],int i ,int j,int size) {
	if(i == size) {
		buff[j] = '\0';
		std::cout << buff  << "\n";
		return;
	}
	buff[j] = str[i];
	printPatternUtil(str,buff,i+1,j+1,size);
	buff[j] = ' ';
	buff[j+1] = str[i];
	printPatternUtil(str,buff,i+1,j+2,size);
}

int 
main() {
	char str[]="apple";
	char buff[2*sizeof(str)];
	buff[0] = str[0];
	printPatternUtil(str,buff,1,1,sizeof(str));
	return 0;
}
