#include <iostream>
#define mod 1000000007

using namespace std;

int dp[101];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	
	cin >> C;
	
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3 ; i < 101 ; i++){
		dp[i] = (dp[i-1] + dp[i-2])%mod;
	}
	
	for(int c = 0 ; c < C ; c++){
		int N;
		cin >> N;
		cout << dp[N] << endl;
	}
	return 0;
}