#include <iostream>
#include <queue> //덱을 사용할지 큐를 사용할지 고민해봐야됨
#include <vector>

using namespace std;

struct pos{
	int y,x;
};

int C,H,W;
bool findkey[26];
bool visit[100][100];
char map[100][100];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pos> q;
vector<pos> start;
vector<pos> rockpos[26];

void Input(){
	string str;
	cin >> H >> W;
	for(int h = 0 ; h < H ; h++){
		for(int w = 0 ; w < W ; w++){
			cin >> map[h][w];
			if(h == 0 || h == H-1 || w == 0 || w == W-1){
				if(map[h][w] == '.'){
					start.push_back({h,w});
					q.push({h,w});
				}
			}
			if(map[h][w] >= 'A' && map[h][w] <= 'Z'){
				rockpos[map[h][w] - 'A'].push_back({h,w});
			}
		}
	}
	cin >> str;
	for(int i = 0 ; i < str.size() ; i++){
		
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> C;
	
	int ty,tx,ny,nx;
	for(int i = 0 ; i < C ; i++){
		Input();
		
		while(!q.empty()){
			ty = q.front().y;
			tx = q.front().x;
			q.pop();
			for(int j = 0 ; j < 4 ; j++){
				ny = ty + dir[i][0];
				nx = tx + dir[i][1];
				if(ny < 0 || ny >= H || nx < 0 || nx >= W)	continue;
				
			}
		}
		
		start.clear();
	}
}