// N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
// 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.
// 이동하지 않고 같은 칸에 머물러있는 경우도 가능하다. 이 경우도 방문한 칸의 개수가 하나 늘어나는 것으로 생각해야 한다.
// 이번 문제에서는 낮과 밤이 번갈아가면서 등장한다. 가장 처음에 이동할 때는 낮이고, 한 번 이동할 때마다 낮과 밤이 바뀌게 된다. 이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.
// 만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다. 단, 벽은 낮에만 부술 수 있다.
// 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.
// 맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
// 14442와의 차이점은 낮과 밤의 유무이다.
// 우선순위 큐로 기존 큐에서 바꿔준 이유는 현재 알고리즘이 먼저 움직인 쪽이 큐에서 선입 되도록 했는데, +2를 시키는 밤에 벽을 부수는 경우 때문에 이 순서가 깨져버렸다.
// 따라서 이를 보안하기 위해서 우선순위 큐를 써서 기본적으로 더 가까이있는걸 먼저 오게 했다. 하지만 이러한 방식은 연산 시간 상의 문제가 있을 수 있다.
// 만약에 시간 초과가 뜬다면, 다음 방식으로는 다른 것을 써봐야 할 것 같은데 당장 아이디어가 없다.
// shrtpath 3차원 배열 말고 그냥 구조체에 값을 입력하면서 하면 안되나? 이렇게 한번 바꿔보기.

#include <iostream>
#include <queue>

using namespace std;

struct pos{
	int y,x,k,time=0;
};

int N,M,K;
int map[1001][1001];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool daytime = true;
bool visit[1001][1001][11];

struct cmp {
  bool operator()(pos a, pos b) {
    // 거리 값이 같은 경우
    if(a.time == b.time) {
      // k 값이 작은 것이 우선하도록한다.
      return a.k > b.k;
    }
    // int형의 값이 작은 것이 우선하도록한다.
    return a.time > b.time;
  }
};

void Input(){
	cin >> N >> M >> K;
    string str;
    for(int i = 1 ; i <= N ; i++){
        cin >> str;
        for(int j = 1 ; j <= M ; j++){
            map[i][j] = str[j-1] - '0';
        }
    }
}

void Solve(){
	int ty,tx,ny,nx,tk,tt;
	priority_queue<pos,vector<pos>,cmp> q;
	priority_queue<pos,vector<pos>,cmp> targetinfo;
	q.push({1,1,K,1});
	visit[1][1][K] = true;
	while(!q.empty()){
		ty = q.top().y;
		tx = q.top().x;
		tk = q.top().k;
		tt = q.top().time;
		q.pop();
		if(tt%2)	daytime = true;
		else	daytime = false;
		//cout << "tx " << tx << " ty " << ty << " tt " << tt <<endl;
		if(tx == M && ty == N){
			cout << tt << '\n';
			return;
		}
		for(int i = 0 ; i < 4 ; i++){
			ny = ty + dir[i][0];
			nx = tx + dir[i][1];
			if(ny < 1 || nx < 1 || ny > N || nx > M)	continue;
            if(map[ny][nx] && !visit[ny][nx][tk-1] && tk > 0){//벽을 부술 수 있는 경우
                if(daytime)	q.push({ny,nx,tk-1,tt+1});
				else	q.push({ny,nx,tk-1,tt+2});
                visit[ny][nx][tk-1] = true;
                //cout << "break the wall ( " << nx << ',' << ny << " )";
                //cout << " tt " << tt <<endl;
            }
            else if(!map[ny][nx] && !visit[ny][nx][tk]){//평지로 가는 경우
                visit[ny][nx][tk] = true;
                //cout << "nx " << nx << " ny " << ny << " tt " << tt <<endl;
                q.push({ny,nx,tk,tt+1});
            }
		}
	}
	cout << -1;
	return;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	
	Input();
	
	Solve();
	
	cout << '\n';
	
	return 0;
}