#include <iostream>
#include <algorithm>
#define max 98765432

using namespace std;

int val[1010][3];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,r,g,b;
	
	scanf("%d",&N);
	
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d %d",&r,&g,&b);
		val[i][0] = r;
		val[i][1] = g;
		val[i][2] = b;
	}
	
	int ans = max;
	for(int i = 0 ; i < 3 ; i++){
		int dp[1010][3];//R G B
		for(int j = 0 ; j < 3 ; j++){
			if(i == j)	dp[0][i] = val[0][i];
			else dp[0][j] = max;
		}
		//cout << i << endl << dp[0][0] << ' ' << dp[0][1] << ' ' << dp[0][2] << endl;
		for(int j = 1 ; j < N ; j++){
			dp[j][0] = min(dp[j-1][1],dp[j-1][2]) + val[j][0];
			dp[j][1] = min(dp[j-1][0],dp[j-1][2]) + val[j][1];
			dp[j][2] = min(dp[j-1][1],dp[j-1][0]) + val[j][2];
			//cout << dp[j][0] << ' ' << dp[j][1] << ' ' << dp[j][2] << endl;
		}
		//cout << ans << endl;
		for(int j = 0 ; j < 3 ; j++){
			if(i == j) continue;
			ans = min(ans,dp[N-1][j]);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
/*
마지막이랑 처음 거 총 가능한 가짓수가 6가지. 이 6가지 경우에서 모든 경우의 수가 나오므로 6개만 확인해보면될듯
*/