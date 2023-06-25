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
				else if(map[i][j] == '0'){
					end_spot[0] = i;
					end_spot[1] = j;
				}
			}
		}
	}
	
	bool visit[10][10],can_reached = false;
	memset(&visit[0][0],0,sizeof(visit));
	queue<pair<int,int>> q;
	q.push({r_start[0],r_start[1]});
	visit[r_start[0]][r_start[1]] = true;
	
	while(!q.empty() && !can_reached){
		auto now = q.front();
		q.pop();
		for(int d = 0 ; d < 4 ; d++){
			int n_c = now.first + dir[d][0];
			int n_r = now.second + dir[d][1];

			if(n_r < 0 || n_c < 0 || n_r >= m || n_c >= n || visit[n_c][n_r])	continue;

			visit[n_c][n_r] = true;
			
			if(map[n_c][n_r] == '#'){
				continue;
			}
			q.push({n_c,n_r});
			
			if(n_c == end_spot[0] && n_r == end_spot[1]){
				can_reached = true;
				break;
			}
		}
	}
	
	if(!can_reached){
		cout << -1 << '\n';
	}
	else{
		cout << 0 << '\n';
	}
	return 0;
}