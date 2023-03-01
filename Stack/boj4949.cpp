#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	stack<char> st;
	string input;
	while(true){
		getline(cin,input);
		
		if(input[0] == '.')	break;
		
		bool is_balanced_string = true;
		for(int i = 0 ; i < input.size() ; i++){
			switch(input[i]){
				case '[':
					st.push(input[i]);
					break;
				case ']':
					if(!st.empty() && st.top() == '['){
						st.pop();
					}
					else{
						is_balanced_string = false;
					}
					break;
				case '(':
					st.push(input[i]);
					break;
				case ')':
					if(!st.empty() && st.top() == '('){
						st.pop();
					}
					else{
						is_balanced_string = false;
					}
					break;
				default:
					break;
			}
			
			if(!is_balanced_string)	break;
		}
		
		if(is_balanced_string && st.empty()){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
		
		while(!st.empty()){
			st.pop();
		}
	}
	
	return 0;
}