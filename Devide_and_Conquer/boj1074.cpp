#include <iostream>

using namespace std;

int N,R,C;

int dp[4][4] ={{0,1,4,5},{2,3,6,7},{8,9,12,13},{10,11,14,15}};
int Find_count(int r_s,int c_s,int l);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> R >> C;
	
	int length = 1;
	for(int i = 0 ; i < N ; i++){
		length *= 2;
	}
	
	int ans = Find_count(0,0,length);
	cout << ans <<'\n';
	
	return 0;
}


int Find_count(int r_s,int c_s,int l){
	if(l <= 1){
		return 0;
	}
	
	int half_l = l/2,ret;
	if(R < r_s + half_l){
		if(C < c_s + half_l){
			ret = Find_count(r_s,c_s,half_l);
		}
		else{
			ret = Find_count(r_s,c_s+half_l,half_l) + half_l*half_l;
		}
	}
	else{
		if(C < c_s + half_l){
			ret = Find_count(r_s+half_l,c_s,half_l) + 2*half_l*half_l;
		}
		else{
			ret = Find_count(r_s+half_l,c_s+half_l,half_l) + 3*half_l*half_l;
		}
	}
	
	return ret;
}