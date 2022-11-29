/*
현재까지 고려한 예외 목록
1. 열쇠와 문 선후관계에 의한 문제점 해결
2. 벽에 갖혀있는 경우를 판단해야된 점 해결
3. 테스트 케이스를 중복으로 넣어서 6개짜리를 돌려도 동일하게 나옴
4. 최소한(O)의 or 최대한의 경우 테스트 필요함 -> 문제 X
5. 범위에 의한 문제? 이것도 확인
6. 

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos{
	int y,x;
};

int C,H,W,steal_document_count = 0;
bool findkey_boolean[26];
bool visit[100][100];
bool adjacent[100][100];
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
	cout << "ln 37\n";
	for(int h = 0 ; h < H ; h++){
		cin >> str;
		for(int w = 0 ; w < W ; w++){
			map[h][w] = str[w];
			if(h == 0 || h == H-1 || w == 0 || w == W-1){
				visit[h][w] = true;
				adjacent[h][w] = true;
				if(map[h][w] == '.'){
					q.push({h,w});
				}
				else if(map[h][w] >= 'A' && map[h][w] <= 'Z'){
					doorpos[map[h][w] - 'A'].push_back({h,w});
				}
				else if(map[h][w] == '$'){
					steal_document_count++;
					q.push({h,w});
				}
				else if(map[h][w] >= 'a' && map[h][w] <= 'z'){
					findkey_boolean[map[h][w]-'a'] = true;
					q.push({h,w});
				}
			}
			else{
				if(map[h][w] >= 'A' && map[h][w] <= 'Z'){
					doorpos[map[h][w] - 'A'].push_back({h,w});
				}
			}
		}
	}
	cout << "ln67\n";
	cin >> str;

	int y,x;
	if(str[0] != '0'){
		for(int i = 0 ; i < str.size() ; i++){
			findkey_boolean[str[i] - 'a'] = true;
		}
	}
}

void findkey(int indexnum){
	int vsize = doorpos[indexnum].size();
	int y,x;
	for(int j = 0 ; j < vsize ; j++){
		y = doorpos[indexnum][j].y;
		x = doorpos[indexnum][j].x;
		if(adjacent[y][x]){
			map[y][x] = '.';
			q.push({y,x});
		}
	}
}

void BFS(){
	int ty,tx,ny,nx;
	while(!q.empty()){
		ty = q.front().y;
		tx = q.front().x;
		q.pop();
		cout << endl << "( " << ty << ',' << tx << " ) : " << map[ty][tx] << '\n';
		for(int i = 0 ; i < 4 ; i++){
			ny = ty + dir[i][0];
			nx = tx + dir[i][1];
			if(ny < 0 || ny >= H || nx < 0 || nx >= W || visit[ny][nx])	continue;
			//배열 범위 밖이거나 or 이미 방문했으면 무시
			visit[ny][nx] = true;
			
			adjacent[ny][nx] = true;
			
			cout << "( " << ny << ',' << nx << " ) : " << map[ny][nx] << '\n';
			
			if(map[ny][nx] == '.'){
				q.push({ny,nx});
			}
			else if(map[ny][nx] >= 'a' && map[ny][nx] <= 'z'){
				findkey(map[ny][nx]-'a');
				findkey_boolean[map[ny][nx]-'a'] = true;
			}
			else if(map[ny][nx] == '$'){
				steal_document_count++;
				q.push({ny,nx});
			}
			else if(map[ny][nx] >= 'A' && map[ny][nx] <= 'Z'
					&& findkey_boolean[map[ny][nx]-'A'] ){
				// 문 위치면서 그 문의 열쇠를 이미 갖고 있는 경우
				q.push({ny,nx});
			}
		}
	}
}

void reset(){
	for(int j = 0 ; j < 26 ; j++){
		findkey_boolean[j] = false;
		doorpos[j].clear();
	}	

	steal_document_count = 0;
	
	for(int j = 0 ; j < H ; j++){
		for(int k = 0 ; k < W ; k++){
			visit[j][k] = false;
		}
	}
}

int main(){
	/*
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	*/
	int t;
	cin >> t;
	
	for(int i = 0 ; i < t ; i++){
		Input();
		
		BFS();
		
		cout << steal_document_count << endl;
		
		reset();
	}
	
	return 0;
}