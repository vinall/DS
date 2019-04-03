#include <iostream>
#include <stack>

using namespace std;

/**
 *30
 *-5
 *
 */


void
stackSort(stack<int> &s,stack<int> &sortedStack) {
	if(s.empty())
		return;
	if (sortedStack.empty()) {
		sortedStack.push(s.top());
		s.pop();
	}
	if(sortedStack.top() > s.top()) {
		auto i = s.top();
		auto j = sortedStack.top();
		s.pop();
		sortedStack.pop();
		sortedStack.push(i);
		s.push(j);
	} else {
		auto i = s.top();
		s.pop();
		sortedStack.push(i);
	}
	stackSort(s,sortedStack);
}

void
display(stack<int> s) {
	while(s.empty() == false) {
		std::cout << s.top() << "->\t";
		s.pop();
	}
	std::cout << std::endl;
}

int
main() {
	std::stack<int> s;
	std::stack<int> sortedStack;
	s.push(-3);
	s.push(14);
	s.push(18);
	s.push(-5);
	s.push(30);
	stackSort(s, sortedStack);
	display(sortedStack);
	return 0;
}
