#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> input;

bool is_used[8];
int N,M;

void Recursive_func(int pos, string ans){
	if(pos == M){
		cout << ans << '\n';
		return ;
	}
	else{
		string temp;
		for(int i = 0 ; i < N ; i++){
			if(!is_used[i]){
				temp = to_string(input[i]);
				is_used[i] = true;
				Recursive_func(pos + 1 , ans + temp + ' ');
				is_used[i] = false;
			}
		}
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	int temp;
	for(int i = 0 ; i < N ; i++){
		cin >> temp;
		input.push_back(temp);
	}
	
	sort(input.begin(),input.end());
	
	Recursive_func(0,"");
	
	return 0;
}