/*
아래처럼 하나하나 할게 아니라 유니온으로 묶어서 한 조각당 몇 개씩 있는지를 미리 dfs로 탐색해서 인접한 개수를 구하고, 
이후에 벽 근처에 있는 조각들의 갯수들의 합 + 1로 답을 내야 훨신 빠름
*/
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

bool visit[1000][1000];
int piece_num[1000][1000];
int map[1000][1000];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int N,M;
int cnt = 0;

vector<int> piece_val;

int dfs(int c,int r);

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
			if(map[i][j] == 0 && visit[i][j] == false){
				piece_val.push_back(dfs(i,j));
				cnt++;
			}
		}
	}
	
	vector<int> used_piece;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(map[i][j] == 1){
				int ans = 0;
				used_piece.clear();
				for(int d = 0 ; d < 4 ; d++){
					int next_c = i + dir[d][0];
					int next_r = j + dir[d][1];
					
					if(next_c < 0 || next_c >= N || next_r < 0 || next_r >= M || map[next_c][next_r])	continue;
					
					bool is_pluesd = false;
					for(int k = 0 ; k < used_piece.size() ; k++){
						if(used_piece[k] == piece_num[next_c][next_r])	is_pluesd = true;
					}
					if(is_pluesd)	continue;
					used_piece.push_back(piece_num[next_c][next_r]);
					
					ans += piece_val[piece_num[next_c][next_r]];
				}
				cout << (ans+1)%10;
			}
			else{
				cout << 0;
			}
		}
		cout << '\n';
	}
	
	return 0;
}

int dfs(int c,int r){
	stack<pair<int,int>> st;
	
	st.push({c,r});
	visit[c][r] = true;
	int ret = 1;
	piece_num[c][r] = cnt;
	
	while(!st.empty()){
		auto now = st.top();
		st.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int next_c = now.first + dir[i][0];
			int next_r = now.second + dir[i][1];
			
			if(next_c < 0 || next_c >= N || next_r < 0 || next_r >= M || visit[next_c][next_r] || map[next_c][next_r])	continue;
			
			st.push({next_c,next_r});
			visit[next_c][next_r] = true;
			ret++;
			piece_num[next_c][next_r] = cnt;
		}
	}
	
	return ret;
}