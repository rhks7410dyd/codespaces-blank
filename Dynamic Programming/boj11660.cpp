#include <iostream>

using namespace std;

int dp[1025][1025];
int N,M;

void printdp(){
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	scanf("%d %d",&N,&M);
	int temp;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			scanf("%d",&temp);
			dp[i][j] = (temp + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);
		}
	}
	
	//printdp();
	
	int x1,x2,y1,y2;
	for(int i = 0 ; i < M ; i++){
		//이렇게 일괄적으로 하면 안되는듯 두번째 케이스 했을때 이상하게 나오는 이유가 이거인거 같음
		//직접 행열을 써놓고 확인해볼 것!
		scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
		int val = dp[y2][x2] - dp[y2][x1-1] - dp[y1 -1][x2] + dp[y1-1][x1-1];
		//cout << dp[y2][x2] << " - " << dp[y2][x1-1] << " - " << dp[y1-1][x2] << " + " << dp[y1-1][x1-1] << " = " <<val << '\n';
		cout << val << '\n';
	}
	
	return 0;
}