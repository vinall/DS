#include <iostream>
using namespace std;

int CHAR_LIMIT[256];

void
makeTwoStringSame(char s1[],char s2[],int size1,int size2) {
	int i = 0,j=0;
	for(i = 0 ; i < size2 ; i++) {
		CHAR_LIMIT[s2[i]] = -1;
	}
	for(i = 0 ; i < size1 ;  ) {
		if(CHAR_LIMIT[s1[i]]  == -1) { 
			s1[j] = s1[i]; 
			j++;
			i++;
		} else{
			i++;
		}
	}
	s1[j] = '\0';
	std::cout << s1 << std::endl;
}

void
removeDirtyCharacters(char s1[],char s2[],int size1,int size2) {
	int i = 0,j=0;
	for(i = 0 ; i < size2 ; i++) {
		CHAR_LIMIT[s2[i]] = -1;
	}
	for(i = 0 ; i < size1 ;  ) {
		if(CHAR_LIMIT[s1[i]]  == -1) { 
			i++;
		} else{
			s1[j] = s1[i]; 
			j++;
			i++;
		}
	}
	s1[j] = '\0';
	std::cout << s1 << std::endl;
}

int
main() {
	char s1[] = "bcadeh";
	char s2[] = "hea";
	int size1 = sizeof(s1)/sizeof(s1[0]);
	int size2 = sizeof(s2)/sizeof(s2[0]);
	removeDirtyCharacters(s1,s2,size1-1,size2-1);
	char s11[] = "bcadeh";
	char s22[] = "hea";

	makeTwoStringSame(s11,s22,size1-1,size2-1);
	return 0;
}
