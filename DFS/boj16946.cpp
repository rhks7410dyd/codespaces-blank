/*
아래처럼 하나하나 할게 아니라 유니온으로 묶어서 한 조각당 몇 개씩 있는지를 미리 dfs로 탐색해서 인접한 개수를 구하고, 이후에 벽 근처에 있는 조각들의 갯수들의 합 + 1로 답을 내야 훨신 빠름
*/
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int ans[1000][1000];
int map[1000][1000];
bool visit[1000][1000];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int N,M;

int solve(int c,int r);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	string temp;
	for(int i = 0 ; i < N ; i++){
		cin >> temp;
		for(int j = 0 ; j < M ; j++){
			map[i][j] = temp[j] - '0';
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(map[i][j]){
				memset(visit,0,sizeof(visit));
				ans[i][j] = solve(i,j);
			}
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}

int solve(int c,int r){
	stack<pair<int,int>> st;
	st.push({c,r});
	visit[c][r] = true;
	int ret = 1;
	
	while(!st.empty()){
		auto now = st.top();
		st.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int next_c = now.first + dir[i][0];
			int next_r = now.second + dir[i][1];
			
			if(next_c < 0 || next_c >= N || next_r < 0 || next_r >= M || visit[next_c][next_r] || map[next_c][next_r])	continue;
			
			ret++;
			visit[next_c][next_r] = true;
			st.push({next_c,next_r});
		}
	}
	
	return ret;
}