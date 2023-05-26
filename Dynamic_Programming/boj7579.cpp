#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int N,M;
int dp[101][10001];
int cost[101];
int mem[101];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int sum = 0;
	cin >> N >> M;
	for(int i = 1 ; i <= N ; i++){
		cin >> mem[i];
	}
	for(int i = 1 ; i <= N ; i++){
		cin >> cost[i];
		sum += cost[i];
	}
	
	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= sum; j++){
			if (j - cost[i] >= 0)	dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	
	for(int i = 0 ; i <= sum ; i++){
		if(dp[N][i] >= M){
			cout << i << '\n';
			break;
		}
	}
	
	return 0;
}
