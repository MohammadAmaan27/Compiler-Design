#include <iostream>
#include <stack>
using namespace std;

int getPrecendence(char c) {
	if(c == '^')
	    return 3;
	else if(c == '/' || c == '*')
		return 2;
	else if(c == '+' || c == '-')
	    return 1;
	else
	    return -1;
}

void InfixToPostfix(string s) {
	stack<char> st;
	string result;
	for(int i = 0; i<s.length(); i++) {
		char c = s[i];
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		    result += c;
		
		else if(c == '(')
		    st.push('(');
		
		else if(c == ')') {
			while(st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while(!st.empty() && getPrecendence(s[i]) <= getPrecendence(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
    }
    
    while(!st.empty()) {
    	result += st.top();
    	st.pop();
	}
	cout<<"\nPostfix expression: \n";
	cout<< result << endl;
}

int main() {
	cout<<"Enter the infix expression\n";
	string infix = "";
	cin>>infix;
	InfixToPostfix(infix);
	return 0;
}



















