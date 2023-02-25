#include <iostream>
#include <string>

using namespace std;

bool is_end_num(int n);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,num=665;
	
	cin >> N;
	
	while(N != 0){
		num++;
		if(is_end_num(num)){
			N--;
		}
	}
	
	cout << num << endl;
}

bool is_end_num(int n){
	string n_str = to_string(n);
	int c = 0;
	for(int i = 0 ; i < n_str.size()-2 ; i++){
		if(n_str[i] == '6' && n_str[i+1] == '6' && n_str[i+2] == '6'){
			return true;
		}
	}
	
	return false;
}