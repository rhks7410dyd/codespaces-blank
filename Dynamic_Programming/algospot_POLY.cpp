//메모해서 정리해보기
#include <iostream>
#include <cstring>
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
		
		int ans = 0;
		for(int i = 1 ; i <= N ; i++){
			ans += recursive(N-i,i)%mod;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}

int recursive(int n,int b_c){
	if(n==0)	return 1;
	if(n==1)	return b_c;
	
	int ret = 0;
	for(int i = 1 ; i <= n ; i++){
		ret = (ret * recursive(n-i,i))%mod;
	}
	return ret;
}
