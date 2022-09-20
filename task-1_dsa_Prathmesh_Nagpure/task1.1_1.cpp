/*

TASK – 1.1

1. Write algorithm for
a. Infix expression to prefix.

Infix expression to prefix

1. Push “)” onto STACK, and add “(“ to end of the A
2. Scan A from right to left and repeat step 3 to 6 for each element of A until the STACK is empty
3. If an operand is encountered add it to B
4. If a right parenthesis is encountered push it onto STACK
5. If an operator is encountered then:
	 a. Repeatedly pop from STACK and add to B each operator (on the top of STACK) which has same 
        or higher precedence than the operator.
     b. Add operator to STACK
6. If left parenthesis is encontered then
	 a. Repeatedly pop from the STACK and add to B (each operator on top of stack until a left parenthesis is encounterd)
	 b. Remove the left parenthesis
7. Exit


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


b. Infix expression to postfix.

Infix expression to postfix.


1.	Scan the Infix string from left to right.
2.	Initialize an empty stack.
3.	If the scanned character is an operand, add it to the Postfix string.
4.	If the scanned character is an operator and if the stack is empty push the character to stack.
5.	If the scanned character is an Operator and the stack is not empty, compare the precedence of the character with the element on top of the stack.
6.	If top Stack has higher precedence over the scanned character pop the stack else push the scanned character to stack. Repeat this step until the stack is not empty and top Stack has precedence over the character.
7.	Repeat 4 and 5 steps till all the characters are scanned.
8.	After all characters are scanned, we have to add any character that the stack may have to the Postfix string.
9.	If stack is not empty add top Stack to Postfix string and Pop the stack.
10.	Repeat this step as long as stack is not empty.


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

c. Write code for balance bracket.

Write code for balance bracket.

Algorithm/Steps:
1.  Whenever we get the opening bracket we will push it into the stack. I.e ‘{‘, ’[’, ’(‘.
2.  Whenever we get the closing bracket we will check if the stack is non-empty or not.
3.  If the stack is empty we will return false, else if it is nonempty then we will check if the topmost element of the stack is the opposite pair of the closing bracket or not.
4.  If it is not the opposite pair of the closing bracket then return false, else move ahead.
5.  After we move out of the string the stack has to be empty if it is non-empty then return it as invalid else it is a valid string.


*/

#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
        stack<char>st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
    }
int main()
{
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}

