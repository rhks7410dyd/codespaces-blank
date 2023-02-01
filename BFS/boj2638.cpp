/*
9328(열쇠), 3197(백조의 호수)와 어느 정도 유사성이 있는 문제.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<pair<int,int>,bool> cheese;
int map[100][100];
bool outside_air[100][100];
int N,M,time = 0;
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
			cheese.push_back({{i/M,i%M},false});
		}
	}
}

void Solve(){
	queue<pair<int,int>> q;
	q.push({0,0});
	outside_air[0][0] = true;
	while(!q.empty()){
		auto temp = q.front();
		q.pop;
		for(int i = 0 ; i < 4 ; i++){
			trow = temp.first + dir[i][0];
			tcol = temp.second + dir[i][1];
			if(trow < 0 || trow >= N || tcol < 0 || tcol >= M)	continue;
			
		}
	}
}
//지금하는대로면 무조건 시간초과 뜰거 같은데 이거 다시 생각 좀 해봐야됨. 시간 계산 해볼 것 + 다른 방식 생각해보기
