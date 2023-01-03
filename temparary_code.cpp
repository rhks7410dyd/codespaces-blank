#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int T,N,K;
	long long dp[16][16];
	

	for(int i = 1 ; i < 15 ; i++){
		dp[0][i] = i;
		dp[i][1] = 1;
	}

	
	for(int i = 1 ; i < 15 ; i++){
		for(int j = 2 ; j < 15 ; j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	
	cin >>T;
	
	for(int i = 0 ; i < T ; i++){
		cin >> K >> N;
		cout << dp[K][N] << endl;
	}
	
	return 0;
}