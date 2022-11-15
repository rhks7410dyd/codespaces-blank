#include <iostream>
#include <queue> //덱을 사용할지 큐를 사용할지 고민해봐야됨
#include <vector>

using namespace std;

struct pos{
	int y,x;
};

int C,H,W,steal_document_count=0;
//bool findkey[26];	//굳이 이걸 안써도 다 .으로 바꾸고 큐에 푸쉬하면 상관 없음
bool visit[100][100];
char map[100][100];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pos> q;
vector<pos> doorpos[26];

void Input();
void findkey(int indexnum);
void BFS();
void reset();

void Input(){
	string str;
	cin >> H >> W;
	for(int h = 0 ; h < H ; h++){
		for(int w = 0 ; w < W ; w++){
			cin >> map[h][w];
			if(h == 0 || h == H-1 || w == 0 || w == W-1){
				if(map[h][w] == '.'){
					visit[h][w] = true;
					q.push({h,w});
				}
			}
			if(map[h][w] >= 'A' && map[h][w] <= 'Z'){
				doorpos[map[h][w] - 'A'].push_back({h,w});
			}
			if(map[h][w] == '$'){
				visit[h][w] = true;
				steal_document_count++;
				q.push({h,w});
			}
		}
	}
	cin >> str;
	
	int y,x;
	if(str[0] != '0'){
		for(int i = 0 ; i < str.size() ; i++){
			findkey(str[i]-'a');
		}
	}
}

void findkey(int indexnum){
	int vsize = doorpos[indexnum].size();
	int y,x;
	for(int j = 0 ; j < vsize ; j++){
		y = doorpos[indexnum][j].y;
		x = doorpos[indexnum][j].x;
		visit[y][x] = true;
		map[y][x] = '.';
		q.push({y,x});
	}
}

void BFS(){
	int ty,tx,ny,nx;
	while(!q.empty()){
		ty = q.front().y;
		tx = q.front().x;
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			ny = ty + dir[i][0];
			nx = tx + dir[i][1];
			if(ny < 0 || ny >= H || nx < 0 || nx >= W || visit[ny][nx])	continue;	//배열 범위 밖이거나 or 이미 방문했으면 무시
			//cout << "( " << ny << ',' << nx << " ) : " << map[ny][nx] << '\n';
			if(map[ny][nx] == '.'){
				visit[ny][nx] = true;
				q.push({ny,nx});
			}
			else if(map[ny][nx] >= 'a' && map[ny][nx] <= 'z'){
				findkey(map[ny][nx]-'a');
			}
			else if(map[ny][nx] == '$'){
				visit[ny][nx] = true;
				steal_document_count++;
				q.push({ny,nx});
			}
		}
	}
}

void reset(){
	for(int j = 0 ; j < 26 ; j++)	doorpos[j].clear();

	steal_document_count = 0;
	
	for(int j = 0 ; j < H ; j++){
		for(int k = 0 ; k < W ; k++){
			visit[j][k] = true;
		}
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> C;
	
	for(int i = 0 ; i < C ; i++){
		Input();
		
		BFS();
		
		cout << steal_document_count << '\n';
		
		reset();
	}
}