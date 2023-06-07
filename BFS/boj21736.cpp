#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string map[600];
bool visit[600][600];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n,m,x_s,y_s;
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		cin >> map[i];
		for(int j = 0 ; j < m ; j++){
			if(map[i][j] == 'I'){
				y_s = i;
				x_s = j;
				map[i][j] = 'O';
			}
		}
	}
	
	queue<pair<int,int>> q;
	q.push({y_s,x_s});
	visit[y_s][x_s] = true;
	int ans = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int next_y = now.first + dir[i][0];
			int next_x = now.second + dir[i][1];
			if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || visit[next_y][next_x])	continue;
			switch(map[next_y][next_x]){
				case 'X':
					visit[next_y][next_x] = true;
					break;
				case 'P':
					ans++;
					visit[next_y][next_x] = true;
					q.push({next_y,next_x});
					break;
				case 'O':
					visit[next_y][next_x] = true;
					q.push({next_y,next_x});
					break;
			}
		}
	}
	
	if(ans){
		cout << ans << '\n';
	}
	else{
		cout << "TT\n";
	}
	return 0;
}