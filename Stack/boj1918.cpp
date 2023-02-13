/*
A+B*C-D/E

ABCDE/-*+

ABC*+DE/-
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;
string input_str;

int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios::sync_with_stdio(false);
	
	cin >> input_str;
	
	for(int i = 0 ; i < input_str.size() ; i++){
		if(input_str[i] >= 'A' && input_str[i] <= 'Z'){
			cout << input_str[i];
		}
		else if(input_str[i] == '(' || st.empty()){
			st.push(input_str[i]);
		}
		else if(input_str[i] == '+' || input_str[i] == '-'){
			while(!st.empty() && st.top() != '('){
				cout << st.top();
				st.pop();
			}
			st.push(input_str[i]);
		}
		else if(input_str[i] == '/' || input_str[i] == '*'){
			while(!st.empty() && (st.top() == '/' || st.top() == '*')){
				cout << st.top();
				st.pop();
			}
			st.push(input_str[i]);
		}
		else{//input_str[i] == ')'
			while(!st.empty() && st.top() != '('){
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
	}
	
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
	
	cout << '\n';
	
	return 0;
}