#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N,M,v_size;
bool check[10001];

vector <int> v;

void backtracking(int pos,int ind,string ans){
	if(pos == M){
		cout << ans << '\n';
		return;
	}
	else{
		string str;
		for(int i = ind ; i < v_size ; i++){
			str = to_string(v[i]);
			backtracking(pos+1,i,ans + str + ' ');
		}
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	
	int t;
	for(int i = 0 ; i < N ; i++){
		cin >> t;
		if(!check[t]){
			check[t] = true;
			v.push_back(t);
		}
	}
	
	sort(v.begin(),v.end());
	
	v_size = v.size();
	
	for(int i = 0 ; i < v_size ; i++){
		string str = to_string(v[i]);
		backtracking(1,i,str+' ');
	}
	
	return 0;
}