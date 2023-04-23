#include <iostream>
#include <algorithm>

using namespace std;

int dp[1010][3];//R G B
int val[1010][3];
int his[1010][3];

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
	
	dp[0][0] = val[0][0];
	dp[0][1] = val[0][1];
	dp[0][2] = val[0][2];
	his[0][1] = 1;
	his[0][2] = 2;
	int temp_p;
	for(int i = 1 ; i < N-1 ; i++){//이거 이대로 하면 결국에는 선택이 뭐였는지를 몰라서, 최솟값을 이루는 애가 맨 처음 선택이 뭐였는지를 알 수가 없음. 이걸 추가 해줘야되서 min 함수로 박을 수가 없음
		if(dp[i-1][1] > dp[i-1][2]){
			temp_p = 2;
		}
		else{
			temp_p = 1;
		}
		his[i][0] = his[i-1][temp_p];
		dp[i][0] = dp[i-1][temp_p] + val[i][0];
		
		if(dp[i-1][0] > dp[i-1][2]){
			temp_p = 2;
		}
		else{
			temp_p = 0;
		}
		his[i][1] = his[i-1][temp_p];
		dp[i][1] = dp[i-1][temp_p] + val[i][1];
		
		if(dp[i-1][1] > dp[i-1][0]){
			temp_p = 0;
		}
		else{
			temp_p = 1;
		}
		his[i][2] = his[i-1][temp_p];
		dp[i][2] = dp[i-1][temp_p] + val[i][2];
	}
	
	for(int i = 0 ; i < 3 ; i++){//dp[N-1][i]의 값을 구하는 차례
		dp[N-1][i] = 987654321;
		for(int j = 0 ; j < 3 ; j++){//N-2번째 애의 색이 j임
			if(i == j || i == his[N-2][j])	continue;
			dp[N-1][i] = dp[N-1][i] < (dp[N-2][j] + val[N-1][i]) ? dp[N-1][i] : (dp[N-2][j] + val[N-1][i]);
		}
	}
	
	//int ans = min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});
	
	//printf("%d\n",ans);
	
	for(int i = 0 ; i < N ; i++){
		printf("%12d%12d%12d\t%12d%12d%12d\n",dp[i][0],dp[i][1],dp[i][2],his[i][0],his[i][1],his[i][2]);
	}
	
	return 0;
}
/*
마지막이랑 처음 거 총 가능한 가짓수가 6가지. 이 6가지 경우에서 모든 경우의 수가 나오므로 6개만 확인해보면될듯
*/