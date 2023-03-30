#include <iostream>
#include <string>

using namespace std;

int N;
char map[70][70];

string recur(int r_s,int c_s,int length);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> map[i][j];
		}
	}
	
	string ans = recur(0,0,N);
	
	cout << ans << '\n';
	
	return 0;
}

string recur(int r_s,int c_s,int length){
	bool one_color = true;
	for(int i = r_s ; i < r_s + length ; i++){
		for(int j = c_s ; j < c_s + length ; j++){
			if(map[r_s][c_s] != map[i][j]){
				one_color = false;
				break;
			}
		}
		if(!one_color)	break;
	}
	 //str.push_back(c)
	int half_l = length/2;
	string ans = "";
	if(one_color){
		ans.push_back(map[r_s][c_s]);
	}
	else{
		ans = "("+recur(r_s,c_s,half_l) +recur(r_s,c_s+half_l,half_l)+ recur(r_s+half_l,c_s,half_l)+recur(r_s+half_l,c_s+half_l,half_l)+")";
	}
	
	return ans;
}