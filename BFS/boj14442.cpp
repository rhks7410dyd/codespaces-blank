#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int y,x,k;
};

int K,N,M;
bool visit[1001][1001][11];
int map[1001][1001];
int shrtpath[1001][1001][11];

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void BFS(){
    int tx,ty,tk,nx,ny;
    queue<pos> q;
    q.push({1,1,K});
    visit[1][1][K] = true;
    while(!q.empty()){
        tx = q.front().x;
        ty = q.front().y;
        tk = q.front().k;
        q.pop();
        if(tx == M && ty == N){
            cout << shrtpath[N][M][tk] + 1;
            return;
        }
        for(int i = 0 ; i < 4 ; i++){
            nx = tx + dir[i][0];
            ny = ty + dir[i][1];
            if(nx <= 0 || ny <= 0 || nx > M || ny > N)  continue;
            if(map[ny][nx] && !visit[ny][nx][tk-1] && tk > 0){//벽을 부술 수 있는 경우
                shrtpath[ny][nx][tk-1] = shrtpath[ty][tx][tk] + 1;
                visit[ny][nx][tk-1] = true;
                //cout << "break the wall ( " << nx << ',' << ny << " )\n";
                //cout << "nx " << nx << " ny " << ny << " shrtpath " << shrtpath[ny][nx][tk-1] <<endl;
                q.push({ny,nx,tk-1});
            }
            else if(!map[ny][nx] && !visit[ny][nx][tk]){//평지로 가는 경우
                shrtpath[ny][nx][tk] = shrtpath[ty][tx][tk] + 1;
                visit[ny][nx][tk] = true;
                //cout << "nx " << nx << " ny " << ny << " shrtpath " << shrtpath[ny][nx][tk] <<endl;
                q.push({ny,nx,tk});
            }
        }
    }
    cout << -1;
    return;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    string str[N+1];
    for(int i = 1 ; i <= N ; i++){
        cin >> str[i];
        for(int j = 1 ; j <= M ; j++){
            map[i][j] = str[i][j-1] - '0';
        }
    }
    /*
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }*/
    
    BFS();

    return 0;
}

