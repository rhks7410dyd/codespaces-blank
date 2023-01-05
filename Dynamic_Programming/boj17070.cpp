#include <iostream>

using namespace std;

int N;
int map[16][16];
int dp[16][16];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> map[i][j];
		}
	}
	
	dp[0][1] = 1;
	
	//1번 행
	for(int i = 2 ; i < N-1 ; i++){
		if(map[0][i] == 0)	dp[0][i] += dp[0][i-1];
	}
	
	//나머지 행
	for(int i = 1 ; i < N ; i++){
		for(int j = 2 ; j < N ; j++){
			if(map[i][j] == 1)	continue;
			
			//현재 값을 입력받는 위치를 기준으로 왼쪽, 왼쪽 대각선 위, 위쪽 이렇게 세 곳의 벽 유무를 통해 어느 곳에서 올 수 있는지를 확인해봐야됨.
			int Type = map[i-1][j-1] + map[i-1][j]*2 + map[i][j-1]*4;
			
			if(Type == 0){//세 방향에서 모두 올 수 있음
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1];
			}
			else if(Type == 1){//왼쪽, 위에서만 올 수 있음
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
			else if(Type/2 == 1){//왼쪽에서만 올 수 있음
				dp[i][j] = dp[i][j-1];
			}
			else if(Type/2 == 2){//위에서만 올 수 있음
				dp[i][j] = dp[i-1][j];
			}
			
			//여기 아래 식이 쥰내 이상함.
			if(i != N -1 || j != N-1){
				if(i == N-1){
					if((Type/2)%2 == 0)	dp[i][j] -= dp[i-1][j];
				}
				if(j == N-1){
					if(Type/2 == 0 || Type/2 == 1)		dp[i][j] -= dp[i][j-1];
				}
			}
		}
	}
	
	cout << dp[N-1][N-1] << '\n';
}