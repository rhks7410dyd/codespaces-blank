//시간 초과가 뜸
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

int map[20][20];
int N;
bool visit[20][20];
int f_r,f_c,s_r,s_c,shark_size=2,shark_eating_fish = 0;
int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

bool can_eat_fish();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> map[i][j];
			if(map[i][j] == 9){
				s_c = i;
				s_r = j;
			}
		}
	}
	
	int time = 0;
	
	while(can_eat_fish()){
		time += abs(s_c-f_c)+abs(s_r-f_r);
		s_c = f_c;
		s_r = f_r;
		shark_eating_fish++;
		if(shark_eating_fish == shark_size){
			shark_size++;
			shark_eating_fish = 0;
		}
		fill(&visit[0][0],&visit[19][20],false);
	}
	
	cout << time << '\n';
	
	return 0;
}

bool can_eat_fish(){
	queue<pair<int,int>> q;
	
	q.push({s_c,s_r});
	visit[s_c][s_r] = true;
	
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int next_r = now.second + dir[i][1];
			int next_c = now.first + dir[i][0];
			
			if(next_r < 0 || next_c < 0 || next_r >= N || next_c >= N || visit[next_c][next_r])	continue;
			
			if(shark_size > map[next_c][next_r] && map[next_c][next_r] != 0){
				f_c = next_c;
				f_r = next_r;
				return true;
			}
			
			if(shark_size == map[next_c][next_r] || map[next_c][next_r] == 0){
				visit[next_c][next_r] = true;
				q.push({next_c,next_r});
			}
		}
	}
	
	return false;
}