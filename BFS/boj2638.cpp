/*
9328(열쇠), 3197(백조의 호수)와 어느 정도 유사성이 있는 문제.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[100][100];
bool visit[100][100];
int N,M,time = 0;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void Input();
void Solve();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	Input();

	Solve();
	
	return 0;
}

void Input(){
	cin >> N >> M;
	
	for(int i = 0 ; i < N*M ; i++){
		cin >> map[i/M][i%M];
	}
}

void Solve(){
	while(true){
		memset(&visit[0][0],0,100000*sizeof(bool));
		bool all_melted = true;
		
		for(int i = 1 ; i < N-1 ; i++){
			for(int j = 1 ; j < M-1 ; j++){
				if(map[i][j] && !visit[i][j]){
					all_melted = false;
					
				}
			}
		}
	}
}
//지금하는대로면 무조건 시간초과 뜰거 같은데 이거 다시 생각 좀 해봐야됨. 시간 계산 해볼 것 + 다른 방식 생각해보기