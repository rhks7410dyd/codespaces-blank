/*
9328(열쇠), 3197(백조의 호수)와 어느 정도 유사성이 있는 문제.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<pair<int,int>,bool>> chease;
int map[100][100];
bool outside_air[100][100];
int N,M,T = -1;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void Input();
void Solve();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	Input();

	Solve();
	
	return 0;
}

void Input(){
	cin >> N >> M;
	
	for(int i = 0 ; i < N*M ; i++){
		cin >> map[i/M][i%M];
		if(map[i/M][i%M] == 1){
			chease.push_back({{i/M,i%M},false});//{{pos},is_melted}
		}
	}
}

void Solve(){
	int trow,tcol;
	bool t_is_melted;
	queue<pair<int,int>> q;
	q.push({0,0});
	outside_air[0][0] = true;
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			trow = temp.first + dir[i][0];
			tcol = temp.second + dir[i][1];
			if(trow < 0 || trow >= N || tcol < 0 || tcol >= M)	continue;
			if(!map[trow][tcol] && !outside_air[trow][tcol]){
				q.push({trow,tcol});
				outside_air[trow][tcol] = true;
			}
		}
	}//초반 입력값에서 외부 공기 찾음
	
	bool some_chease_is_melted;
	do{
		some_chease_is_melted = false;
		for(int i = 0 ; i < chease.size() ; i++){
			auto temp_c = chease[i];
			trow = temp_c.first.first;
			tcol = temp_c.first.second;
			t_is_melted = temp_c.second;

			if(t_is_melted)	continue;

			int count_of_outside = 0;
			for(int j = 0 ; j < 4 ; j++){
				if(trow + dir[j][0] < 0 || trow + dir[j][0] >= N || tcol + dir[j][1] < 0 || tcol + dir[j][1] >= M)	continue;
				if(outside_air[trow + dir[j][0]][tcol + dir[j][1]])	count_of_outside++;
			}

			if(count_of_outside >= 2){
				chease[i].second = true;
				some_chease_is_melted = true;
			}
		}
		
		for(int i = 0 ; i < chease.size() ; i++){
			if(chease[i].second)	outside_air[chease[i].first.first][chease[i].first.second] = true;
		}
		T++;
	}while(some_chease_is_melted);
	
	cout << T << endl;
	
	//중간에 빈 공간이었던 곳을 outside_air에서 트루로 못바꿔줘서 틀리는 거임. 이 부분만 고치면 정답이 될듯.
}