//"Algorithm" Search if the top of the stack is the opening bracket of the same nature. If this holds then pop the stack and continue the iteration , in the end if the stack is empty, it means all brackets are well-formed and return  Balanced , else return Not Balanced.
// CPP program to check for balanced brackets.
#include <bits/stdc++.h>
using namespace std;

// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
	// Declare a stack to hold the previous brackets.
	stack<char> temp;
	for (int i = 0; i < expr.length(); i++) {
		if (temp.empty()) {
			// if the stack is empty just push the current
			// bracket
			temp.push(expr[i]);
		}
		else if ((temp.top() == '(' && expr[i] == ')')
				|| (temp.top() == '{' && expr[i] == '}')
				|| (temp.top() == '[' && expr[i] == ']')) {
			// if we found any complete pair of bracket then
			// pop
			temp.pop();
		}
		else {
			temp.push(expr[i]);
		}
	}
	if (temp.empty()) {
		// if stack is empty return true
		return true;
	}
	return false;
}

// Driver code
int main()
{
	string expr = "{()}[]";

	// Function call
	if (areBracketsBalanced(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}
