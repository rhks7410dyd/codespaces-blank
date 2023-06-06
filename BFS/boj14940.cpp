#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[1000][1000];
int ans[1000][1000];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n,m;
	int x_s,y_s;
	
	cin >> n >>m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> map[i][j];
			if(map[i][j] == 2){
				x_s = j;
				y_s = i;
			}
		}
	}
	
	queue<pair<int,int>> q;
	q.push({y_s,x_s});
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0 ; i < qsize ; i++){
			auto now = q.front();
			q.pop();
			for(int next = 0 ; next < 4 ; next++){
				int y_n = now.first + dir[next][0];
				int x_n = now.second + dir[next][1];
				if(0 > y_n || y_n >= n || 0 > x_n || x_n >= m || !map[y_n][x_n] || ans[y_n][x_n])	continue;
				q.push({y_n,x_n});
				ans[y_n][x_n] = ans[now.first][now.second]+1;
				
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(ans[i][j] == 0 && map[i][j] == 1){
				ans[i][j] = -1;
			}
		}
	}		
	ans[y_s][x_s] = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}	
	
	return 0;
}