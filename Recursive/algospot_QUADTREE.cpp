#include <iostream>
#include <string>

using namespace std;

int now_index = 0;
string input_quad,reverse_quad;

string recursive();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int C;
	cin >> C;
	for(int i = 0 ; i < C ; i++){
		cin >> input_quad;
		now_index = 0;
		reverse_quad = recursive();

		cout << reverse_quad << '\n';
	}
	
	return 0;
}

string recursive(){
	string ret = "";
	if(input_quad[now_index] == 'x'){
		now_index++;
		string first_part = recursive();
		string second_part = recursive();
		string third_part = recursive();
		string forth_part = recursive();
		ret += "x" + third_part + forth_part + first_part + second_part;
		
		return ret;
	}
	
	ret += input_quad[now_index];
	now_index++;
	return ret;
}