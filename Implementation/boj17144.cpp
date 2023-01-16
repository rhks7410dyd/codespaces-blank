#include <iostream>
#include <algorithm>

using namespace std;

int R,C,T,cleaner_c,cleaner_r;

int map[51][51];
int temp[51][51];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void spread_step();
void operating_step();
void print_map();

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
	
	for(int i = 1 ; i <= T ; i++){
		spread_step();
		
		//cout << "t : " << i << "\nbefore operating step\n";
		//print_map();
		
		operating_step();
		
		//cout << "after operating step\n";
		//print_map();
	}
	
	int sum = 0;
	for(int r = 1 ; r <= R ; r++){
		for(int c = 1 ; c <= C ; c++){
			if(map[r][c] != -1)	sum += map[r][c];
		}
	}
	
	cout << sum << '\n';
	
	return 0;
}

void spread_step(){
	fill(&temp[1][1],&temp[50][51],0);//temp array setting

	int tr,tc,tval;
	for(int r = 1 ; r <= R ; r++){
		for(int c = 1 ; c <= C ; c++){
			if(map[r][c] == 0 || map[r][c] == -1){
				continue;
			}
			
			temp[r][c] += map[r][c];
			for(int k = 0 ; k < 4 ; k++){
				tr = r + dir[k][0];
				tc = c + dir[k][1];
				if(tr < 1 || tc < 1 || tr > R || tc > C || map[tr][tc] == -1)	continue;
				// 현재 탐색 점이 범위 밖이거나 공기 청정기 위치가 아님
				tval = map[r][c]/5;
				temp[r][c] -= tval;
				temp[tr][tc] += tval;
			}
			
		}
	}
	
	for(int r = 1 ; r <= R ; r++){
		for(int c = 1 ; c <= C ; c++){
			map[r][c] = temp[r][c];
		}
	}
}

void operating_step(){
	for(int i = cleaner_r - 2 ; i > 1 ; i--){
		map[i][1] = map[i-1][1];
	}
	
	for(int i = cleaner_r + 1 ; i < R ; i++){
		map[i][1] = map[i+1][1];
	}
	
	for(int i = 1 ; i < C ; i++){
		map[1][i] = map[1][i+1];
		map[R][i] = map[R][i+1];
	}
	
	for(int i = 1 ; i < cleaner_r - 1 ; i++){
		map[i][C] = map[i+1][C];
	}
	
	for(int i = R ; i > cleaner_r ; i--){
		map[i][C] = map[i-1][C];
	}
	
	for(int i = C ; i > 2 ; i--){
		map[cleaner_r-1][i] = map[cleaner_r-1][i-1];
		map[cleaner_r][i] = map[cleaner_r][i-1];
	}
	
	map[cleaner_r-1][1] = -1;
	map[cleaner_r][1] = -1;
	
	map[cleaner_r-1][2] = 0;
	map[cleaner_r][2] = 0;
}

void print_map(){
	cout << "print map\n";
	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}