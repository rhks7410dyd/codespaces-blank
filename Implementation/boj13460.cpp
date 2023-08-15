#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

char map[10][10];
int n,m;
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int r_start[2];
int b_start[2];
int end_spot[2];
queue<pair<pair<int,int>,pair<int,int>>> q;//{redpos,bluepos}

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
	두 구슬이 겹칠 수 없기 때문에, 동시에 움직여야됨. 그리고 동시에 움직인다는 것은 visit에 저장해야될 경우가 두 구슬위치를 모두 고려해서 방문했음을 저장해야됨
	10*10*10*10
	*/
	char visit[10][10][10][10];//{Br,Bc,Rr,Rc}
	memset(&visit[0][0][0][0],-1,sizeof(visit));
	
	q.push({{r_start[0],r_start[1]},{b_start[0],b_start[1]}});
	visit[r_start[0]][r_start[1]][b_start[0]][b_start[1]] = 0;
	int C = 10;
	while(C--){
		int q_size = q.size();
		
		for(int i = 0 ; i < q_size ; i++){
			auto now = q.front();
			q.pop();
			auto red = now.first;
			auto blue = now.second;
			
			int c = -1;
			if(red.first == blue.first){
				if(red.second < blue.second){
					c = 0;//동일 행, 레드가 왼쪽
				}
				else{
					c = 1;//동일 행, 레드가 오른쪽
				}
			}
			else if(red.second == blue.second){
				if(red.first < blue.first){
					c = 2;//동일 열,레드가 위
				}
				else{
					c = 3;//동일 열,레드가 아래
				}
			}
			bool red_end = false,blue_end = false;
			for(int d = 0 ; d < 4 ; d++){
				red = now.first;
				red = now.second;
				if(c == d){
					
				}
				else{
					while(red.first >= 0 && red.first < n && red.second >= 0 && red.second < m){
						red.first += dir[d][0];
						red.second += dir[d][1];
						if(red.first == end_spot[0] && red.second == end_spot[1]){
							
						}
					}
				}
			}
		}
	}
	
	cout << -1 << '\n';
	
	return 0;
}