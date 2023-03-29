//메모해서 정리해보기
#include <iostream>
#include <cstring>
#include <cstdlib>
#define mod 10000000

using namespace std;

int dp[101][101];
int recursive(int n,int b_c);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	for(int c = 0 ; c < C ; c++){
		int N;
		cin >> N;
		memset(dp,-1,sizeof(dp));
		int ans = 0;
		for(int i = 1 ; i <= N ; i++){
			ans += recursive(N-i,i);
			ans %= mod;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}

int recursive(int n,int b_c){
	if(dp[n][b_c] != -1)	return dp[n][b_c];
	if(n==0){
		dp[n][b_c] = 1;
		return dp[n][b_c];
	}	
	if(n==1){
		dp[n][b_c] = b_c;
		return dp[n][b_c];
	}
	
	int ret = 0;
	for(int i = 1 ; i <= n ; i++){
		ret += ((b_c+i-1) * recursive(n-i,i));
		ret %= mod;
	}
	dp[n][b_c] = ret;
	return dp[n][b_c];
}
