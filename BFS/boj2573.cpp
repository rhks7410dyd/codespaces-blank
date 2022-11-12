/******************************************************************************
 ------------------------------------------------------------------------------
 ------------------------------------------------------------------------------
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct pos{
    short y,x;
};

short N,M;
short map[300][300];
short minusval[300][300];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool visit[300][300];
pos start = {-1,-1};

void printmap(){
    cout << "print map\n";
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void printminus(){
    cout << "print minus value\n";
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cout << minusval[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void printvisit(){
    cout << "print visit array\n";
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(visit[i][j]) cout << 1 << ' ';
            else    cout << 0 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int count){
    queue<pos> q;
    vector<pos> save;
    q.push(start);
    short tx,ty,nx,ny,tminus,tsmyr;
    int c,year=0;
    visit[start.y][start.x] = true;
    while(true){
        year++;
        c=0;
        while(!q.empty()){//while 안에서 너비우선 탐색을 실행하고 다음 빙하가 녹는데까지
        //최소 몇년이 걸리는지를 확인하면서 탐색을 진행함
            c++;
            tminus = 0;
            tx = q.front().x;
            ty = q.front().y;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                nx = tx + dir[i][0];
                ny = ty + dir[i][1];
                if(nx < 0 || nx >= M || ny < 0 || ny >= N)  continue;
                if(map[ny][nx] && !visit[ny][nx]){//빙산조각이 있는 경우
                    visit[ny][nx] = true;
                    q.push({ny,nx});
                }
                else if(!map[ny][nx]){//바닷물이 있는 경우
                    tminus++;
                }
            }
            minusval[ty][tx] = tminus;
        }
        //cout << "count " << count << " c " << c<<endl;
        if(count != c) break;
        
        for(int i = M + 1 ; i < M*N ; i++){
            if(map[i/M][i%M]){
                map[i/M][i%M] -= minusval[i/M][i%M];
                if(map[i/M][i%M] <= 0){
                    map[i/M][i%M] = 0;
                    count--;//다 녹은 빙산이 생길 때마다 count 개수를 줄여서 총 개수를 낮춰줘야됨.
                }
            }
        }
        //printmap();
        
        
        memset(visit,0,sizeof(visit));
        memset(minusval,0,sizeof(minusval));
        for(int i = M + 1 ; i < M*N ; i++){//start pos 찾기
            if(map[i/M][i%M]){
                q.push({i/M,i%M});
                visit[i/M][i%M] = true;
                break;
            }
        }
    }
    cout << year-1;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int count=0;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
            if(map[i][j]){
                count++;
                if(start.x == -1 && start.y == -1){
                    start = {i,j};
                }
            }
        }
    }
    //printmap();
    BFS(count);
    
    return 0;
}






