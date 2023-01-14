#include <iostream>
#include <algorithm>

using namespace std;

int R,C,T,cleaner_c,cleaner_r;

int map[51][51];
int temp[51][51];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void spread_step();
void operating_step();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> R >> C >> T;
	
	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			cin >>map[i][j];
			if(map[i][j] == -1){//청정기의 아래 위치가 입력될 것임.
				cleaner_r = i;
				cleaner_c = j;
			}
		}
	}
	
	for(int i = 0 ; i < T ; i++){
		
	}
}

void spread_step(){
	fill(&temp[1][1],&temp[50][51],0);//temp array setting

	int tr,tc;
	for(int r = 1 ; r <= R ; r++){
		for(int c = 1 ; c <= C ; c++){
			if(map[r][c] == 0 || map[r][c] == -1){
				continue;
			}
			else{
				temp[r][c] = map[r][c];
				for(int k = 0 ; k < 4 ; k++){
					if(r + dir[k][0] < 1 || c + dir[k][1] < 1 || r + dir[k][0] > R || c + dir[k][1] > C || map[r+dir[k][0]][c+dir[k][1]] == -1)	continue;
					// 현재 탐색 점이 범위 밖이거나 공기 청정기 위치가 아님
					
				}
			}
		}
	}
}