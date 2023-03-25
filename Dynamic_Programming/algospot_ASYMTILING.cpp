#include <iostream>
#define mod 1000000007

using namespace std;

unsigned long long dp[101];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	
	cin >> C;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3 ; i < 101 ; i++){
		dp[i] = (dp[i-1] + dp[i-2])%mod;
	}
	
	for(int c = 0 ; c < C ; c++){
		int N;
		cin >> N;
		
		long long ans;//int형으로 하면 짝수일 때 문제가 발생하는듯, long long으로 ans를 바꾸니 정답처리됨
		if(N%2 == 0){
			ans = dp[N] - dp[N/2] - dp[N/2-1];
		}
		else{
			ans = dp[N] - dp[N/2];
		}
		while(ans < 0){
			ans += mod;
		}
		cout << ans << endl;
	}
	return 0;
}