/*
A+B*C-D/E
ABCDE/-*+
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<string> st;
string input_str;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> input_str;
	
	string temp,alpha,beta,delta;
	for(int i = 0 ; i < input_str.size() ; i++){
		temp = "";
		if(input_str[i] != ')'){
			st.push(temp+input_str[i]);
			continue;
		}
		
		beta = st.top();		st.pop();
		delta = st.top();	st.pop();
		alpha = st.top();	st.pop();
		temp = alpha+beta+delta;
		if(st.top() == "(")	st.pop();
		st.push(temp);
	}
	
	while(st.size() > 1){
		beta = st.top();	st.pop();
		delta = st.top();	st.pop();
		alpha = st.top();	st.pop();
		temp = alpha+beta+delta;
		if(st.size() && st.top() == "(")	st.pop();
		st.push(temp);		
	}
	
	string ans = st.top();
	cout << ans << endl;
	
	return 0;
}