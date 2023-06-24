#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[10][10];
int n,m;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
pair<int,int> r_start;
pair<int,int> b_start;
pair<int,int> end_spot;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
			if(map[i][j] != '#' && map[i][j] != '.'){
				if(map[i][j] == 'B'){
					b_start = {i,j};
				}
				else if(map[i][j] == 'R'){
					r_start = {i,j};
				}
				else{
					end_spot = {i,j};
					map[i][j] = '0';
				}
			}
		}
	}
	
	cout << b_start.first << ' ' << b_start.second << '\n';
	cout << r_start.first << ' ' << r_start.second << '\n';
	cout << end_spot.first << ' ' << end_spot.second << '\n';
	
	bool visit[10][10],can_reached = false;
	queue<pair<int,int>> q;
	q.push({r_start.first,r_start.second});
	visit[r_start.first][r_start.second] = true;
	while(!q.empty() && !can_reached){
		auto now = q.front();
		q.pop();
		for(int d = 0 ; d < 4 ; d++){
			int n_c = now.first + dir[d][0];
			int n_r = now.second + dir[d][1];
			
			if(n_r < 0 || n_c < 0 || n_r >= m || n_c >= n || map[n_c][n_r] == '#' || visit[n_c][n_r])	continue;
			
			if(map[n_c][n_r] == '0'){
				can_reached = true;
				break;
			}
			
			visit[n_c][n_r] = true;
			q.push({n_c,n_r});
		}
	}
	
	if(!can_reached){
		cout << -1 << '\n';
		return 0;
	}
	else{
		cout << 0 << '\n';
	}
	return 0;
}