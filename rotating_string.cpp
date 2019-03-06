#include <iostream>
#include <string>
using namespace std;

bool
rotate(const string &str,string input) {
	size_t len = str.size();
	size_t len1 = str.size();
	bool flag = false;
	string temp = str+str;
	for(int i = 0; i < len ; i++) {
		flag = true;
		for(int j = 0,k=i; j < len1 ; j++,k++) {
			if(temp[k] != input[j]) {
				flag = false;
				break;
			}
		}
		if(flag)
			break;
	}
	return flag;
}

bool
rotate_by_2(const string &str,string input) {
	if(str.size() != input.size())
		return false;
	int len = str.size();
	for(int i = 2,j=0 ; j < len ;i++,j++) {
		if(str[(i+len)%len] != input[j])
			return false;
	}
	return true;
}

int
main() {
	std::string string1{"amazon"};
	std::string string2{"azonam"};
	std::cout << (rotate(string1,string2) ? "found" : "not found") << "\n";
	std::cout << (rotate_by_2(string1,string2) ? "found" : "not found") << "\n";
	return 0;
}
