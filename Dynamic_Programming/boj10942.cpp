#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[2001][2001];
int N,M;
vector<int> v;

int Solve(int S,int E);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&N);
	
	v.push_back(0);
	int t;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&t);
		v.push_back(t);
	}
	
	scanf("%d",&M);
	memset(&dp[0][0],-1,sizeof(dp));
	int s,e;
	for(int i = 0 ; i < M ; i++){
		scanf("%d %d",&s,&e);
		int ans = Solve(s,e);
		printf("%d\n",ans);
	}
	
	return 0;
}

int Solve(int S,int E){
	if(dp[S][E] != -1)	return dp[S][E];
	
	if(E-S == 1){
		dp[S][E] = (v[S] == v[E] ? 1 : 0);
		return dp[S][E];
		//이 파트를 이렇게 나눠서 쓰는 것이 시간이 훨신 적게 걸림.
	}
	if(S == E){
		dp[S][E] = 1;
		return dp[S][E];
	}
	
	if(v[S] != v[E]){
		dp[S][E] = 0;
		return dp[S][E];
	}
	
	dp[S][E] = Solve(S+1,E-1);
	return dp[S][E];
	// 이 파트도 동일함
}