/*
1. 맨처음에 반복문으로 하는 곳 없애기
2. 왜 안되는지 찾기
*/
#include <iostream>
#include <algorithm>
#define MOD 1000000000

using namespace std;

int dp[1<<11][41];

int Solve(int set,int now,int l);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int ans=0;
	
	if(N < 10){
		cout << ans << '\n';
		return 0;
	}
	
	fill(&dp[0][0],&dp[1<<11-1][41],-1);
	
	for(int i = 1 ; i < 10 ; i++){
		ans += Solve(1<<i,i,N-1);
		ans %= MOD;
	}
	
	cout << ans << '\n';
	
	return 0;
}

int Solve(int set,int now,int l){
	if(l == 0){
		if(set == 1023)	return 1;
		return 0;
	}
	
	int& ret = dp[set][l];
	if(ret != -1)	return ret;
	ret = 0;
	
	if(now != 0)	ret += Solve((set|(1<<(now-1))),now-1,l-1);
	ret%=MOD;
	if(now != 9)	ret += Solve((set|(1<<(now+1))),now+1,l-1);
	ret%=MOD;
	
	return ret;
}