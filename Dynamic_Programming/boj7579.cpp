#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int N,M;
int dp[100][10001];
int cost[100];
int mem[100];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sycn_with_stdio(false);
	
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		cin >> mem[i];
	}
	for(int i = 0 ; i < N ; i++){
		cin >> cost[i];
	}
	
	int ans = Solve(-1,);
	
	cout << ans << '\n';
	return 0;
}