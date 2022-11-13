#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int y,x;
};

//vector < vector <int> > v(10,vector <int>(10,0));
vector < vector < vector < pos > > > switchinfo(101,vector < vector < pos > >(101,vector<pos>(1,{0,0})));
int N , M , light_up_room = 0 ;
bool lightup[101][101];
bool link[101][101];
bool visit[101][101];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pos> q;

void input(){
    int x,y,a,b;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> x >> y >> a >> b;
        switchinfo[y][x].push_back({b,a});
    }
}

bool adjacent(int y,int x){
    int nx,ny;
    for(int i = 0 ; i < 4 ; i++){
        ny = y + dir[i][0];
        nx = x + dir[i][1];
        if(nx < 1 || nx > N || ny < 1 || ny > N)    continue;
        if(link[ny][nx])    return true;
    }
    return false;
}

void find_other_room(int y, int x){
	int ny,nx;
	for(int i = 0 ; i < 4 ; i++){
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if(nx < 1 || nx > N || ny < 1 || ny > N)	continue;
		if(!link[ny][nx] && lightup[ny][nx] && !visit[ny][nx]){
			visit[ny][nx] = true;
			link[ny][nx] = true;
			q.push({ny,nx});
			find_other_room(ny,nx);
		}
	}
}

void BFS(){
    int ty,tx,nx,ny,fx,fy;
    
    q.push({1,1});
    lightup[1][1] = true;
    link[1][1] = true;
    light_up_room++;
    while(!q.empty()){
        ty = q.front().y;
        tx = q.front().x;
        q.pop();
        for(int i = 1 ; i < switchinfo[ty][tx].size() ; i++){
            ny = switchinfo[ty][tx][i].y;
            nx = switchinfo[ty][tx][i].x;
            if(link[ny][nx])    continue;
            light_up_room++;
            lightup[ny][nx] = true;
            if(adjacent(ny,nx)){//이 파트를 쭉쭉 이어나가서 주변에 추가할 곳이 없을 때까지 해야됨!
                link[ny][nx] = true;
                visit[ny][nx] = true;
                q.push({ny,nx});
                find_other_room(ny,nx);
            }
        }
    }
}

void print_light_up_room(){
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			if(lightup[i][j])	cout << 1 << ' ';
			else	cout << 0 << ' ';
		}
		cout << endl;
	}
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    input();
    
    BFS();
	
	print_light_up_room();
	
    cout << light_up_room << endl;
    return 0;
}

