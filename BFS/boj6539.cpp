/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

char map[30][30][30];//순서대로 l r c;
int visit[30][30][30];
int dirx[6] = {1,-1,0,0,0,0};
int diry[6] = {0,0,1,-1,0,0};
int dirz[6] = {0,0,0,0,1,-1};

struct pos{
    int z,y,x;
};

pos start;
pos buildingexit;

int l,r,c;

int BFS(){
    queue<pos> q;
    int cx,cy,cz,nx,ny,nz,count = 0;
    q.push(start);
    while(!q.empty()){
        cz = q.front().z;
        cy = q.front().y;
        cx = q.front().x;
        //cout << cz << ' ' << cy << ' ' << cx << endl;
        q.pop();
        for(int i = 0 ; i < 6 ; i++){
            nz = cz + dirz[i];
            ny = cy + diry[i];
            nx = cx + dirx[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= c || ny >= r || nz >= l) continue; //맵 밖일 경우에 컨티뉴
            if(map[nz][ny][nx] == 'E')  return visit[cz][cy][cx] + 1;
            if(map[nz][ny][nx] != '#' && visit[nz][ny][nx] == -1){
                visit[nz][ny][nx] = visit[cz][cy][cx] + 1;
                q.push({nz,ny,nx});
            }
        }
    }
    return -1;
}

int main()
{
    while(true){
        //reset visit array
        cin >> l >> r >> c;
        if(!l && !r && !c)  break; // 셋 다 0 0 0 인 경우에 테스트가 끝난다.
        for(int i = 0 ; i < l ; i++){
            for(int j = 0 ; j < r ; j++){
                for(int k = 0 ; k < c ; k++){
                    visit[i][j][k] = -1;
                }
            }
        }

        for(int i = 0 ; i < l ; i++){
            for(int j = 0 ; j < r ; j++){
                for(int k = 0 ; k < c ; k++){
                    cin >> map[i][j][k];
                    if(map[i][j][k] == 'S'){
                        start = {i,j,k};
                        visit[i][j][k] = 0;
                    }
                    else if(map[i][j][k] == 'E')    buildingexit = {i,j,k};
                }
            }
        }
        //bfs
        int count = BFS();
        
        if(count == -1) cout << "Trapped!\n";
        else    cout << "Escaped in " << count << " minute(s).\n";
    }

    return 0;
}