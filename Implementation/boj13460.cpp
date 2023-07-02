#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

char map[10][10];
int n,m;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int r_start[2];
int b_start[2];
int end_spot[2];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> map[i][j];
			if(map[i][j] != '#' && map[i][j] != '.'){
				if(map[i][j] == 'B'){
					b_start[0] = i;
					b_start[1] = j;
					continue;
				}
				else if(map[i][j] == 'R'){
					r_start[0] = i;
					r_start[1] = j;
					continue;
				}
				else if(map[i][j] == 'O'){
					end_spot[0] = i;
					end_spot[1] = j;
				}
			}
		}
	}
	
	/*
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	
	/*
	예제 4에서 볼 수 있듯이 중간에 갈 수 있으면 안됨. 끝까지 가서 벽에 부딪힌 순간을 큐에 넣어야됨.
	bfs를 통해서 두 개의 구슬이 O까지 갈 수 있는지를 확인함
	1. 빨간 구슬이 갈 수 없는 경우 -> -1
	2. 빨간 구슬만 갈 수 있는 경우 -> 가는데 걸리는 최소 횟수
	3. 두 구슬 모두 갈 수 있는 경우 -> ???
	*/
	bool visit[10][10];
	int C = 10;
	while(C--){
		
	}
	
	
	return 0;
}