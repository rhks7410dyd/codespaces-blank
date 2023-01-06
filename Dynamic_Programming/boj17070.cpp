#include <iostream>

using namespace std;

int N;
int map[16][16];
int dp[16][16][3];//마지막 인덱스에서 0은 가로, 1은 세로, 2는 대각선의 형태이다.

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
	
	dp[0][1][0] = 1;
	
	//1번 행
	for(int i = 2 ; i < N ; i++){
		if(map[0][i] == 0)	dp[0][i][0] += dp[0][i-1][0];
	}
	
	//나머지 행 -> 더하는 걸 이렇게 무지성으로 더하지 말고, 형태에 따라 안될 수도 있음을 인지해야됨.
	for(int i = 1 ; i < N ; i++){
		for(int j = 2 ; j < N ; j++){
			if(map[i][j] == 1)	continue;
			
			//현재 값을 입력받는 위치를 기준으로 왼쪽, 왼쪽 대각선 위, 위쪽 이렇게 세 곳의 벽 유무를 통해 어느 곳에서 올 수 있는지를 확인해봐야됨.
			int Type = map[i-1][j-1] + map[i-1][j]*2 + map[i][j-1]*4;
			
			switch(Type){
				case 0://셋다비어있음
					dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
					dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
					dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
					break;
				case 1://대각선만 벽
					dp[i][j][0] = dp[i][j-1][0];
					dp[i][j][1] = dp[i-1][j][1];
					break;
				case 2://위만 벽
					dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
					break;
				case 3://대각선과 위가 벽
					dp[i][j][0] = dp[i][j-1][0];
					break;
				case 4://왼쪽만 벽
					dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
					break;
				case 5://대각선과 왼쪽이 벽
					dp[i][j][1] = dp[i-1][j][1];
					break;
			}
		}
	}
	
	/*
	cout << endl;
	for(int k = 0 ; k < 3 ; k++){
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				cout << dp[i][j][k] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	*/
	
	cout << dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2] << '\n';
}