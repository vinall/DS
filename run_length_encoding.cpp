#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iterator>
using namespace std;

void
runLengthEncoding(std::string &str,int size) { 
	std::unordered_map<char,int> charcount;
	std::stringstream ss;
	for(int i = 0 ; i < size ; i++) {
		charcount[str[i]]++;
	}
	int idx = 0;
	for(auto itr = std::rbegin(charcount) ; itr != std::rend(charcount) ; ++itr){
		ss << itr->first << itr->second;
	}
	std::cout << ss.str() << std::endl;
}

int
main() {
	std::string str = "wwwwaaadexxxxxx";
	int size  = str.size();
	runLengthEncoding(str,size);
	for(int i = 0 ; i < size ; i++ ) {
		std::cout << str[i] << "->\t";
	}
	std::cout << std::endl;
	return 0;
}
