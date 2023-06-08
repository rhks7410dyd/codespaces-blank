/*
1. 맨처음에 반복문으로 하는 곳 없애기
=> 이건 할 수가 없는게 시작점을 9개로 따로 잡아야해서 어쩔 수 없이 반복문으로 시작을 설정해줘야됨
2. 왜 안되는지 찾기
=>dp 조건에 now를 추가했어야했는데 추가를 못함
*/
#include <iostream>
#include <algorithm>
#define MOD 1000000000

using namespace std;

long long dp[1<<11][10][101];

long long Solve(int set,int now,int l);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	long long ans=0;
	
	if(N < 10){
		cout << ans << '\n';
		return 0;
	}
	
	fill(&dp[0][0][0],&dp[1<<11-1][9][101],-1);
	
	for(int i = 1 ; i < 10 ; i++){
		ans += Solve(1<<i,i,N-1);
		ans %= MOD;
	}
	
	cout << ans << '\n';

	return 0;
}

long long Solve(int set,int now,int l){
	if(l == 0){
		if(set == 1023)	return 1;
		return 0;
	}
	
	
	long long& ret = dp[set][now][l];
	if(ret != -1)	return ret;
	ret = 0;
	
	if(now != 0){
		int next_set = set|(1<<now-1);
		ret += Solve(next_set,now-1,l-1);
	}
	ret%=MOD;
	
	if(now != 9){
		int next_set = set|(1<<now+1);
		ret += Solve(next_set,now+1,l-1);
	}
	ret%=MOD;
	
	
	return ret;
}