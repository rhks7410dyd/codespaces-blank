/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
벽을 '한 번'만 부술 수 있다는 점을 유념해야됨. 즉, position을 저장할 때, 벽을 부순 것인지 아닌지 확인을 하는 인수를 추가적으로 만들어놓아야됨.
그래야지 다음에 벽이 또 있더라도 거기로 못가게 할 수 있음! 이 문제에서는 이 부분을 bool을 이용하여 표현하는 것이 좋지만 갯수가 추가적으로
늘어난다면 short나 int를 이용하여 표현하는 것이 적절할 것으로 보임.

단순하게 bool을 이용해서 하나의 맵에 저장해버리면 처음에 벽을 부수지 않고 나중에 부수는게 더 빠른 경우에도 문제가 발생할 수 있음. 즉 두개의 
visit 을 만들어서 true인 경우와 아닌 경우 두 개를 모두 비교해봐야할 듯?
15%에서 틀림
*******************************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visit[2][1000][1000];
short map[1000][1000];
int N,M;
int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};

struct pos{
    int y,x;
    bool breakwall;
};

int BFS(){
    int cx,cy,nx,ny;
    bool br;
    queue<pos> q;
    q.push({0,0,false});
    while(!q.empty()){
        cx = q.front().x;
        cy = q.front().y;
        br = q.front().breakwall;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            nx = cx + dirx[i];
            ny = cy + diry[i];
            if(nx < 0 || ny < 0 || nx >= M ||ny >= N)   continue;
            //이번 큐에 넣은 것이 벽을 부셨던 것인지 아닌지로 나눠서 안에서 나누기
            if(br && visit[1][ny][nx] == 999999999){//이미 한 번 부신 경우
                if(map[ny][nx] == 0 && visit[1][ny][nx] > visit[1][cy][cx] + 1){
                    q.push({ny,nx,br});
                    visit[1][ny][nx] = visit[1][cy][cx] + 1;
                }
            }
            else if(!br && visit[0][ny][nx] == 999999999){//아직 안부신 경우
                if(map[ny][nx] == 1 && visit[1][ny][nx] > visit[0][cy][cx] + 1){//벽을 부셔버리는 경우
                    q.push({ny,nx,true});
                    visit[1][ny][nx] = visit[0][cy][cx] + 1;
                }
                else if(map[ny][nx] == 0){//빈 공간으로 가는 경우
                    q.push({ny,nx,br});
                    visit[(int)br][ny][nx] = visit[(int)br][cy][cx] + 1;
                } 
            }
        }
    }
    return min(visit[0][N-1][M-1],visit[1][N-1][M-1])+1;
}

int main()
{
    cin >> N >> M;
    char t;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> t;
            map[i][j] = t - '0';
            visit[0][i][j] = 999999999;
            visit[1][i][j] = 999999999;
        }
    }
    visit[0][0][0] = 0;
    int count = BFS();
    
    if(count != 1000000000)cout << count;
    else cout << -1;
    
    return 0;
}

