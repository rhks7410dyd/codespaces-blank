//시간 초과가 뜸
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int map[20][20];
int N;
int plus_time,f_r,f_c,s_r,s_c,shark_size=2,shark_eating_fish = 0;
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
		time += plus_time;
		//cout << "shark position (" << s_c << ',' << s_r << ")\tfish position (" << f_c << ',' << f_r << ")\ttime : " << time << endl;
		map[s_c][s_r] = 0;
		map[f_c][f_r] = 0;
		s_c = f_c;
		s_r = f_r;
		shark_eating_fish++;
		if(shark_eating_fish == shark_size){
			shark_size++;
			shark_eating_fish = 0;
		}
	}
	
	cout << time << '\n';
	
	/*
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	
	return 0;
}

bool can_eat_fish(){
	bool visit[20][20] = {false,};
	queue<pair<pair<int,int>,int>> q;
	
	q.push({{s_c,s_r},0});
	visit[s_c][s_r] = true;
	//최단경로로 갈 수 없다는 사실을 고려할 것
	while(!q.empty()){
		int qsize = q.size();
		vector<pair<int,int>> v;
		
		for(int T = 0 ; T < qsize ; T++){
			int now_c = q.front().first.first;
			int now_r = q.front().first.second;
			int now_t = q.front().second;
			q.pop();

			for(int i = 0 ; i < 4 ; i++){
				int next_r = now_r + dir[i][1];
				int next_c = now_c + dir[i][0];

				if(next_r < 0 || next_c < 0 || next_r >= N || next_c >= N || visit[next_c][next_r])	continue;

				if(shark_size > map[next_c][next_r] && map[next_c][next_r] != 0){
					plus_time = now_t+1;
					v.push_back({next_c,next_r});
					continue;
				}

				if(shark_size == map[next_c][next_r] || map[next_c][next_r] == 0){
					visit[next_c][next_r] = true;
					q.push({{next_c,next_r},now_t+1});
				}
			}
		}
		
		if(!v.empty()){
			int best_hash_val = v[0].first * 100 + v[0].second;
			int best_p=0;
			for(int i = 0 ; i < v.size() ; i++){
				if(best_hash_val > v[i].first * 100 + v[i].second){
					best_hash_val = v[i].first * 100 + v[i].second;
					best_p = i;
				}
			}
			f_c = v[best_p].first;
			f_r = v[best_p].second;
			
			return true;
		}
	}
	
	return false;
}

/*
8
1 0 1 0 1 0 1 0
3 6 6 6 6 6 6 0
0 0 0 0 0 0 0 0
9 6 6 6 6 6 6 6
0 0 0 0 0 0 0 0
6 6 6 6 6 6 6 0
2 2 2 2 2 2 3 3
0 0 0 0 0 0 0 0

*/