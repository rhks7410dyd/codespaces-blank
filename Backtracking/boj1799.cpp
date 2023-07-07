#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int dir[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
int map[10][10];
bool visit[10][10];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
		}
	}
	
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(map[i][j] && !visit[i][j]){
				for(int d = 0 ; d < 4 ; d++){
					pair<int,int> temp = {i,j};
					while(temp.first >= 0 && temp.first < n && temp.second >= 0 && temp.second < n){
						visit[temp.first][temp.second] = true;
						temp.first += dir[d][0];
						temp.second += dir[d][1];
					}
				}
				ans++;
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}